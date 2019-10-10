#include "mymouseevent.h"
#include <QDebug>
#include<QMouseEvent>

MyMouseEvent::MyMouseEvent(QWidget *parent) : QLabel(parent)
{
    //设置鼠标追踪
    this->setMouseTracking(true);
}

//鼠标进入
void MyMouseEvent::enterEvent(QEvent *)
{
    qDebug()  << "鼠标进入了！！！";
}

//鼠标离开
void MyMouseEvent::leaveEvent(QEvent *)
{
     qDebug()  << "鼠标离开了！！！";
}

//鼠标按下
void MyMouseEvent::mousePressEvent(QMouseEvent *ev)
{
    //判断是不是左键
    if(ev->button() == Qt::LeftButton){
        QString str = QString("鼠标按下来啦！x = %1 y = %2").arg(ev->x()).arg(ev->y());
        qDebug() << str;
    }
}

//鼠标释放
void MyMouseEvent::mouseReleaseEvent(QMouseEvent *ev){
    QString str = QString("鼠标释放啦！x = %1 y = %2").arg(ev->x()).arg(ev->y());
    qDebug() << str;
}

//鼠标移动
void MyMouseEvent::mouseMoveEvent(QMouseEvent *ev)
{
    //持续状态，需要buttons 用与操作符进行判断

     QString str = QString("鼠标移动了！！！ x = %1 y = %2").arg(ev->x()).arg(ev->y());
     qDebug()  << str;

}
