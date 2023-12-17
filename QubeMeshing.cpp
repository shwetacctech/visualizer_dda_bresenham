#include "stdafx.h"
#include "QubeMeshing.h"
#include "OpenGLWindow.h"
#include "BezierCurve.h"
#include "HermiteCurve.h"
#include "BSpline.h"
QubeMeshing::QubeMeshing(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi();
    connect(pushButton, &QPushButton::clicked, this, &QubeMeshing::addPoints);
    connect(pushButton_2, &QPushButton::clicked, this, &QubeMeshing::bezierCurve);
    connect(pushButton_3, &QPushButton::clicked, this, &QubeMeshing::hermiteCurve);
    connect(mRenderer, SIGNAL(shapeUpdate()), mRenderer, SLOT(update()));
}

QubeMeshing::~QubeMeshing()
{}
void QubeMeshing::setupUi() {
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
void  QubeMeshing::addPoints() {
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
void QubeMeshing::bezierCurve() {
    BezierCurve bezicurve;
    mcurvePoint=bezicurve.generateCubicBezierCurve(mPoints[0], mPoints[1], mPoints[2], mPoints[3], 200);
    for (int i = 0; i < mcurvePoint.size(); i++) {
        mVertices << mcurvePoint[i].getX() << mcurvePoint[i].getY() << mcurvePoint[i].getZ();
        mColors << 1.0f << 0.0f << 1.0f;
        mColors << 1.0f << 0.0f << 1.0f;

    }
    mRenderer->setVectorOfLines(mVertices);
    mRenderer->setColorOfLines(mColors);
    mRenderer->updateData(mVertices, mColors);
    mVertices.clear();
    mColors.clear();
}

void QubeMeshing::hermiteCurve() {

    HermiteCurve hmcurve;
    mcurvePoint = hmcurve.generateHermiteCurve(mPoints[0], mPoints[1], mPoints[2], mPoints[3], 100);
    for (int i = 0; i < mcurvePoint.size(); i++) {
        mVertices << mcurvePoint[i].getX() << mcurvePoint[i].getY() << mcurvePoint[i].getZ();
        mColors << 01.0f << 0.0f << 1.0f;
        mColors << 1.0f << 0.0f << 01.0f;

    }
    mRenderer->setVectorOfLines(mVertices);
    mRenderer->setColorOfLines(mColors);
    mRenderer->updateData(mVertices, mColors);
    mVertices.clear();
    mColors.clear();
}

void QubeMeshing::bsplineCurve() {
    BSpline bspline;
    mcurvePoint=bspline.generateBSpline(mPoints, 3);
    for (int i = 0; i < mcurvePoint.size(); i++) {
        mVertices << mcurvePoint[i].getX() << mcurvePoint[i].getY() << mcurvePoint[i].getZ();
        mColors << 01.0f << 0.0f << 1.0f;
        mColors << 1.0f << 0.0f << 01.0f;

    }
    mRenderer->setVectorOfLines(mVertices);
    mRenderer->setColorOfLines(mColors);
    mRenderer->updateData(mVertices, mColors);
    mVertices.clear();
    mColors.clear();
}