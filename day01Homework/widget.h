#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void trigger();//触发函数
    void btnEvent(bool * flag);//槽
signals:
    void isWin(bool * flag);//信号

private:
    bool flag;//判断窗口打开没有
    Widget * w;//新建的窗口
    QPushButton * btn;//按钮
};
#endif // WIDGET_H
