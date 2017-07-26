#include "mypaint.h"
#include <QTimer>
#include <QPainterPath>
#include <QPainter>
#include <QTime>
myPaint::myPaint(QWidget *parent) :
    QWidget(parent)
{
    p = t = 0;
    timer = new QTimer;
    path = new QPainterPath;
    point = new QPoint;
    p1 = new QPointF;
    p2 = new QPointF;
    small=2;
    p2->setX(0);
    p2->setY(this->height());
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpdate()));

    this->setAutoFillBackground(true);
    QPalette p = this->palette();
    p.setColor(QPalette::Background, QColor(96,96,96));
    this->setPalette(p);
    //this->setGeometry(100,100,700,400);
}

myPaint::~myPaint()
{
    delete timer;
    delete point;
    delete path;
}



//reimplemented virtual method paintEvent
void myPaint::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);
    painter.setPen(QPen(Qt::white));//adjust the painter size and color

    int height = this->height();
    int width = this->width();
    //画网格
    for(int i=0;i<width;i=i+50)
    {
        painter.drawLine(i,0,i,height);

    }
    for(int j=height;j>0;j=j-50)
    {
       painter.drawLine(width,j,0,j);
    }



    painter.setPen(QPen(Qt::white));
    QPoint originPoint(p,0);
    painter.translate(originPoint);  //adjust the origin point of the painting
    painter.drawPath(*path);  //painting
    //QWidget::paintEvent(event);
}


//slot method, will be called when the timer is time out
void myPaint::timerUpdate()
{
    t += 10;
    //create random number
    QTime time;
    time= QTime::currentTime();
    qsrand(time.msec()+time.second()*1000);
    int rand=qrand()%this->height();//产生0-this->height()之间的随机值
    //the next point of the painted line
    //point->setX(t);
    //point->setY(rand);


    p1->setX(p2->x());
    p1->setY(p2->y());
    p2->setX(t);
    p2->setY(this->height()-rand/small);
    path->quadTo(*p1,*p2);


    //向右移动
    if(t > this->width())
    {
        p -= 10;
    }

    //in case update() method is called, the system will trigger paintEvent to repaint the window
    this->update();

}
QTimer *myPaint::getTimer()
{
    return timer;
}
int myPaint::getSmall()
{
    return small;
}
void myPaint::setSmall(int small)
{
    if(small>=1&&small<=4)
        this->small = small;
}

