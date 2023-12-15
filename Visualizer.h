#pragma once

#include <QtWidgets/QMainWindow>
#include <QInputDialog>

class OpenGLWindow;

class Visualizer : public QMainWindow
{
    Q_OBJECT

public:
    Visualizer(QWindow* parent = nullptr);
    ~Visualizer();

private:
    void setupUi();
public slots:
    void addLines();
    void addGrids();
    void bresenhams();
    void simpleDDA();

private:
    QMenuBar* mMenuBar;
    QToolBar* mMainToolBar;
    QWidget* mCentralWidget;
    QStatusBar* mStatusBar;
    OpenGLWindow* mRenderer;
    OpenGLWindow* mRenderer1;
    QPushButton* pushButton,*pushButton_2,*pushButton_3,*pushButton_4,*pushButton_5;
    QLineEdit* mLineEdit, *mLineEdit1,*mLineEdit2,  *mLineEdit3,  *mLineEdit4,  *mLineEdit5;
    QLabel* label;
    QLabel* label_2;
    QLabel* label_3;
    QLabel* label_4;
    QLabel* label_5;
    QLabel* label_6;

   
    
};


