#include "stdafx.h"
#include "Visualizer.h"
#include "OpenGLWindow.h"
#include "BezierCurve.h"
#include "Hermite.h"
#include "BSpline.h"
#include "Line.h"
#include "Bresenhams.h"
#include "SimpleDDA.h"
Visualizer::Visualizer(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi();
    connect(pushButton, &QPushButton::clicked, this, &Visualizer::addPoints);
    connect(pushButton_2, &QPushButton::clicked, this, &Visualizer::bezierCurve);
    connect(pushButton_3, &QPushButton::clicked, this, &Visualizer::hermiteCurve);
    connect(pushButton_4, &QPushButton::clicked, this, &Visualizer::bresenham);
    connect(pushButton_5, &QPushButton::clicked, this, &Visualizer::simpleDDA);
    connect(pushButton_6, &QPushButton::clicked, this, &Visualizer::bsplineCurve);
    connect(mRenderer, SIGNAL(shapeUpdate()), mRenderer, SLOT(update()));
}

Visualizer::~Visualizer()
{}
void Visualizer::setupUi() {
    resize(600, 500);
    centralWidget = new QWidget(this);
    centralWidget->setObjectName("centralWidget");
    doubleSpinBox = new QDoubleSpinBox(centralWidget);
    doubleSpinBox->setObjectName("doubleSpinBox");
    doubleSpinBox->setMinimum(-100.000000000000000);
    doubleSpinBox->setMaximum(100.000000000000000);
    doubleSpinBox->setGeometry(QRect(300, 60, 62, 22));
    doubleSpinBox_2 = new QDoubleSpinBox(centralWidget);
    doubleSpinBox_2->setObjectName("doubleSpinBox_2");
    doubleSpinBox_2->setMinimum(-100.000000000000000);
    doubleSpinBox_2->setMaximum(100.000000000000000);
    doubleSpinBox_2->setGeometry(QRect(370, 60, 62, 22));
    doubleSpinBox_3 = new QDoubleSpinBox(centralWidget);
    doubleSpinBox_3->setObjectName("doubleSpinBox_3");
    doubleSpinBox_3->setMinimum(-100.000000000000000);
    doubleSpinBox_3->setMaximum(100.000000000000000);
    doubleSpinBox_3->setGeometry(QRect(440, 60, 62, 22));
   
    
    pushButton = new QPushButton(centralWidget);
    pushButton->setObjectName("pushButton");
    pushButton->setGeometry(QRect(510, 60, 75, 24));
    pushButton->setText("ADD");
    pushButton_2 = new QPushButton(centralWidget);
    pushButton_2->setObjectName("pushButton_2");
    pushButton_2->setGeometry(QRect(320, 120, 91, 24));
    pushButton_2->setText("Bezier Curve");
    pushButton_3 = new QPushButton(centralWidget);
    pushButton_3->setObjectName("pushButton_3");
    pushButton_3->setGeometry(QRect(430, 120, 91, 24));
    pushButton_3->setText("Hermite Curve");
    pushButton_4 = new QPushButton(centralWidget);
    pushButton_4->setObjectName("pushButton_4");
    pushButton_4->setText("Bresenham");
    pushButton_4->setGeometry(QRect(300, 170, 81, 24));
    pushButton_5 = new QPushButton(centralWidget);
    pushButton_5->setObjectName("pushButton_5");
    pushButton_5->setText("Simple DDA");
    pushButton_5->setGeometry(QRect(390, 170, 81, 24));
    pushButton_6 = new QPushButton(centralWidget);
    pushButton_6->setObjectName("pushButton_6");
    pushButton_6->setGeometry(QRect(480, 170, 81, 24));
    pushButton_6->setText("BSpline");

    listWidget = new QListWidget(centralWidget);
    listWidget->setObjectName("listWidget");
    listWidget->setGeometry(QRect(30, 60, 256, 131));

    label = new QLabel(centralWidget);
    label->setObjectName("label");
    label->setGeometry(QRect(50, 30, 111, 16));
    label->setText("Input Data");
    label_2 = new QLabel(centralWidget);
    label_2->setObjectName("label_2");
    label_2->setGeometry(QRect(300, 30, 49, 16));
    label_2->setText("X - Value");
    label_3 = new QLabel(centralWidget);
    label_3->setObjectName("label_3");
    label_3->setGeometry(QRect(370, 30, 49, 16));
    label_3->setText("Y - Value");
    label_4 = new QLabel(centralWidget);
    label_4->setObjectName("label_4");
    label_4->setGeometry(QRect(440, 30, 49, 16));
    label_4->setText("Z - Value");

    
    mRenderer = new OpenGLWindow(QColor(0, 0, 0), this);
    mRenderer->setGeometry(QRect(30, 210, 531, 200));

    setCentralWidget(centralWidget);
    menuBar = new QMenuBar(this);
    menuBar->setObjectName("menuBar");
    menuBar->setGeometry(QRect(0, 0, 458, 22));
    setMenuBar(menuBar);
    mainToolBar = new QToolBar(this);
    mainToolBar->setObjectName("mainToolBar");
    addToolBar(Qt::TopToolBarArea, mainToolBar);
    statusBar = new QStatusBar(this);
    statusBar->setObjectName("statusBar");
    setStatusBar(statusBar);
}
void  Visualizer::addPoints() {
    double xValue = doubleSpinBox->value();
    double yValue = doubleSpinBox_2->value();
    double zValue = doubleSpinBox_3->value();
    QString itemText = QString("%1, %2, %3").arg(xValue).arg(yValue).arg(zValue);
    Point3D p(xValue, yValue,zValue);
    mPoints.push_back(p);
    QListWidgetItem* newItem = new QListWidgetItem(itemText);
    listWidget->addItem(newItem);
    mVertices.clear();
    
}
void Visualizer::bezierCurve() {
    mVertices.empty();
    mColors.empty();
    BezierCurve bezicurve(mPoints[0], mPoints[1], mPoints[2], mPoints[3]);
    mVertices << mPoints[0].getX() << mPoints[0].getY() << mPoints[0].getZ();
    mColors << 0.0f << 1.0f << 0.0f;
    bezicurve.drawCurve(mPoints[0], mPoints[1], mPoints[2], mPoints[3], mcurvePoint, mcurveColor);
    for (int i = 0; i < mcurvePoint.size(); i += 3)
    {
        mVertices << mcurvePoint[i] << mcurvePoint[i + 1] << mcurvePoint[i + 2];
    }
    for (int i = 0; i < mcurveColor.size(); i += 3)
    {
        mColors << mcurveColor[i] << mcurveColor[i + 1] << mcurveColor[i + 2];
    }
    mVertices << mPoints[3].getX() << mPoints[3].getY() << mPoints[3].getZ();
    mColors << 1.0f << 1.0f << 0.0f;
    mRenderer->updateData(mVertices, mColors,1);
    mVertices.empty();
    mColors.empty();
    mPoints.clear();
    mcurvePoint.clear();
    mcurveColor.clear();
    listWidget->clear();
}
void Visualizer::simpleDDA() {
    mVertices.empty();
    mColors.empty();
    Line l(mPoints[0], mPoints[1]);
    mVertices << mPoints[0].getX() << mPoints[0].getY() << mPoints[0].getZ();
    mVertices << mPoints[1].getX() << mPoints[1].getY() << mPoints[1].getZ();

    mColors << 0.0f << 1.0f << 0.0f;
    mColors << 0.0f << 1.0f << 0.0f;
    SimpleDDA sim(l,mcurvePoint, mcurveColor);
    sim.drawGrid(mcurvePoint, mcurveColor);
    for (int i = 0; i < mcurvePoint.size()+3; i += 3)
    {
        mVertices << mcurvePoint[i] << mcurvePoint[i + 1]<<mcurvePoint[i+2];
    }
    for (int i = 0; i < mcurveColor.size()+3; i += 3)
    {
        mColors << mcurveColor[i] << mcurveColor[i + 1] << mcurveColor[i + 2];
    }
    
    mRenderer->updateData(mVertices, mColors,1);
    mVertices.clear();
    mColors.clear();
    mcurveColor.clear();
    mcurvePoint.clear();
}
void Visualizer::hermiteCurve() {
   
    mVertices.empty();
    mColors.empty();
    Hermite hermitecurve(mPoints[0], mPoints[1], mPoints[2], mPoints[3]);
    mVertices << mPoints[0].getX() << mPoints[0].getY() << mPoints[0].getZ();
    mColors << 1.0f << 1.0f << 0.0f;
    hermitecurve.drawCurve(mPoints[0], mPoints[1], mPoints[2], mPoints[3], mcurvePoint, mcurveColor);
    for (int i = 0; i < mcurvePoint.size(); i += 3)
    {
        mVertices << mcurvePoint[i] << mcurvePoint[i + 1] << mcurvePoint[i + 2];
    }
    for (int i = 0; i < mcurveColor.size(); i += 3)
    {
        mColors << mcurveColor[i] << mcurveColor[i + 1] << mcurveColor[i + 2];
    }
    mVertices << mPoints[3].getX() << mPoints[3].getY() << mPoints[3].getZ();
    mColors << 1.0f << 1.0f << 0.0f;
    mRenderer->updateData(mVertices, mColors, 1);
    mVertices.empty();
    mColors.empty();
    mcurvePoint.clear();
    mcurveColor.clear();
    listWidget->clear();
}
void Visualizer::bresenham() {
    mVertices.clear();
    mColors.clear();
    Line l(mPoints[0], mPoints[1]);
    Bresenhams bre(l,mcurvePoint);
    for (int i = 0; i < mcurvePoint.size(); i+=3) {
        mVertices<<mcurvePoint[i]<< mcurvePoint[i+1]<< mcurvePoint[i+2];
        mColors << 1.0f<<1.0f<<0.0f;
    }
    mRenderer->updateData(mVertices, mColors, 0);
    mVertices.clear();
    mColors.clear();
    mPoints.clear();
    mcurvePoint.clear();
    mcurveColor.clear();
    listWidget->clear();
}
void Visualizer::bsplineCurve() {
    BSpline bspline(3);
    mCurvePoints=bspline.evaluate(mPoints, 100);
   for (int i = 0; i < mCurvePoints.size(); i++) {
        mVertices << mCurvePoints[i].getX() << mCurvePoints[i].getY() << mCurvePoints[i].getZ();
        mColors << 01.0f << 0.0f << 1.0f;
    }
    mRenderer->updateData(mVertices, mColors,0);
    mVertices.clear();
    mColors.clear();
    mPoints.clear();
    mCurvePoints.clear();
    listWidget->clear();
}
