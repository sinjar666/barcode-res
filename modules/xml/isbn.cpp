#include "isbn.h"

Isbn::Isbn(QString path,QObject *parent) :
    QObject(parent)
{
    filepath=path;
}
void Isbn::openwebpage(QString no)
{
    qDebug("working");
    QString web="http://isbn.net.in/";
    web.append(no);
    qDebug()<<web;
    page=new QWebPage();
    page->mainFrame()->load(QUrl(web));
    connect(page,SIGNAL(loadFinished(bool)),this,SLOT(result()));
}
void Isbn::result()
{
    qDebug("page load is complete");
    QString name,author,publisher,find_div,review;
    if(!page->findText("Not Found"))
    {   qDebug("isbn not 13 digit");
        break;
    }
    if(!page->findText("Cannot find any details about this book. Are you sure there is such a book?"))
    {   qDebug("wrong isbn");
        break;
	}
    QWebElementCollection collection;
    collection=page->mainFrame()->findAllElements("table");
    name=collection.at(0).attribute("class");
    //qDebug()<<name;

    QWebElement tbody=collection.at(0).firstChild();
    name=tbody.firstChild().firstChild().nextSibling().toPlainText();
    author=tbody.firstChild().nextSibling().firstChild().nextSibling().toPlainText();
    publisher=tbody.firstChild().nextSibling().nextSibling().firstChild().nextSibling().toPlainText();
    //qDebug()<<name;
    //qDebug()<<author;
    //qDebug()<<publisher;

    collection=page->mainFrame()->findAllElements("div");
    foreach(tbody,collection)
    {
        if(tbody.hasAttribute("id"))
        {
            find_div=tbody.attribute("id");
            if(find_div=="editorial_review")
            {   //qDebug("here");
                review=tbody.toPlainText();
                //qDebug()<<review;
                break;
            }
        }
    }
    QString img_src;
    collection=page->mainFrame()->findAllElements("a");
    img_src=collection.at(0).firstChild().attribute("src");

    manager=new QNetworkAccessManager(this);
    req=new QNetworkRequest(QUrl(img_src));
    manager->get(*req);
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(reply(QNetworkReply*)));
}
void Isbn::reply(QNetworkReply *rep)
{
    qDebug("donwload complete");
    if(rep->error())
    {return;

    }
    QByteArray pic=rep->readAll();
    QFile file("test_download.jpg");
    file.open(QIODevice::WriteOnly | QIODevice::Truncate);
    file.write(pic);
    file.close();
}

