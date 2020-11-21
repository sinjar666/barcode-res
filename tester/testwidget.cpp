#include "testwidget.h"

TestWidget::TestWidget(QWidget *parent) :
    QWidget(parent)
{
    QString path = "/home/srijan/barcode/isbn-image.jpg";
    QPixmap pixmap(path);
    pre = new QLabel();
    pre->setPixmap(pixmap.scaled(320,200));
    res_e = new QLineEdit("ISBN");
    res_e->setReadOnly(true);
    lay = new QVBoxLayout(this);
    lay->addWidget(pre);
    lay->addWidget(res_e);
    reader = new ReadEAN13(path);
    reader->start();
    connect(reader,SIGNAL(started()),this,SLOT(workerStarted()));
    connect(reader,SIGNAL(finished()),this,SLOT(workerCompleted()));
}

void TestWidget::workerStarted()    {
    qDebug() << "Execution of worker thread started.";
}

void TestWidget::workerCompleted()  {
    qDebug() << "Thread exited gracefully";
    QString result;
    result = reader->getResult();
    qDebug() << result;
    res_e->setText(result);
}
