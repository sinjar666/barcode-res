#ifndef PREIMAGE_H
#define PREIMAGE_H

#include <QObject>
#include <QImage>
#include <QSet>
#include <QFile>
#include <QColor>
#include <QPixmap>
#include <QDebug>

class PreImage : public QObject
{
    Q_OBJECT
    QImage src,dest;
public:
    explicit PreImage(QObject *parent = 0);

signals:

public slots:

};

#endif // PREIMAGE_H
