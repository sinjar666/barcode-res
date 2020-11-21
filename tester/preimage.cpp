#include "preimage.h"

PreImage::PreImage(QObject *parent) :
    QObject(parent)
{
    src.load("/home/srijan/barcode/test12.jpg");
    dest=QImage(1024,768,QImage::Format_Mono);
    dest.fill(255);
    QImage img=src.scaled(1024,768,Qt::KeepAspectRatio);
    for (int i = 0; i < img.width(); ++i)
        {
            for (int j = 0; j < img.height(); ++j)
            {
                QRgb col = img.pixel(i, j);
                int gray = qGray(col);
                img.setPixel(i, j, qRgb(gray, gray, gray));
//                if(gray<170)
//                    binary[j][i]=true;
//                else
//                    binary[j][i]=false;
            }
        }
    img=img.convertToFormat(QImage::Format_Indexed8);
    int t=100,t_old=0;
    QSet<int> G1,G2;
    while(t_old!=t) {
        G1.clear();
        G2.clear();
        t_old=t;
            for(int i=0;i<img.width();i++) {
                for(int j=0;j<img.height(); j++) {
                    if(qRed(img.pixel(i,j)) > t)
                        G1.insert(qRed(img.pixel(i,j)));
                    else
                        G2.insert(qRed(img.pixel(i,j)));
                }
            }
        int x,sum1=0,sum2=0;
        foreach(x,G1)
            sum1+=x;
        sum1/=G1.size();
        foreach(x,G2)
            sum2+=x;
        sum2/=G2.size();
        t=(sum1+sum2)/2;
    }
    for(int i=0;i<img.width();i++) {
        for(int j=0;j<img.height();j++)  {
            int val=qRed(img.pixel(i,j));
            if(val<=t)
                dest.setPixel(i,j,0);
            else
                dest.setPixel(i,j,1);
        }
    }
    uint r=500;
    uint num_1l=0,max_1l=0,num_1r=0,max_1r=0,start_pos,end_pos;
    for(int i=511,j=511;i>=0;i--,j++) {
        if(qRed(dest.pixel(i,r))==0 || i==0) {
            if(num_1l>max_1l) {
                max_1l=num_1l;
                start_pos=i+max_1l+1;
            }
            num_1l=0;
        }
        else
            num_1l++;
        if(qRed(dest.pixel(j,r))==0 || i==0) {
            if(num_1r>max_1r)   {
                max_1r=num_1r;
                end_pos=j-max_1r-1;
            }
            num_1r=0;
        }
        else num_1r++;
    }
    uint left=start_pos;
    uint right=end_pos;
    qDebug()<<left << right;
    uint bit_width = (right-left+1)/95;
    qDebug() << bit_width;
    r=500;
    QImage tmp(right-left+1,100,QImage::Format_Mono);
    for(int i=0;i<=right-left;i++)    {
        for(int j=0;j<100;j++)   {
            if(qRed(dest.pixel(left+i,r+j))==0)
                tmp.setPixel(i,j,0);
            else
                tmp.setPixel(i,j,1);
        }
    }

    tmp=tmp.scaled(950,100,Qt::IgnoreAspectRatio);
    for(int i=0;i<950;i++)  {
        uint num0=0,num1=0,bit=0;
        for(int j=0;j<100;j++)  {
            if(qRed(tmp.pixel(i,j))==0)
                num0++;
            else num1++;
        }
        if(num1>num0) bit=1;
        else bit=0;
        for(int j=0;j<100;j++)  {
            tmp.setPixel(i,j,bit);
        }
    }
    //tmp=tmp.scaled(950,400,Qt::KeepAspectRatio);
    //for(int k=0;k<10;k++)   {
    QString bits;
    for(int i=0;i<950;i+=10)   {
        if(qRed(tmp.pixel(i+1,0))==0)
            bits+="1";
        else bits+="0";
    }

    qDebug() << bits;
    //}
    QFile fil2("out2.bmp");
    fil2.open(QIODevice::WriteOnly| QIODevice::Truncate);
    tmp.save(&fil2);
    fil2.close();


//    QString bits;
//    int c=1;
//    for(int i=134;i<=897;i++)   {
//        if(qRed(dest.pixel(i,r))==0)  {
//            if(c==bit_width)    {
//                bits += "1 ";
//                c=0;
//            }
//            else
//                bits+="1";
//        }
//        else    {
//            if(c==bit_width)    {
//                bits += "0 ";
//                c=0;
//            }
//            else    {
//                bits+="0";
//            }
//        }
//        c++;
//    }
    //qDebug() << bits;

//    QString bits;
//    uint curr_pos=left;
//    for(int k=0;k<10;k++)   {
//    uint sum=0,threshold=(bit_width*bit_width)*0.50;
//    for(uint i=curr_pos;i<curr_pos+bit_width;i++)   {
//        for(uint j=r;j<r+10;j++)  {
//            if(qRed(dest.pixel(i,j))==0)
//                    sum++;
//        }
//    }
//    bits+=(sum>=threshold) ? "1" : "0";
//    curr_pos += bit_width;
//    }
//    qDebug() << bits;
//    qDebug()<< curr_pos;

    QFile fil("out.bmp");
    fil.open(QIODevice::WriteOnly| QIODevice::Truncate);
    dest.save(&fil);
    fil.close();

}
