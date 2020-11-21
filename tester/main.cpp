#include <QtGui/QApplication>
#include "mainwindow.h"
#include "preimage.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
//    PreImage *w = new PreImage();
//    exit(0);
    return a.exec();
//    return 0;
}
