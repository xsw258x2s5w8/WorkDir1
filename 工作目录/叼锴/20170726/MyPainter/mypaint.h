#ifndef MYPAINT_H
#define MYPAINT_H

#include <QWidget>

class myPaint : public QWidget
{
    Q_OBJECT
public:
    explicit myPaint(QWidget *parent = 0);
    ~myPaint();

    QTimer *getTimer();
    int getSmall();
    void setSmall(int small);
private:
    int p, t;   //p represent the x coordinate of the start point of painting, t represent the  x coordinate of time
    QTimer *timer;
    QPoint *point;
    QPointF *p1;
    QPointF *p2;
    QPainterPath *path;
    int small;//变小倍数
    void virtual paintEvent(QPaintEvent *);     //paintEvent method, need to be reimplemented

public slots:
    void timerUpdate();      //slot method for the timer signal timeout()
    
};

#endif // MYPAINT_H
