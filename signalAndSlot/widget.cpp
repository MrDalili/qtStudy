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

    void(Teacher::*teacherPara)(QString) = &Teacher::hungry;
    void(Student::*studentPara)(QString) = &Student::treat;
    //解耦信号和槽
    connect(teacher,teacherPara,student,studentPara);
    //触发信号
    //classOver();

    //通过信号去通知激发信号
    //新建一个button链接
    QPushButton * btn = new QPushButton("请客吃饭",this);
    resize(600,400);
    //绑定一下
    connect(btn,&QPushButton::clicked,this,&Widget::classOver);

    //信号传参这块

}

Widget::~Widget()
{
}

void Widget::classOver(){
    emit teacher->hungry("宫保鸡丁");
}
