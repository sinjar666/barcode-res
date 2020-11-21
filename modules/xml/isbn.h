#ifndef ISBN_H
#define ISBN_H

#include <QObject>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QWebFrame>
#include <QWebPage>
#include <QWebElementCollection>
#include <QWebElement>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QWebView>


class Isbn : public QObject{
    Q_OBJECT
    QString filepath;
    QWebPage *page;
    //QString webtext;
    QNetworkAccessManager *manager;
    QNetworkRequest *req;
public:
    explicit Isbn(QString path,QObject *parent = 0);
    void openwebpage(QString no);

signals:

public slots:
    void result();
    void reply(QNetworkReply *rep);
};

#endif // ISBN_H
