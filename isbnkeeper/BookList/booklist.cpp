#include "booklist.h"

Booklist::Booklist(Engine *engine_a,QString path,QWidget *parent) :
    QWidget(parent)
{
    setWindowTitle("ISBN Keeper -- Book List");
    engine=engine_a;
    filepath=path;
    top_w=new Topmid(filepath);
    bottom_w=new BottomBar2();
    layout_w=new QVBoxLayout(this);
    layout_w->addWidget(top_w);
    layout_w->addWidget(bottom_w);
    menu=new QMenuBar(this);
    menu->addAction("Description");
    confirm_dialog = new DelConfirmDialog(this);
    err_d = new QErrorMessage(this);
    //layout_w->addWidget(label_image);
    connect(bottom_w,SIGNAL(activateCamera()),this,SLOT(activateCamera()));
    connect(bottom_w,SIGNAL(requestDelete()),this,SLOT(deletepressed()));
    connect(bottom_w,SIGNAL(sendToggle(bool)),this,SLOT(markpressed(bool)));
    connect(top_w,SIGNAL(itemselect(QStringList)),this,SLOT(selected_item(QStringList)));
    connect(menu,SIGNAL(triggered(QAction*)),this,SLOT(displaydescription(QAction*)));
//    connect(top_w,SIGNAL(itemselect(QStringList)),this,SLOT(load_img(QStringList)));
    connect(top_w,SIGNAL(itemopen(QString)),this,SLOT(double_clicked(QString)));
    //connect(top_w,SIGNAL(/*camera-signal*/),this,SLOT(list_update()));
}
void Booklist::displaydescription(QAction *act)
{
    if(act->text()=="Description")
    {
        Descdialog *dia=new Descdialog(filepath,this);
        dia->exec();
    }
}

void Booklist::activateCamera()
{
    Path=filepath;
    qDebug()<<"activate camera" << Path;
    //emit startCamera(filepath);
    camera = new StillCam(this);
    //camera->setAttribute(setOrientation(ScreenOrientationLockLandscape));
    camera->setAttribute(Qt::WA_Maemo5StackedWindow);
    camera->setAttribute(Qt::WA_DeleteOnClose);
    camera->setWindowFlags(camera->windowFlags() | Qt::Window);
    connect(camera,SIGNAL(gotISBN(QString)),this,SLOT(fetchInfo(QString)));
    camera->show();
}

void Booklist::fetchInfo(QString isbn) {
    camera->close();
    //camera->deleteLater();
    //delete(camera);
    image_failed=false;
    isbn_no = isbn;
    fetcher = new Isbn();
    fetcher->openwebpage(isbn);
    connect(fetcher,SIGNAL(img_error()),this,SLOT(setImageFailed()));
    connect(fetcher,SIGNAL(load_complete()),this,SLOT(displayInfoAfterLoad()));
//    loading = new LoaderWidget(this);
//    //loading->setAttribute(setOrientation(ScreenOrientationLockLandscape));
//    loading->setAttribute(Qt::WA_DeleteOnClose);
//    loading->setAttribute(Qt::WA_Maemo5StackedWindow);
//    loading->setWindowFlags(loading->windowFlags()|Qt::Window);
//    loading->show();
    loading = new QProgressDialog(tr("ISBN:: ")+isbn+tr("\n")+tr("Retrieving data from server."),tr("Stop"),0,0,this);
    loading->setAutoClose(true);
    loading->setWindowTitle("Please Wait");
    connect(loading,SIGNAL(canceled()),this,SLOT(cancelDisplayInfo()));
    loading->show();
}

void Booklist::cancelDisplayInfo()  {
    fetcher->deleteLater();
}

void Booklist::displayInfoAfterLoad() {
    if(fetcher->getError()==Isbn::ISBN_INVALID) {
        fetcher->deleteLater();
        loading->reset();
        err_d->showMessage(tr("The returned ISBN is invalid!!"));
        return;
    }
    else if(fetcher->getError()==Isbn::ISBN_NOTFOUND)   {
        fetcher->deleteLater();
        loading->reset();
        err_d->showMessage(tr("The requested book was not found in the online database. Must be a very rare book."));
        return;
    }
    QString title,author,publisher,summary,img_url;
    title=fetcher->getname();
    author=fetcher->getauthor();
    publisher=fetcher->getpublisher();
    summary=fetcher->getreview();
    img_url=fetcher->getUrl();
    qDebug() << "fetch done..";
    fetcher->deleteLater();
    if(title==""||author==""||publisher==""||summary==""||img_url=="")  {
        loading->reset();
        err_d->showMessage(tr("Unable to fetch the content. Check internet connection and retry..."));
        return;
    }
    xml_engine = new Xfile();
    bool rval=xml_engine->addbook(Path,title,author,publisher,isbn_no,
                        QTime::currentTime().toString(),QDate::currentDate().toString(),summary,img_url);
    if(!rval)   {
        loading->reset();
        err_d->showMessage(tr("Unable to save to file. Either file is corrupt or disk write-protected."));
        return;
    }

    QRegExp exp("\\/{1,1}\\w+\\.{1,1}");
    int pos=Path.indexOf(exp,0);
    QString fname = Path.mid(pos+1,Path.length()-pos-1);
    IndexItem item(fname,isbn_no,title,1);
    engine->addEntry(title,item);
    item=IndexItem(fname,isbn_no,title,2);
    engine->addEntry(author,item);
    item=IndexItem(fname,isbn_no,title,3);
    engine->addEntry(publisher,item);
    engine->saveIndex();
    QImage cover;
    if(!image_failed)
        cover = QImage("/home/user/isbn-book.jpg");
    else
        cover=QImage(":/leather-book-preview.png"); //default image
    loading->reset();
    delete(xml_engine);

    book_info = new BookInfoWid(cover,isbn_no,title,author,publisher,summary,this);
    //book_info->setAttribute(setOrientation(ScreenOrientationLockLandscape));
    book_info->setAttribute(Qt::WA_Maemo5StackedWindow);
    book_info->setWindowFlags(book_info->windowFlags()|Qt::Window);
    book_info->show();
}

void Booklist::setImageFailed()    {
    image_failed = true;
}




void Booklist::selected_item(QStringList name)
{
    current_files=name;
}

void Booklist::deletepressed()
{
    Xml_list=new Xfile();
    QString select_name;
    if(current_files.length()==0) {
        err_d->showMessage(tr("Please select one or more files!!"));
    }
    else    {
    if(confirm_dialog->exec())
    {
        foreach(select_name,current_files)
        {
            QRegExp exp("\\({1,1}[0-9]{13,13}\\){1,1}$");
            //exp.indexIn(select_name);
            int pos=select_name.indexOf(exp,0);
            QString isbn_ = select_name.mid(pos+1,13);
            //isbn=match;
            //QString isbn_ = exp.cap();
            qDebug()<<"deleting isbn " << isbn_;
            bool rval=Xml_list->deletexml(filepath,isbn_);
            if(!rval)   {
                err_d->showMessage(tr("Delete failed! File corrupt or disk write-protected."));
                Xml_list->deleteLater();
                return;
            }
            engine->removeByISBN(isbn_);
            engine->saveIndex();
        }
    }
    top_w->populatelist();
  }
}
void Booklist::double_clicked(QString name)
{
    QString isbn;
    QRegExp exp("\\({1,1}[0-9]{13,13}\\){1,1}$");
    int pos=name.indexOf(exp,0);
    isbn = name.mid(pos+1,13);
    //emit book_info(isbn_);
    Path=filepath;
    qDebug() << isbn;
    isbn_no=isbn;
    xml_engine = new Xfile();
    data=xml_engine->getbookinfo(Path,isbn);
    delete(xml_engine);
    fetcher = new Isbn();
    image_failed=false;
    connect(fetcher,SIGNAL(img_error()),this,SLOT(setImageFailed2()));
    connect(fetcher,SIGNAL(load_complete()),this,SLOT(displayInfoFromFile()));
    fetcher->getimage(data.at(4));
//    loading = new LoaderWidget(this);
//    //loading->setAttribute(setOrientation(ScreenOrientationLockLandscape));
//    loading->setAttribute(Qt::WA_DeleteOnClose);
//    loading->setAttribute(Qt::WA_Maemo5StackedWindow);
//    loading->setWindowFlags(loading->windowFlags()|Qt::Window);
//    //connect(fetcher,SIGNAL(load_complete()),this,SLOT(displayInfoAfterLoad()));
//    loading->show();
    loading = new QProgressDialog("Fetching cover image...","Cancel",0,0,this);
    loading->setAutoClose(true);
    loading->setWindowTitle("Please wait");
    connect(loading,SIGNAL(canceled()),this,SLOT(cancelFetchImage()));
    loading->show();
}

void Booklist::cancelFetchImage()   {
    image_failed=true;
    fetcher->deleteLater();
    displayInfoFromFile();
}

void Booklist::setImageFailed2()    {
    fetcher->deleteLater();
    image_failed=true;
    //displayInfoFromFile();
}

void Booklist::displayInfoFromFile()    {
    //loading->close();
    delete(loading);
    if(!image_failed) fetcher->deleteLater();
    if(!image_failed)
        cover=QImage("/home/user/isbn-book.jpg");
    else
        cover=QImage(":/leather-book-preview.png"); //Default book image
    //qDebug()<< data ;
    book_info = new BookInfoWid(cover,isbn_no,data.at(0),data.at(1),data.at(2),data.at(3),this);
    //book_info->setAttribute(setOrientation(ScreenOrientationLockLandscape));
    book_info->setAttribute(Qt::WA_Maemo5StackedWindow);
    book_info->setWindowFlags(book_info->windowFlags() | Qt::Window);
    book_info->show();
}

void Booklist::markpressed(bool status)
{        Mark_mode=status;
        top_w->setMarkMode(status);
}
//void Booklist::load_img(QStringList item)
//{
//    if(item.length()==1)
//    {
//        manager=new QNetworkAccessManager(this);
//        req=new QNetworkRequest(QUrl(img_src));
//        manager->get(*req);
//        connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(reply_label(QNetworkReply*)));
//    }
//    else
//    {
//        QString item_select=item.length();
//        label_image=new QLabel("Multiple selected.");
//        label_image->setMaximumSize(200,400);
//        label_image->setWordWrap(true);
//        label_image->setText(item_select);
//    }
//}
//void Booklist::reply_label(QNetworkReply *rep)
//{
//    qDebug("donwload complete");
//    if(rep->error())
//    {return;
//    }
//    QByteArray pic=rep->readAll();
//    pix_map=new QPixmap();
//    if(!pix_map.loadFromData(pic))
//        qDebug("image not loaded");
//    label_image=new QLabel();
//    label_image.pixmap(pix_map);
//}
void Booklist::list_update()
{
    top_w->populatelist();
}
