#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //创建老师
    teacher = new Teacher(this);
    //创建学生
    student = new Student(this);
    //解耦信号和槽
    connect(teacher,&Teacher::hungry,student,&Student::treat);
    //触发信号
    classOver();
}

Widget::~Widget()
{
}

void Widget::classOver(){
    emit teacher->hungry();
}
