#include "widget.h"
#include "ui_widget.h"
#include "QDebug"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->setButton,&QPushButton::clicked,[=](){
        ui->widget->setValue(50);
    });

    connect(ui->getButton,&QPushButton::clicked,[=](){
       qDebug() << ui->widget->getValue();
    });
}

Widget::~Widget()
{
    delete ui;
}

