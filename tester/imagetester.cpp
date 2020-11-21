#include "imagetester.h"

ImageTester::ImageTester(QWidget *parent) :
    QWidget(parent)
{

    img.load("/home/srijan/barcode/test6.jpg");
    img=img.scaled(1024,768);
    //binary = (uchar **)malloc(1024*768);
    for (int i = 0; i < img.width(); ++i)
        {
            for (int j = 0; j < img.height(); ++j)
            {
                QRgb col = img.pixel(i, j);
                int gray = qGray(col);
                img.setPixel(i, j, qRgb(gray, gray, gray));
                if(gray<140)
                    binary[j][i]=true;
                else
                    binary[j][i]=false;
            }
        }
    img=img.convertToFormat(QImage::Format_Indexed8,Qt::MonoOnly);
    label = new QLabel(this);
    QPixmap pixmap = QPixmap::fromImage(img);
    label->setPixmap(pixmap);
    uint w,h;
    w = img.width();
    qDebug()<<w;
    h = img.height();
    uint r=0.40*h;
    //uint i=w/2;
    QString bits;
    uint num_0l=0,max_0l=0,num_0r=0,max_0r=0,start_pos,end_pos;
    for(int i=512,j=512;i>=0;i--,j++) {
        if(binary[r][i]==true) {
            if(num_0l>max_0l) {
                max_0l=num_0l;
                start_pos=i+max_0l+1;
            }
            num_0l=0;
        }
        else
            num_0l++;
        if(binary[r][j]==true) {
            if(num_0r>max_0r)   {
                max_0r=num_0r;
                end_pos=j-max_0r-1;
            }
            num_0r=0;
        }
        else num_0r++;
    }
    for(int i=0;i<1024;i++)
        bits+=(binary[r][i]==true)?"1":"0";
    qDebug() <<"start="<< start_pos<< "  end=" << end_pos;
    qDebug() << bits;
    curr_pos=start_pos;
    bit_width=7;
    QString val;
    for(int i=0;i<=7;i++)
        val+=(readBit()?"1":"0");
    qDebug() << val;
}

bool ImageTester::readBit()  {
    uint sum=0,threshold=(bit_width*bit_width)*0.6;
    QString val;
    for(uint j=(0.4*768);j<(0.4*768)+bit_width;j++)  {
        for(uint i=curr_pos;i<curr_pos+bit_width;i++)   {
            if(binary[j][i])    {
                val+="1 ";
                sum++;
            }
            else val+="0 ";
        }
        val+="\n";
    }
    curr_pos+=bit_width;
    qDebug() << val;
    //qDebug()<<curr_pos << sum << threshold;
    if(sum>=threshold) return true;
    else
        return false;
}
