#include "homescreen.h"

HomeScreen::HomeScreen(QWidget *parent) :
    QWidget(parent)
{
    rootdir=new QString("/home/user/MyDocs/");
    engine = new Engine(*rootdir+QString("index"));
    searchMode=false;

    top = new SearchBar(engine);
    middle = new MiddleWid(rootdir);
    bottom = new BottomBar(rootdir);
    lay=new QVBoxLayout(this);
    lay->addWidget(top);
    lay->addWidget(middle);
    lay->addWidget(bottom);
    confirm_dialog = new DelConfirmDialog(this);
    connect(bottom,SIGNAL(activateCamera()),this,SLOT(activateCamera()));
    connect(top,SIGNAL(sendToggle(bool)),this,SLOT(toggleSelectionMode(bool)));
    connect(middle,SIGNAL(sendSelectedList(QStringList)),this,SLOT(changeSelectedList(QStringList)));
    connect(top,SIGNAL(enterSearchMode(bool)),this,SLOT(setSearchMode(bool)));
    connect(top,SIGNAL(sendSearchText(QString)),this,SLOT(performSearch(QString)));
    connect(top,SIGNAL(openOthers()),this,SLOT(openOthers()));
    connect(middle,SIGNAL(displayContent(QString)),this,SLOT(openFile(QString)));
    connect(bottom,SIGNAL(requestDelete()),this,SLOT(performDelete()));
    connect(bottom,SIGNAL(requestRefresh()),this,SLOT(sendRefresh()));
}

void HomeScreen::toggleSelectionMode(bool checked)  {
    markMode = checked;
    middle->setMarkMode(checked);
}

void HomeScreen::setSearchMode(bool status) {
    searchMode=status;
    middle->setSearchModeOn(status);
}

void HomeScreen::performSearch(QString key) {
    QList<IndexItem> results;
    resultNames.clear();
    results=engine->getEntry(key);
    results.append(engine->getSubstringMatch(key));
    IndexItem result;
    foreach(result,results) {
        resultNames << result.getTitle();
    }
    resultNames.removeDuplicates();
    middle->showSearchResults(resultNames);
}

void HomeScreen::changeSelectedList(QStringList newFiles)    {
    currentFiles = newFiles;
    qDebug() << "Currently selected.." << currentFiles;
}

void HomeScreen::activateCamera()   {
    qDebug() << "start camera.";
}

void HomeScreen::openFile(QString fname)    {
    qDebug() << "Opening this file:"<<fname;

}
void HomeScreen::openOthers()   {
    qDebug() << "Opening this file:others";
}

void HomeScreen::performDelete()    {
    if(confirm_dialog->exec())  {
    QString name;
    foreach(name,currentFiles)  {
        //Delete that particular book from tumul class
        //Generate keywords from name
        //For each keyword delete entry from index
        resultNames.removeAll(name);
    }
    if(searchMode)
        middle->showSearchResults(resultNames);
    else
        middle->populateList();
}
}

void HomeScreen::sendRefresh()  {
    if(!searchMode)
        middle->populateList();
}
