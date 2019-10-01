#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
   // ui->setupUi(this);
    //创建一个按钮
    QPushButton * btn = new QPushButton;
    //让btn对象依赖当前窗口
    btn->setParent(this);
    //设置文本
    btn->setText("第一个按钮");

    QPushButton * btn2 = new  QPushButton("第二个按钮",this);
    //移动被btn2的位置
    btn2->move(0,100);
    //重置大小
    resize(600,400);
    //设置固定的窗口大小
    setFixedSize(600,400);
    //设置窗口标题
    setWindowTitle("第一个窗口");

    //需求 点击我的按钮 关闭窗口
    //参数1 信号的发送者 参数2 发送的信号（函数的地址） 参数3 信号的接收者 参数4 处理的槽函数
    //松散耦合的作用
    connect(btn,&QPushButton::clicked,this, &QWidget::close);
}

Widget::~Widget()
{
    delete ui;
}

