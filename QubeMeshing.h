#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QubeMeshing.h" 
#include "Point3D.h"
#include "OpenGLWindow.h"

class QubeMeshing : public QMainWindow
{
    Q_OBJECT

public:
    QubeMeshing(QWidget *parent = nullptr);
    ~QubeMeshing();
    void setupUi();
public slots:
    void addPoints();
    void bezierCurve();
    void hermiteCurve();
    void bsplineCurve();
private:
    //Ui::QubeMeshingClass ui;
   QWidget* centralWidget;
    QDoubleSpinBox* doubleSpinBox;
    QDoubleSpinBox* doubleSpinBox_2;
    QDoubleSpinBox* doubleSpinBox_3;
    QPushButton* pushButton;
    QPushButton* pushButton_2;
    QPushButton* pushButton_3;
    QListWidget* listWidget;
    QOpenGLWidget* openGLWidget;
    QMenuBar* menuBar;
    QToolBar* mainToolBar;
    QStatusBar* statusBar;
    QLabel* label;
    QLabel* label_2;
    QLabel* label_3;
    QLabel* label_4;
    std::vector< Point3D> mPoints;
    QVector<GLfloat> mVertices;
    QVector<GLfloat> mColors;
    OpenGLWindow* mRenderer;
    QVector<Point3D> mcurvePoint;
};

