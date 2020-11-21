#ifndef INDEXITEM_H
#define INDEXITEM_H

#include <QString>
#include <QDebug>
#include <QDate>
#include <QDataStream>

class IndexItem
{
    QString fname,title;
    int type;

public:
    IndexItem()    {}
    IndexItem(const IndexItem &other);
    IndexItem(QString fname,int type,QString title);
    IndexItem &operator=(const IndexItem &o);


    QString getFname() const;
    int getType() const;
    QString getTitle() const;

};
QDataStream & operator<<(QDataStream & stream,const IndexItem & item);
QDataStream & operator>>(QDataStream & in,IndexItem & item);
bool operator==(const IndexItem & a,const IndexItem & b);
#endif // INDEXITEM_H
