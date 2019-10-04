#include "widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //创建老师
    teacher = new Teacher(this);
    //创建学生
    student = new Student(this);
    //如果信号和槽有参数的话，需要使用函数指针
    void(Teacher::*teacherPara)(void) = &Teacher::hungry;
    void(Student::*studentPara)(void) = &Student::treat;
    //解耦信号和槽
    connect(teacher,teacherPara,student,studentPara);
    //触发信号
    //classOver();

    //通过信号去通知激发信号
    //新建一个button链接
    QPushButton * btn = new QPushButton("请客吃饭",this);
    resize(600,400);
    //绑定一下,通过点击事件绑定到classOver，classOver中出发老师的带参信号
    connect(btn,&QPushButton::clicked,teacher,teacherPara);

}

Widget::~Widget()
{
}

void Widget::classOver(){
    emit teacher->hungry();
}
