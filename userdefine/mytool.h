#ifndef MYTOOL_H
#define MYTOOL_H

#include <QWidget>

namespace Ui {
class mytool;
}

class mytool : public QWidget
{
    Q_OBJECT

public:
    explicit mytool(QWidget *parent = nullptr);
    ~mytool();

    //关联信号和槽的函数
    void setValue(int v);
    int getValue();
private:
    Ui::mytool *ui;
};

#endif // MYTOOL_H
