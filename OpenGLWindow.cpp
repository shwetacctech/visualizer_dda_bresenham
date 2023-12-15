/**#include "stdafx.h"
#include "OpenGLWindow.h"
#include <QOpenGLContext>
#include <QOpenGLPaintDevice>
#include <QOpenGLShaderProgram>
#include "SimpleDDA.h"
#include "Grid.h"
#include "Bresenhams.h"

OpenGLWindow::OpenGLWindow(const QColor& background, QMainWindow* parent) : 
    mBackground(background)
{
    setParent(parent);
    setMinimumSize(720, 550);
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

    // We are done with the current QOpenGLContext, forget it. If there is a
    // subsequent initialize(), that will then connect to the new context.
    QObject::disconnect(mContextWatchConnection);
}



void OpenGLWindow::paintGL()
{
    
    glClear(GL_COLOR_BUFFER_BIT);

    mProgram->bind();

    QMatrix4x4 matrix;
    matrix.ortho(-3.0f-(gridSize/2), 3.0f+(gridSize/2), -3.0f- (gridSize / 2), 3.0f+ (gridSize / 2), 0.1f, 100.0f);  // Adjust the orthographic projection
    matrix.translate(0, 0, -2);

    mProgram->setUniformValue(m_matrixUniform, matrix);
   
  
    colorSqr(mPixelVertices);
    Grid grid;
    grid.drawGrid(gridSize, gridStep,vertices, colors);
    
   
    
    // Prepare the data for rendering
    GLfloat* verticesData = vertices.data();
    GLfloat* colorsData = colors.data();

    glVertexAttribPointer(m_posAttr, 2, GL_FLOAT, GL_FALSE, 0, verticesData);
    glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, colorsData);

    glEnableVertexAttribArray(m_posAttr);
    glEnableVertexAttribArray(m_colAttr);

    glDrawArrays(GL_LINES, 0, vertices.size()/2);

    glDisableVertexAttribArray(m_colAttr);
    glDisableVertexAttribArray(m_posAttr);
}

void OpenGLWindow::colorSqr(QVector<QVector2D>& pixels) {
    int i = 0;
    while (i < pixels.size()) {
        QVector<QVector2D> qv;
        qv.append(pixels[i]);
        i++;
        qv.append(pixels[i]);
        i++;
        qv.append(pixels[i]);
        i++;
        qv.append(pixels[i]);
        i++;
        QVector3D fillColor(1.0f, 0.0f, 1.0f);
        fillSquare(qv, fillColor);
    }
}
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

    // Prepare the data for rendering
    GLfloat* verticesData = vertices.data();
    GLfloat* colorsData = colors.data();

    glVertexAttribPointer(m_posAttr, 2, GL_FLOAT, GL_FALSE, 0, verticesData);
    glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, colorsData);

    glEnableVertexAttribArray(m_posAttr);
    glEnableVertexAttribArray(m_colAttr);

    glDrawArrays(GL_TRIANGLE_FAN, 0, vertices.size() / 2);

    glDisableVertexAttribArray(m_colAttr);
    glDisableVertexAttribArray(m_posAttr);
}


void OpenGLWindow::addLine(Line l) {
    vertices<<l.getP1().x() << l.getP1().y();
    vertices<<l.getP2().x() << l.getP2().y();
    
    colors << 1.0f << 0.0f << 0.0f;
    colors << 1.0f << 0.0f << 0.0f;
   
    emit update_state();
}


void OpenGLWindow::addGrid(float size,float step) {
    Grid g;
    g.drawGrid(size, step, vertices, colors);
    gridSize = size;
    gridStep = step;
    emit update_state();
}

void OpenGLWindow::simpleDDA(Line l) {
    mPixelVertices.clear();
    SimpleDDA simpleDDALine;
    simpleDDALine.drawLineBySimpleDDA(l, mPixelVertices);
    colorSqr(mPixelVertices);
    emit update_state();
}

void OpenGLWindow::bresenhams(Line l) {
    mPixelVertices.clear();
    Bresenhams bresenhamsLine;
    bresenhamsLine.drawLineByBresenhams(l, mPixelVertices);
    colorSqr(mPixelVertices);
    emit update_state();
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

}*/
#include "stdafx.h"
#include "OpenGLWindow.h"
#include <QOpenGLContext>
#include <QOpenGLPaintDevice>
#include <QOpenGLShaderProgram>
#include <QPainter>
#include "Grid.h"
#include "Bresenhams.h"
#include "SimpleDDA.h"


OpenGLWindow::OpenGLWindow(const QColor& background, QMainWindow* parent) :
    mBackground(background)
{
    setParent(parent);
    setMinimumSize(720, 550);
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

void OpenGLWindow::paintGL()
{


    glClear(GL_COLOR_BUFFER_BIT);

    mProgram->bind();

    QMatrix4x4 matrix;
    matrix.ortho(-3.0f - (gridSize / 2), 3.0f + (gridSize / 2), -3.0f - (gridSize / 2), 3.0f + (gridSize / 2), 0.1f, 100.0f);
    matrix.translate(0, 0, -2);

    mProgram->setUniformValue(m_matrixUniform, matrix);

    Grid grid;
    grid.drawGrid(gridSize,gridStep,vertices, colors);
    colorSqr(mPixelVertices);

    glVertexAttribPointer(m_posAttr, 2, GL_FLOAT, GL_FALSE, 0, vertices.data());
    glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, colors.data());

    glEnableVertexAttribArray(m_posAttr);
    glEnableVertexAttribArray(m_colAttr);

    glDrawArrays(GL_LINES, 0, vertices.size() / 2);

    glDisableVertexAttribArray(m_colAttr);
    glDisableVertexAttribArray(m_posAttr);
}

void OpenGLWindow::colorSqr(QVector<QVector2D>& pixels)
{
    int i = 0;
    while (i < pixels.size()) {
        QVector<QVector2D> qv;
        qv.append(pixels[i]);
        i++;
        qv.append(pixels[i]);
        i++;
        qv.append(pixels[i]);
        i++;
        qv.append(pixels[i]);
        i++;
        QVector3D fillColor(1.0f, 0.0f, 1.0f);
        fillSquare(qv, fillColor);
    }
}
void OpenGLWindow::fillSquare(const QVector<QVector2D>& squareVertices, const QVector3D& fillColor)
{

    QVector<GLfloat> vertices;
    QVector<GLfloat> colors;

    // Convert QVector<QVector2D> to QVector<GLfloat>
    for (const auto& vertex : squareVertices)
    {
        vertices << vertex.x();
        vertices << vertex.y();
        colors << fillColor.x() << fillColor.y() << fillColor.z();
    }

    // Prepare the data for rendering
    GLfloat* verticesData = vertices.data();
    GLfloat* colorsData = colors.data();

    glVertexAttribPointer(m_posAttr, 2, GL_FLOAT, GL_FALSE, 0, verticesData);
    glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, colorsData);

    glEnableVertexAttribArray(m_posAttr);
    glEnableVertexAttribArray(m_colAttr);

    glDrawArrays(GL_TRIANGLE_FAN, 0, vertices.size() / 2);

    glDisableVertexAttribArray(m_colAttr);
    glDisableVertexAttribArray(m_posAttr);
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

void OpenGLWindow::addLine(Line l)
{
    vertices.push_back(l.getP1().x());
    vertices.push_back(l.getP1().y());
    vertices.push_back(l.getP2().x());
    vertices.push_back(l.getP2().y());

    colors << 1.0f << 0.0f << 0.0f;
    colors << 1.0f << 0.0f << 0.0f;

    emit update_state();
}

void OpenGLWindow::addGrid(float size,float step)
{
    gridSize = size;
    gridStep = step;
    emit update_state();
}

void OpenGLWindow::bresenhams(Line l)
{
    mPixelVertices.clear();
    Bresenhams b;
    b.drawLineByBresenhams(l, mPixelVertices);
    colorSqr(mPixelVertices);
    emit update_state();
}

void OpenGLWindow::simpleDDA(Line l)
{
    mPixelVertices.clear();
    SimpleDDA s;
    s.drawLineBySimpleDDA(l, mPixelVertices);
    colorSqr(mPixelVertices);
    emit update_state();
}

