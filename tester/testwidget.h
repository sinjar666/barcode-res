#ifndef TESTWIDGET_H
#define TESTWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QVBoxLayout>
#include <QLineEdit>
#include "readean13.h"

class TestWidget : public QWidget
{
    Q_OBJECT
    QLabel *pre;
    QLineEdit *res_e;
    QVBoxLayout *lay;
    ReadEAN13 *reader;
public:
    explicit TestWidget(QWidget *parent = 0);

signals:

public slots:
    void workerStarted();
    void workerCompleted();

};

#endif // TESTWIDGET_H
