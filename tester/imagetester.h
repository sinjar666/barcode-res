#ifndef IMAGETESTER_H
#define IMAGETESTER_H

#include <QWidget>
#include <QImage>
#include <QPixmap>
#include <QLabel>
#include <QDebug>
class ImageTester : public QWidget
{
    Q_OBJECT
    QImage img;
    bool binary[768][1024];
    uint curr_pos,bit_width;
    QLabel *label;

public:
    explicit ImageTester(QWidget *parent = 0);
    bool readBit();

signals:

public slots:

};

#endif // IMAGETESTER_H
