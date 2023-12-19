#pragma once
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLBuffer>

class QOpenGLTexture;
class QOpenGLShader;
class QOpenGLShaderProgram;
class QOpenGLPaintDevice;

class OpenGLWindow :public QOpenGLWidget, protected QOpenGLFunctions{
        Q_OBJECT
    public:
        OpenGLWindow(const QColor& background, QMainWindow* parent);
        ~OpenGLWindow();

        void setVectorOfLines(QVector<GLfloat>& vectorOfLines);
        void setColorOfLines(QVector<GLfloat>& colorOfLines);
        void updateData(const QVector<GLfloat>& vertices, const QVector<GLfloat>& colors, int flag);
        void fillSquare(const QVector<QVector2D>& squareVertices, const QVector3D& fillColor);

    protected:
        void paintGL() override;
        void initializeGL() override;

    private:
        void reset();

    private:
        bool mAnimating = false;
        int mFlag = 0;
        QOpenGLContext* mContext = nullptr;
        QOpenGLPaintDevice* mDevice = nullptr;

        QOpenGLShader* mVshader = nullptr;
        QOpenGLShader* mFshader = nullptr;
        QOpenGLShaderProgram* mProgram = nullptr;

        QList<QVector3D> mVertices;
        QList<QVector3D> mNormals;
        QOpenGLBuffer mVbo;
        int mVertexAttr;
        int mNormalAttr;
        int mMatrixUniform;
        QColor mBackground;
        QMetaObject::Connection mContextWatchConnection;


        QVector<GLfloat> verticesOfOrignalLine;
        QVector<GLfloat> colorOfOrignalLine;

        GLint m_posAttr = 0;
        GLint m_colAttr = 0;
        GLint m_posAttr1 = 0;
        GLint m_colAttr1 = 0;
        GLint m_matrixUniform = 0;
};


