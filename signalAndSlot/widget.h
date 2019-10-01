#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <teacher.h>
#include <student.h>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void classOver();
private:
    Teacher * teacher;
    Student * student;

};
#endif // WIDGET_H
