#include "stdafx.h"
#include "OpenGLWindow.h"
#include <QOpenGLContext>
#include <QOpenGLPaintDevice>
#include <QOpenGLShaderProgram>
#include <QPainter>

OpenGLWindow::OpenGLWindow(const QColor& background, QMainWindow* parent) :
    mBackground(background)
{
    setParent(parent);
    setMinimumSize(550, 450);
}

OpenGLWindow::~OpenGLWindow()
{
    reset();
}

void OpenGLWindow::reset()
{
    // And now release all OpenGL resources.
    makeCurrent();
    delete mProgram;
    mProgram = nullptr;
    delete mVshader;
    mVshader = nullptr;
    delete mFshader;
    mFshader = nullptr;
    mVbo.destroy();
    doneCurrent();
    QObject::disconnect(mContextWatchConnection);
}


void OpenGLWindow::setVectorOfLines(QVector<GLfloat>& vectorOfLines)
{
    verticesOfOrignalLine = vectorOfLines;
}

void OpenGLWindow::setColorOfLines(QVector<GLfloat>& colorOfLines)
{
    colorOfOrignalLine = colorOfLines;
}

// Code to fill the pixel with color
void OpenGLWindow::fillSquare(const QVector<QVector2D>& squareVertices, const QVector3D& fillColor)
{
    QVector<GLfloat> vertices;
    QVector<GLfloat> colors;

    for (const auto& vertex : squareVertices)
    {
        vertices << vertex.x();
        vertices << vertex.y();
        colors << fillColor.x() << fillColor.y() << fillColor.z();
    }

}


void OpenGLWindow::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);

    mProgram->bind();

    QMatrix4x4 matrix;
    matrix.ortho(-2.0f*2, 2.0f*2, -2.0f*2, 2.0f*2, 0.1f, 100.0f);
    matrix.translate(0, 0, -2);

    mProgram->setUniformValue(m_matrixUniform, matrix);

    GLfloat* verticesData = verticesOfOrignalLine.data();
    GLfloat* colorsData = colorOfOrignalLine.data();

        if (mFlag == 1)

        {

            glVertexAttribPointer(m_posAttr, 3, GL_FLOAT, GL_FALSE, 0, verticesData);

            glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, colorsData);

            glEnableVertexAttribArray(m_posAttr);

            glEnableVertexAttribArray(m_colAttr);

            glDrawArrays(GL_LINES, 0, verticesOfOrignalLine.size() / 3);

        }
        else
        {
            glVertexAttribPointer(m_posAttr, 3, GL_FLOAT, GL_FALSE, 0, verticesData);
            glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, colorsData);

            glEnableVertexAttribArray(m_posAttr);
            glEnableVertexAttribArray(m_colAttr);

            glDrawArrays(GL_LINE_LOOP, 0, verticesOfOrignalLine.size() / 3);
        }
        
}

void OpenGLWindow::updateData(const QVector<GLfloat>& vertices, const QVector<GLfloat>& colors,int flag=0)
{
    verticesOfOrignalLine = vertices;
    colorOfOrignalLine = colors;
    mFlag = flag;
    update();  // Schedule a repaint
}


void OpenGLWindow::initializeGL()
{
    static const char* vertexShaderSource =
        "attribute highp vec4 posAttr;\n"
        "attribute lowp vec4 colAttr;\n"
        "varying lowp vec4 col;\n"
        "uniform highp mat4 matrix;\n"
        "void main() {\n"
        "   col = colAttr;\n"
        "   gl_Position = matrix * posAttr;\n"
        "}\n";

    static const char* fragmentShaderSource =
        "varying lowp vec4 col;\n"
        "void main() {\n"
        "   gl_FragColor = col;\n"
        "}\n";

    initializeOpenGLFunctions();

    mProgram = new QOpenGLShaderProgram(this);
    mProgram->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
    mProgram->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
    mProgram->link();
    m_posAttr = mProgram->attributeLocation("posAttr");
    Q_ASSERT(m_posAttr != -1);
    m_colAttr = mProgram->attributeLocation("colAttr");
    Q_ASSERT(m_colAttr != -1);
    m_matrixUniform = mProgram->uniformLocation("matrix");
    Q_ASSERT(m_matrixUniform != -1);
}


