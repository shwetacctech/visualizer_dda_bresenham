#pragma once
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include "Line.h"

class QOpenGLTexture;
class QOpenGLShader;
class QOpenGLShaderProgram;
class QOpenGLPaintDevice;

class OpenGLWindow :public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    OpenGLWindow(const QColor& background, QMainWindow* parent);
    ~OpenGLWindow();

public:
    QVector<GLfloat> vertices;
    QVector<GLfloat> colors;
    void addLine(Line l);
    void fillSquare(const QVector<QVector2D>& squareVertices, const QVector3D& fillColor);
    void colorSqr(QVector<QVector2D>& pixels);
    void addGrid(float size,float step);
    void bresenhams(Line l);
    void simpleDDA(Line l);
signals:
    void update_state();
protected:
    void paintGL() override;
    void initializeGL() override;
private:
   
    void reset();
    
private:
    bool mAnimating = false;
    QOpenGLContext* mContext = nullptr;
    QOpenGLPaintDevice* mDevice = nullptr;

    QOpenGLShader* mVshader = nullptr;
    QOpenGLShader* mFshader = nullptr;
    QOpenGLShaderProgram* mProgram = nullptr;
    QVector<QVector2D> mPixelVertices;
    QList<QVector2D> mVertices;
    QList<QVector2D> mNormals;

    QOpenGLBuffer mVbo;
    int mVertexAttr;
    int mNormalAttr;
    int mMatrixUniform;
    QColor mBackground;
    QMetaObject::Connection mContextWatchConnection;

    
    GLint m_posAttr = 0;
    GLint m_colAttr = 0;
    GLint m_matrixUniform = 0;
    float mFloatInputs[4];
    //Line *mLine;
    float gridSize;
    float gridStep;
   // QInputDialog* mInputBox;

};
