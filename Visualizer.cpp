#include "stdafx.h"
#include "Visualizer.h"
#include "OpenGLWindow.h"

Visualizer::Visualizer(QWindow* parent) : QMainWindow(nullptr)
{
    setupUi();
    connect(pushButton_5, &QPushButton::clicked, this, &Visualizer::addLines);
    connect(pushButton_2, &QPushButton::clicked, this, &Visualizer::addGrids);
    connect(pushButton_3, &QPushButton::clicked, this, &Visualizer::bresenhams);
    connect(pushButton_4, &QPushButton::clicked, this, &Visualizer::simpleDDA);
    connect(mRenderer, SIGNAL(update_state()), mRenderer, SLOT(update()));
}

Visualizer::~Visualizer()
{}

void Visualizer::setupUi() {
    resize(900, 700);
    mMenuBar = new QMenuBar(this);
    mMenuBar->setObjectName("menuBar");
    setMenuBar(mMenuBar);
    mMainToolBar = new QToolBar(this);
    mMainToolBar->setObjectName("mainToolBar");
    addToolBar(mMainToolBar);
    mStatusBar = new QStatusBar(this);
    mStatusBar->setObjectName("statusBar");
    setStatusBar(mStatusBar);
    mLineEdit = new QLineEdit(this);
    mLineEdit->setObjectName("lineEdit");
    mLineEdit->setGeometry(QRect(20, 30, 113, 21));
    mLineEdit1 = new QLineEdit(this);
    mLineEdit1->setObjectName("lineEdit_2");
    mLineEdit1->setGeometry(QRect(20, 70, 113, 21));
    mLineEdit2 = new QLineEdit(this);
    mLineEdit2->setObjectName("lineEdit_3");
    mLineEdit2->setGeometry(QRect(240, 30, 81, 21));
    mLineEdit3 = new QLineEdit(this);
    mLineEdit3->setObjectName("lineEdit_4");
    mLineEdit3->setGeometry(QRect(340, 30, 81, 21));
    mLineEdit4 = new QLineEdit(this);
    mLineEdit4->setObjectName("lineEdit_5");
    mLineEdit4->setGeometry(QRect(440, 30, 81, 21));
    mLineEdit5 = new QLineEdit(this);
    mLineEdit5->setObjectName("lineEdit_6");
    mLineEdit5->setGeometry(QRect(540, 30, 81, 21));

    pushButton_2 = new QPushButton(this);
    pushButton_2->setObjectName("pushButton_2");
    pushButton_2->setGeometry(QRect(150, 40, 75, 41)); 
    pushButton_2->setText("ADD GRID");
    pushButton_3 = new QPushButton(this);
    pushButton_3->setObjectName("pushButton_3");
    pushButton_3->setGeometry(QRect(480, 70, 75, 24));
    pushButton_3->setText("BresenHam");
    pushButton_4 = new QPushButton(this);
    pushButton_4->setObjectName("pushButton_4");
    pushButton_4->setGeometry(QRect(300, 70, 75, 24));
    pushButton_4->setText("Simple DDA");
    pushButton_5 = new QPushButton(this);
    pushButton_5->setObjectName("pushButton_5");
    pushButton_5->setText("ADD ");
    pushButton_5->setGeometry(QRect(640, 50, 75, 41));
    
    label = new QLabel(this);
    label->setObjectName("label");
    label->setGeometry(QRect(260, 10, 49, 16));
    label->setText("X1-");
    label_2 = new QLabel(this);
    label_2->setObjectName("label_2");
    label_2->setGeometry(QRect(370, 10, 49, 16));
    label_2->setText("Y1-");
    label_3 = new QLabel(this);
    label_3->setObjectName("label_3");
    label_3->setGeometry(QRect(460, 10, 49, 16));
    label_3->setText("X2-");
    label_4 = new QLabel(this);
    label_4->setObjectName("label_4");
    label_4->setGeometry(QRect(570, 10, 49, 16));
    label_4->setText("Y2-");
    label_5 = new QLabel(this);
    label_5->setObjectName("label_5");
    label_5->setGeometry(QRect(20, 10, 49, 16));
    label_5->setText("Grid Size");
    label_6 = new QLabel(this);
    label_6->setObjectName("label_6");
    label_6->setGeometry(QRect(20, 60, 49, 16));
    label_6->setText("Grid Step");

    mRenderer = new OpenGLWindow(QColor(0, 0, 0), this);
    mRenderer->setGeometry(QRect(20, 120, 701, 411));

    setWindowTitle(QCoreApplication::translate("SymetricDDA_BresenhamClass", "SymetricDDA_Bresenham", nullptr));

}
void Visualizer::addLines() {
    float x1 = mLineEdit2->text().toFloat();
    float y1 = mLineEdit3->text().toFloat();
    float x2 = mLineEdit4->text().toFloat();
    float y2 = mLineEdit5->text().toFloat();
    Line l(Point2D(x1, y1), Point2D(x2, y2));
    mRenderer->addLine(l);
}

void Visualizer::addGrids() {
    float gridSize = mLineEdit->text().toFloat();
    float gridStep = mLineEdit1->text().toFloat();
    mRenderer->addGrid(gridSize, gridStep);

}
void Visualizer::bresenhams() {
    float x1 = mLineEdit2->text().toFloat();
    float y1 = mLineEdit3->text().toFloat();
    float x2 = mLineEdit4->text().toFloat();
    float y2 = mLineEdit5->text().toFloat();
    Line l(Point2D(x1, y1), Point2D(x2, y2));
    mRenderer->bresenhams(l);
}
void Visualizer::simpleDDA() {
    float x1 = mLineEdit2->text().toFloat();
    float y1 = mLineEdit3->text().toFloat();
    float x2 = mLineEdit4->text().toFloat();
    float y2 = mLineEdit5->text().toFloat();
    Line l(Point2D(x1, y1), Point2D(x2, y2));
    mRenderer->simpleDDA(l);

}

