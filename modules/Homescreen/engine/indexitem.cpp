#include "indexitem.h"

IndexItem::IndexItem(const IndexItem &other)    {
    *this=other;
}

IndexItem::IndexItem(QString fname, int type, QString title)    {
    this->fname=fname;
    this->type=type;
    this->title=title.replace(" ","_");
}


IndexItem & IndexItem::operator=(const IndexItem &o)   {
    fname=o.getFname();
    type=o.getType();
    title=o.getTitle();
    return *this;
}

QString IndexItem::getFname() const   {
    return fname;
}

int IndexItem::getType() const    {
    return type;
}

QString IndexItem::getTitle() const   {
    return title;
}

QDataStream & operator<<(QDataStream & stream,const IndexItem & item)    {
    stream << item.getFname() << item.getType() << item.getTitle();
    return stream;
}

QDataStream & operator>>(QDataStream & in,IndexItem & item) {
    QString a,c;
    int b;
    in >> a >> b >> c;
    //qDebug()<<sdate;
    item = IndexItem(a,b,c);
    return in;
}

bool operator ==(const IndexItem & a, const IndexItem & b)  {
    if(a.getFname() == b.getFname() && a.getType() == b.getType() && a.getTitle() == b.getTitle())
        return true;
    else return false;
}
