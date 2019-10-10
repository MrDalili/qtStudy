#ifndef MYMOUSEEVENT_H
#define MYMOUSEEVENT_H

#include <QLabel>

class MyMouseEvent : public QLabel
{
    Q_OBJECT
public:
    explicit MyMouseEvent(QWidget *parent = nullptr);

    //捕获事件
    //鼠标进入
    void enterEvent(QEvent *) override;
    //鼠标离开
    void leaveEvent(QEvent *) override;

    //鼠标按下
    void mouseMoveEvent(QMouseEvent *ev) override;
    //鼠标释放
    void mouseReleaseEvent(QMouseEvent *ev) override;
    //鼠标移动
    void mousePressEvent(QMouseEvent *ev) override;
signals:

public slots:
};

#endif // MYMOUSEEVENT_H
