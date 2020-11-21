#ifndef FILTERDIALOG_H
#define FILTERDIALOG_H

#include <QDialog>
#include <QCheckBox>
#include <QHBoxLayout>
#include "engine/engine.h"

class FilterDialog : public QDialog
{
    Q_OBJECT
    QHBoxLayout *lay;
    QCheckBox *title_b,*author_b,*pub_b;
    Engine *obj;
public:

    explicit FilterDialog(Engine *e,quint8 arg,QWidget *parent = 0);

signals:

public slots:
    void titleChecked(int state);
    void authorChecked(int state);
    void pubChecked(int state);

};

#endif // FILTERDIALOG_H
