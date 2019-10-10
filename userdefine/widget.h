#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    //定时器事件
    void timerEvent(QTimerEvent *);

    //定时器的ID
    int id1;
    int id2;
    //事件过滤器的事件
private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
