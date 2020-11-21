#ifndef SEARCHBAR_H
#define SEARCHBAR_H

#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QGraphicsObject>
#include <QDeclarativeView>
#include "engine/engine.h"
#include "filterdialog.h"

class SearchBar : public QWidget
{
    Q_OBJECT
public:
    explicit SearchBar(Engine *arg,QWidget *parent = 0);
    void toggleOthers(bool enabled);

private:
    Engine *e;
    QHBoxLayout *lay;
    QDeclarativeView *search_view;
    QPushButton *others_b,*filter_b,*mark_b;
    FilterDialog *filters;
     QGraphicsObject *item;

signals:
    void sendToggle(bool checked);
    void enterSearchMode(bool status);
    void sendSearchText(QString text);
    void openOthers();

public slots:
    void searchTextChanged(QString text);
    void filterPressed();
    void othersPressed();
    void markToggled(bool checked);

};

#endif // SEARCHBAR_H
