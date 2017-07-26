#include "shipin_twousb.h"
#include "ui_shipin_twousb.h"

Shipin_twousb::Shipin_twousb(QString name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Shipin_twousb)
{
    ui->setupUi(this);
    cam = NULL;
    cam2 = NULL;

    imag=new QImage();
    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(readFarme()));
    connect(ui->usbFrame,SIGNAL(clicked()),this,SLOT(openCamera1()));
    connect(ui->moniFrame,SIGNAL(clicked()),this,SLOT(openCamera2()));
    connect(ui->fourFrame,SIGNAL(clicked()),this,SLOT(showfourFrame()));
//    openCamara();//打开摄像头
    if(name == "USBCamera")
        openCamera1();
    if(name == "moniCamera")
        openCamera2();
    qDebug()<<name;
}

Shipin_twousb::~Shipin_twousb()
{
    delete ui;
}

void Shipin_twousb::openCamera1()
{
    if(cam2 != NULL)
        cvReleaseCapture(&cam2);//释放内存；
    ui->usbFrame->setEnabled(false);
    ui->moniFrame->setEnabled(true);
//    sleep(1);
    cam=cvCreateCameraCapture(0);
    timer->start(33);
}

void Shipin_twousb::openCamera2()
{
    if(cam != NULL)
        cvReleaseCapture(&cam);//释放内存；
    ui->moniFrame->setEnabled(false);
    ui->usbFrame->setEnabled(true);
//    sleep(1);
    cam2=cvCreateCameraCapture(1);
    timer->start(33);
}

void Shipin_twousb::readFarme()
{
    if(cam != NULL)
        frame=cvQueryFrame(cam);
    else
        frame=cvQueryFrame(cam2);
    QImage imag=QImage((const uchar*)frame->imageData,frame->width,frame->height,QImage::Format_RGB888).rgbSwapped();
    ui->label->setPixmap(QPixmap::fromImage(imag));
}

void Shipin_twousb::saveImage()
{
    const QPixmap *pixmap = ui->label->pixmap();
    QString format = "png";
    QDateTime dateTime = QDateTime::currentDateTime();
    QString fileName ="../WeighSensor/savePicture/" + dateTime.toString("yyyy-MM-dd hh-mm-ss-zzz")+ "." + format;
    if (!fileName.isEmpty())
        pixmap->save(fileName, format.toAscii());
}

void Shipin_twousb::showfourFrame()
{
    Shipin *shipin = new Shipin();
    shipin->show();
    this->close();
}

void Shipin_twousb::returnIndex()
{
    this->close();
}

void Shipin_twousb::returnPage()
{
    Shipin *shipin = new Shipin();
    shipin->show();
    this->close();
}
