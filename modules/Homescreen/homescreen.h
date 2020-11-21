#ifndef HOMESCREEN_H
#define HOMESCREEN_H

#include <QWidget>
#include <QVBoxLayout>
#include "searchbar.h"
#include "middlewid.h"
#include "bottombar.h"
#include "delconfirmdialog.h"
#include "engine/engine.h"

class HomeScreen : public QWidget
{
    Q_OBJECT
    bool searchMode,markMode;
    SearchBar *top;
    MiddleWid *middle;
    BottomBar *bottom;
    QVBoxLayout *lay;
    Engine *engine;
    QString *rootdir;
    QStringList currentFiles;
    QStringList resultNames;
    DelConfirmDialog *confirm_dialog;

public:
    explicit HomeScreen(QWidget *parent = 0);

signals:

public slots:
    void activateCamera();
    void toggleSelectionMode(bool checked);
    void changeSelectedList(QStringList newFiles);
    void setSearchMode(bool status);
    void performSearch(QString key);
    void performDelete();
    void openFile(QString fname);
    void openOthers();
    void sendRefresh();

};

#endif // HOMESCREEN_H
