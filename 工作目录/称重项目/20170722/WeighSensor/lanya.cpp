#include "lanya.h"
#include "ui_lanya.h"
#include "index.h"
#include "wangluoshezhi.h"
Lanya::Lanya(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Lanya)
{
    ui->setupUi(this);
    //tableview 里的东西
    ui->tableWidget->setWindowTitle("QTableWidget & Item");
    ui->tableWidget->resize(350, 200);  //设置表格
    QStringList header;
    header<<"Bluetooth"<<"Operation"<<"junction"<<"intercalate";
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->setItem(0,0,new QTableWidgetItem("Jan"));

    ui->tableWidget->setItem(0,1,new QTableWidgetItem(QIcon("../WeighSensor/image/images/gantan.svg"), "Jan's month"));
    ui->tableWidget->setItem(0,2,new QTableWidgetItem("Junction"));
    ui->tableWidget->setItem(0,3,new QTableWidgetItem("intercalate"));
//    QImage *ppm = new QImage("../WeighSensor/image/images/gantan.svg");
//    QLabel *label = new QLabel();
//    label->setPixmap(QPixmap::fromImage(*ppm));
//    ui->tableWidget->setCellWidget(0,3,label);



    ui->tableWidget->verticalHeader()->setVisible(false);   //隐藏列表头

    //槽函数
    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Lanya::~Lanya()
{
    delete ui;
}

void Lanya::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Lanya::returnPage()
{
    Wangluoshezhi *returnPage=new Wangluoshezhi();
    returnPage->show();
    this->close();
}
