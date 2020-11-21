#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    TestWidget *w = new TestWidget();
    //ImageTester *w2 = new ImageTester();
    setCentralWidget(w);
}

MainWindow::~MainWindow()
{

}
