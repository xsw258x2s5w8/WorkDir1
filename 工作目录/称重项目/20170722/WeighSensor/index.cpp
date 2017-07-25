#include "index.h"
#include "ui_index.h"
#include "page2.h"
#include "erweimaguanli.h"
#include "lishijilu.h"
#include "yiciguobang.h"
#include "erciguobang.h"
#include "shipin.h"

Index::Index(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Index)
{
    ui->setupUi(this);
    connect(ui->menu,SIGNAL(clicked()),this,SLOT(showMenuWidget()));
    connect(ui->QRcode,SIGNAL(clicked()),this,SLOT(showQRcode()));
    connect(ui->print,SIGNAL(clicked()),this,SLOT(showPrint()));
    connect(ui->yiciguobang,SIGNAL(clicked()),this,SLOT(showYiguobang()));
    connect(ui->erciguobang,SIGNAL(clicked()),this,SLOT(showErciguobang()));
    connect(ui->shipin,SIGNAL(clicked()),this,SLOT(showShipin()));
    //开启ip摄像头
    const string videoStreamAddress = "rtsp://admin:123456@192.168.1.105:10554/udp/av0_0";
    if(!vcap.open(videoStreamAddress)) {
        cout << "Error opening video stream or file" << endl;
        return ;
    }else
        cout<<"success"<<endl;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(readframe()));
    connect(timer, SIGNAL(timeout()), this, SLOT(showImage()));
    timer->start(33);
}

Index::~Index()
{
    delete ui;
}

void Index::showMenuWidget()
{
    page2 *menu=new page2();
    menu->show(); //open menu Widget
//    this->close();  //close parent Widget
}

void Index::showQRcode()
{
    Erweimaguanli *showQRcode=new Erweimaguanli();
    showQRcode->show();
//    this->close();
}

void Index::showPrint()
{
    Lishijilu *showPrint=new Lishijilu();
    showPrint->show();
//    this->close();
}

void Index::showYiguobang()
{
    Yiciguobang *showYiguobang=new Yiciguobang();
    showYiguobang->setCarWeight(ui->weight_label->text());
    showYiguobang->setCarTare(ui->lineEdit->text());

    QStringList strList;
    //strList.append(ui->lineEdit->text());//皮重
    strList.append(ui->lineEdit_car->text());
    strList.append(ui->lineEdit_art->text());
    strList.append(ui->lineEdit_remark->text());
    showYiguobang->showData(strList);  //进入一次过磅页面的显示

    showYiguobang->show();
//    this->close();
}

void Index::showErciguobang()
{
    Erciguobang *showErciguobang=new Erciguobang();
    showErciguobang->getWeight(ui->weight_label->text());
    QStringList strList;
    strList.append(ui->lineEdit_car->text());
    strList.append(ui->lineEdit_art->text());
    strList.append(ui->lineEdit_remark->text());
    showErciguobang->showData(strList);  //进入二次过磅页面的显示
    showErciguobang->show();
//    this->close();
}

void Index::showShipin()
{
    Shipin *showShipin = new Shipin();
    showShipin->show();
//    this->close();
}

void Index::readframe()
{
    int counter = 0;
 //   for(;;){
 //       counter++;
        if(!vcap.read(frame))
        {
            cout << "No frame" << endl;
            waitKey();
        }
//        if (counter %2!= 0)
//            continue;
//        cv::imshow("Output Window", image);
//        double rate=vcap.get(CV_CAP_PROP_FPS);
//        std::cout<<"帧率为:"<<rate<<std::endl;
//        if(cv::waitKey(1) >= 0) break;
//   }
}

QImage Mat2QImage(Mat cvImg)
{
    QImage qImg;
    if (cvImg.channels() == 3)                             //3 channels color image
    {

        cvtColor(cvImg, cvImg, CV_BGR2RGB);
        qImg = QImage((const unsigned char*)(cvImg.data),
               cvImg.cols, cvImg.rows,
               cvImg.cols*cvImg.channels(),
               QImage::Format_RGB888);
    }
    else if (cvImg.channels() == 1)                    //grayscale image
    {
        qImg = QImage((const unsigned char*)(cvImg.data),
               cvImg.cols, cvImg.rows,
               cvImg.cols*cvImg.channels(),
               QImage::Format_Indexed8);
    }
    else
    {
        qImg = QImage((const unsigned char*)(cvImg.data),
               cvImg.cols, cvImg.rows,
               cvImg.cols*cvImg.channels(),
               QImage::Format_RGB888);
    }

    return qImg;
}

void Index::showImage()
{
    vcap >> frame;
    realimage = Mat2QImage(frame);
    int Owidth = realimage.width(),Oheight = realimage.height();
//    cout<<Owidth<<","<<Oheight<<endl;
    int Fwidth,Fheight;       //缩放后的图片大小
    int Mul;
    if(Owidth/400>=Oheight/300)
        Mul=Owidth/400;
    else
        Mul=Oheight/300;
    Fwidth=Owidth/Mul;
    Fheight=Oheight/Mul;//记录图片与label大小的比例，用于缩放图片
    image = realimage.scaled(Fwidth,Fheight,Qt::KeepAspectRatio);
    ui->iplabel->setPixmap(QPixmap::fromImage(image));  // 将图片显示到label上
}
