#include "student.h"
#include <QDebug>
Student::Student(QObject *parent) : QObject(parent)
{

}

void Student::treat(){
    qDebug() << "请老师吃饭";
}

void Student::treat(QString food){

    qDebug() << "请老师吃饭" << food.toUtf8().data();
}
