#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QPainterPath>
#include <QPainter>
#include <QTime>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(500,500);      //resize the main window
    ui->paint->setGeometry(50,10,400,400);
    ui->smallButton->setGeometry(40,420,70,35);
    ui->startButton->setGeometry(120,420,100,35);
    ui->stopButton->setGeometry(230,420,100,35);
    ui->bigButton->setGeometry(340,420,70,35);

    connect(ui->smallButton,SIGNAL(clicked()),this,SLOT(setSmall()));
    connect(ui->bigButton,SIGNAL(clicked()),this,SLOT(setBig()));
    connect(ui->stopButton,SIGNAL(clicked()),this,SLOT(stop()));
    connect(ui->startButton,SIGNAL(clicked()),this,SLOT(start()));
}

MainWindow::~MainWindow()
{
}
void MainWindow::stop()
{
    QTimer *timer = ui->paint->getTimer();
    timer->stop();
}

void MainWindow::start()
{
    QTimer *timer = ui->paint->getTimer();
    timer->start(100);
}
void MainWindow::setSmall()
{
    int small = ui->paint->getSmall();
    ui->paint->setSmall(small*2);
}

void MainWindow::setBig()
{
    int small = ui->paint->getSmall();
    ui->paint->setSmall(small/2);
}


