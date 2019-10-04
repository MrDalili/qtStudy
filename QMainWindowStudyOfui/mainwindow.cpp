#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //先将资源添加进项目中
    //然后使用 ( : + 前缀名 + 文件名 )的方式在项目中使用
    ui->actionnew->setIcon(QIcon(":/Image/Luffy.png"));

}

MainWindow::~MainWindow()
{
    delete ui;
}

