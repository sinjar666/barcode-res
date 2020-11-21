#include "searchbar.h"

SearchBar::SearchBar(Engine *arg,QWidget *parent) :
    QWidget(parent)
{
    e=arg;
    others_b = new QPushButton("Others.");
    filter_b = new QPushButton("Filter");
    mark_b = new QPushButton("Mark");
    mark_b->setCheckable(true);
    search_view = new QDeclarativeView(QUrl("qrc:/qml/searchbox.qml"));
    item = search_view->rootObject();
    lay = new QHBoxLayout(this);
    lay->addWidget(others_b);
    lay->addItem(new QSpacerItem(100,search_view->height()));
    lay->addWidget(mark_b);
    lay->addWidget(search_view);
    lay->addWidget(filter_b);
    filters = new FilterDialog(e,e->getFilters(),this);
    connect(item,SIGNAL(keyPressed(QString)),this,SLOT(searchTextChanged(QString)));
    connect(filter_b,SIGNAL(clicked()),this,SLOT(filterPressed()));
    connect(others_b,SIGNAL(clicked()),this,SLOT(othersPressed()));
    connect(mark_b,SIGNAL(toggled(bool)),this,SLOT(markToggled(bool)));
}

void SearchBar::markToggled(bool checked)   {
    emit sendToggle(checked);
}

void SearchBar::toggleOthers(bool enabled)  {
    if(!enabled) others_b->setDisabled(true);
    else others_b->setDisabled(false);
}

void SearchBar::searchTextChanged(QString text) {
    qDebug("here.");
    if(text!="")    {
        emit enterSearchMode(true);
        emit sendSearchText(text);
    }
    else
        emit enterSearchMode(false);
}

void SearchBar::filterPressed() {
    filters->exec();
}

void SearchBar::othersPressed() {
    emit openOthers();
}
