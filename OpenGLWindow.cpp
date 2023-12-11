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
    setMinimumSize(500, 250);
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
    matrix.ortho(-16.0f, 16.0f, -16.0f, 16.0f, 0.1f, 100.0f);  
    matrix.translate(0, 0, -2);

    mProgram->setUniformValue(m_matrixUniform, matrix);

    QVector<GLfloat> vertices; //vector for vertices storing vertices value
    QVector<GLfloat> colors; //vector for colors

    // Draw the grid
    drawGrid(vertices, colors);
    // using vertices
    vertices << -3.75 << -3.75;
    vertices << 4.5 << 2.5;
    //coloring them into black
    colors << 1.0f << 0.0f << 0.0f;//line coloring into red
    colors << 1.0f << 0.0f << 0.0f;
    QVector<QVector2D> squareVertices; //empty vector for storing points to be colored inside grid or square
  bresenhamLinePixels(-3.75, -3.75, 4.5, 2.5, squareVertices); //calling function of bresenhams 
  //ddaLinePixels(-3.75, -3.75, 4.5, 2.5, squareVertices); //calling function of ddalinepixels
    
    int i = 0;
    while (i < squareVertices.size()) {
        QVector<QVector2D> qv;
        qv.append(squareVertices[i]); //first vertice of square
        i++;
        qv.append(squareVertices[i]);//second vertice of square
        i++;
        qv.append(squareVertices[i]);//third vertice of square
        i++;
        qv.append(squareVertices[i]);//fourth vertice of square
        i++;
        QVector3D fillColor(1.0f, 1.0f, 1.0f);  //coloring the pixel formed squared which contains line
        fillSquare(qv, fillColor);  
    }
    // Prepare the data for rendering
    GLfloat* verticesData = vertices.data();
    GLfloat* colorsData = colors.data();

    glVertexAttribPointer(m_posAttr, 2, GL_FLOAT, GL_FALSE, 0, verticesData);
    glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, colorsData);

    glEnableVertexAttribArray(m_posAttr);
    glEnableVertexAttribArray(m_colAttr);

    glDrawArrays(GL_LINES, 0, vertices.size() / 2);

    glDisableVertexAttribArray(m_colAttr);
    glDisableVertexAttribArray(m_posAttr);
}

void OpenGLWindow::drawGrid(QVector<GLfloat>& vertices, QVector<GLfloat>& colors)
{
    const float gridSize = 16.0f;  // Adjust the grid size as needed
    const float step = 1.0f;

    // Draw horizontal grid lines
    for (float y = -gridSize / 2.0f; y <= gridSize / 2.0f; y += step)
    {
        vertices << -gridSize / 2.0f << y;
        vertices << gridSize / 2.0f << y;
        //coloring horizontal lines of grid
        colors << 1.0f << 1.0f << 1.0f; 
        colors << 1.0f << 1.0f << 1.0f;
    }

    // Draw vertical grid lines
    for (float x = -gridSize / 2.0f; x <= gridSize / 2.0f; x += step)
    {
        vertices << x << -gridSize / 2.0f;
        vertices << x << gridSize / 2.0f;
        //coloring vertical grid lines
        colors << 1.0f << 1.0f << 1.0f;
        colors << 1.0f << 1.0f << 1.0f;
    }
}

// coloring the squares in which line occurs

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

//logic for simple dda 
void OpenGLWindow::ddaLinePixels(float x1, float y1, float x2, float y2, QVector<QVector2D>& pixelVertices) {

    float dx = abs(x2 - x1); //x difference
    float dy = abs(y2 - y1); //y difference

    float steps = dx > dy ? dx : dy;

    float deltax = dx / steps; //increment or deltax divide by the xdifference
    float deltay = dy / steps; //increment or deltay divide by the ydifference

    for (int i = 0; i < steps; i++) {
        pixelVertices.append(QVector2D(round(x1), round(y1))); //adding the vertice of square left bottom
        pixelVertices.append(QVector2D(round(x1) + 1, round(y1))); //adding the vertice of square right bottom
        pixelVertices.append(QVector2D(round(x1) + 1, round(y1) + 1));//adding the vertice of square rigth top
        pixelVertices.append(QVector2D(round(x1), round(y1) + 1));//adding the vertice of square left top

        x1 += deltax; //incrementing x1 by the deltax
        y1 += deltay; //incrementing y1 by deltay
    }

    
}
//logic for bresenhams line drawing
void OpenGLWindow::bresenhamLinePixels(float x1, float y1, float x2, float y2, QVector<QVector2D>& pixelVertices)
{
    float dx = abs(x2 - x1);
    float dy = abs(y2 - y1);
    float sx = (x1 < x2) ? 0.5f : -0.5f;
    float sy = (y1 < y2) ? 0.5f : -0.5f;
    float err = dx - dy;

    while (x1 <= x2 || y1 <= y2) {
        pixelVertices.append(QVector2D(round(x1), round(y1)));//adding the vertice of square left bottom
        pixelVertices.append(QVector2D(round(x1) + 1, round(y1)));//adding the vertice of square right bottom
        pixelVertices.append(QVector2D(round(x1) + 1, round(y1) + 1));//adding the vertice of square rigth top
        pixelVertices.append(QVector2D(round(x1), round(y1) + 1));//adding the vertice of square left top

        float e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy; //decrementing error by dy
            x1 += sx;
            x1 = round(x1);
        }
        if (e2 < dx) {
            err += dx; //incrementing err by dx
            y1 += sy;   
            y1 = round(y1);
        }
    }
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

void OpenGLWindow::createGeometry()
{
   
}