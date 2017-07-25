#include "dangeshedizhi.h"
#include "ui_dangeshedizhi.h"
#include "dizhi.h"
#include "index.h"
#include "shezhi.h"

Dangeshedizhi::Dangeshedizhi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Dangeshedizhi)
{
    ui->setupUi(this);
    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->scanning,SIGNAL(clicked()),this,SLOT(showScan()));
}

Dangeshedizhi::~Dangeshedizhi()
{
    delete ui;
}

void Dangeshedizhi::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Dangeshedizhi::returnPage()
{
    Dizhi *returnPage=new Dizhi();
    returnPage->show();
    this->close();
}

void Dangeshedizhi::showScan()
{
    Shezhi *showScan=new Shezhi();
    showScan->show();
    this->close();
}
