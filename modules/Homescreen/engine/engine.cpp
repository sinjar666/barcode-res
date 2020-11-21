#include "engine.h"

Engine::Engine(QString path_a,QObject *parent) :
    QObject(parent)
{
    path = new QString(path_a + "index");
    filterby = 0;
}

void Engine::loadIndex()    {
    file = new QFile(*path);
    if(!file->open(QIODevice::ReadOnly))    {
        qDebug() << "loadIndex():: Index file not found.";
    }
    QDataStream stream(file);
    stream >> index;
    file->close();
    delete(file);
}

void Engine::saveIndex()    {
    file = new QFile(*path);
    if(!file->open(QIODevice::WriteOnly|QIODevice::Truncate))   {
        qDebug() << "saveIndex()::Unable to create file.";
    }
    QDataStream stream(file);
    stream << index;
    file->close();
    delete(file);
}

void Engine::createEmptyIndex() {
    file = new QFile(*path);
    if(!file->open(QIODevice::WriteOnly|QIODevice::Truncate))   {
        qDebug() << "saveIndex()::Unable to create file.";
    }
}

void Engine::addEntry(QString keyword, IndexItem item)  {
    index.insert(keyword,item);
}

QList<IndexItem> Engine::getEntry(QString keyword) {
    QList<IndexItem> vals,results;
    if(index.contains(keyword))
        vals = index.values(keyword);
    IndexItem val;
    foreach(val,vals)   {
            if(filterby==0)
                results.append(val);
            if((filterby & TITLE_F)>0 && val.getType()==1)
                results.append(val);
            if((filterby & AUTHOR_F)>0 && val.getType()==2)
                results.append(val);
            if((filterby & PUBLISHER_F)>0 && val.getType() == 3)
                results.append(val);


    }

    return vals;
}

bool Engine::remove(QString key)    {
    if(index.remove(key)>0) {
        saveIndex();
        return true;
    }
    else return false;
}

bool Engine::remove(QString key, IndexItem val) {
    if(index.remove(key,val)>0) {
        return true;
        saveIndex();
    }
    else return false;
}

bool Engine::removeByName(QString fname)  {
    QMultiHash<QString,IndexItem>::const_iterator i;
    QString text;
    IndexItem val;
    bool found=false;
    for(i=index.constBegin();i!=index.constEnd();++i)   {
        text = i.key();
        val = i.value();
        if(val.getFname()==fname)   {
            i--;
            found=true;
            remove(text,val);
        }
    }
    return found;
}

QList<IndexItem> Engine::getSubstringMatch(QString keyword) {
    QList<IndexItem> *results;
    results = new QList<IndexItem>();
    QMultiHash<QString,IndexItem>::const_iterator i;
    for(i=index.constBegin();i!=index.constEnd();++i)   {
        QString text = i.key();
        IndexItem val = i.value();
        if(text.contains(keyword,Qt::CaseInsensitive) && text!=keyword)  {
            if(filterby==0)
                results->append(val);
            if((filterby & TITLE_F)>0 && val.getType()==1)
                results->append(val);
            if((filterby & AUTHOR_F)>0 && val.getType()==2)
                results->append(val);
            if((filterby & PUBLISHER_F)>0 && val.getType() == 3)
                results->append(val);
        }
    }
    return *results;
    delete(results);
}

void Engine::setFilter(Filters arg,bool status) {
    if(status)
        filterby |= (int)arg;
    else
        filterby &= (~(int)arg);
}

quint8 Engine::getFilters()   {
    return filterby;
}

QList<QString> Engine::getKeys(IndexItem val)   {
    return index.keys(val);
}
