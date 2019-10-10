#include "widget.h"
#include "ui_widget.h"
#include "QDebug"
#include <QTimerEvent>
#include <QTimer>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //定时器,这个是使用函数之后使用id判断事件进行定时
    id1 = startTimer(1000);//每1秒调用一次timerEvent事件，并且返回一个这个事件的id
    id2 = startTimer(2000);


    //使用定时器类进行定时
    QTimer * timer = new QTimer(this);
    //启动定时器对象
    timer->start(500);//毫秒做单位
    //每0.5s发送一次信号
    connect(timer,&QTimer::timeout,[=](){
        static int num3 = 0;
        ui->timer_3->setText(QString::number(num3++));
    });

    connect(ui->stop,&QPushButton::clicked,[=](){
       timer->stop();
    });

    connect(ui->setButton,&QPushButton::clicked,[=](){
        ui->widget->setValue(50);
    });

    connect(ui->getButton,&QPushButton::clicked,[=](){
       qDebug() << ui->widget->getValue();
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent * e){
    if(e->timerId() == id1){
        static int num = 0;
        ui->timeer_1->setText(QString::number(num++));
    }
    if(e->timerId() == id2){
        static int num2 = 0;
        ui->timer_2->setText(QString::number(num2++));
    }
}
