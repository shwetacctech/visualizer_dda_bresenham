#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_Visualizer.h" 
#include "Point3D.h"
#include "OpenGLWindow.h"

class Visualizer : public QMainWindow
{
    Q_OBJECT

public:
    Visualizer(QWidget *parent = nullptr);
    ~Visualizer();
    void setupUi();
public slots:
    void addPoints();
    void bresenham();
    void bezierCurve();
    void hermiteCurve();
    void bsplineCurve();
    void simpleDDA();
private:
   Ui::VisualizerClass ui;
   QWidget* centralWidget;
    QDoubleSpinBox* doubleSpinBox;
    QDoubleSpinBox* doubleSpinBox_2;
    QDoubleSpinBox* doubleSpinBox_3;
    QPushButton* pushButton;
    QPushButton* pushButton_2;
    QPushButton* pushButton_3;
    QPushButton* pushButton_4;
    QPushButton* pushButton_5;
    QPushButton* pushButton_6;
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
    std::vector< Point3D> mCurvePoints;
    QVector<GLfloat> mVertices;
    QVector<GLfloat> mColors;
    OpenGLWindow* mRenderer;

    std::vector<float> mcurvePoint;
    std::vector<float> mcurveColor;

};

