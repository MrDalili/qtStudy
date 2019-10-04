#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    btn = new QPushButton("open",this);
    btn->setText("open1");
    resize(600,400);
    //一开始窗口没打开，为false
    flag = false;
    //把点击事件和触发函数绑定一下
    connect(btn,&QPushButton::clicked,this,&Widget::trigger);
    //把信号和槽函数帮顶一下
    connect(this,&Widget::isWin,this,&Widget::btnEvent);
}

Widget::~Widget()
{

}
//其实这个才是真正的槽函数
void Widget::btnEvent(bool * flag){
    if (*flag){
        //打开状态，那么窗口关闭
        w->close();
        *flag = false;
        btn->setText("open");
    }else {
        //新建一个窗口
       w = new Widget();
       //展示一下
       w->show();
       *flag = true;
       btn->setText("close");
    }
}
//触发槽函数
void Widget::trigger(){
    //触发这个信号
     emit isWin(&flag);
 }
