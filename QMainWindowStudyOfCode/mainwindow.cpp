#include "mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QLabel>
#include <QStatusBar>
#include <QDockWidget>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(600,400);
    //菜单栏
    //菜单栏只能有一个
    QMenuBar *mb = menuBar();
    //添加菜单
    QMenu * fileMenu = mb->addMenu("文件");
    QMenu * editMenu = mb->addMenu("编辑");
    //添加菜单项
    QAction * newAction = fileMenu->addAction("新建");
    //添加分界线
    fileMenu->addSeparator();
    QAction * openAction = fileMenu->addAction("打开");

    //工具栏 可以有多个
    QToolBar * toolBar = new QToolBar(this);
    //给new出来的toolBar添加默认的停靠范围，类似于初始化
    addToolBar(Qt::LeftToolBarArea,toolBar);
    //只允许左右上停靠
    toolBar->setAllowedAreas(Qt::LeftToolBarArea|Qt::RightToolBarArea|Qt::TopToolBarArea);
    //设置浮动
    toolBar->setFloatable(false);
    //设置移动(总开关)，这个有了就不可以浮动和移动了
    toolBar->setMovable(false);

    //工具栏添加菜单项
    toolBar->addAction(newAction );
    //添加分割线
    toolBar->addSeparator();
    toolBar->addAction(openAction);

    //状态栏 只能有一个
    QStatusBar * stBar = statusBar();
    //将状态栏和主窗口绑定在一起
    setStatusBar(stBar);
    //创建状态栏上的提示信息
    QLabel * label = new QLabel("提示信息",this);
    //添加信息到左侧
    stBar->addWidget(label);

    QLabel * label1 = new QLabel("右侧提示信息",this);
    //添加信息到右侧
    stBar->addPermanentWidget(label1);


    //铆接部件 浮动窗口 可以有多个
    QDockWidget * dock = new QDockWidget;
    //添加铆接部件到窗口中,并且初始化在底部
    addDockWidget(Qt::BottomDockWidgetArea,dock);
    //设置停靠范围
    dock->setAllowedAreas(Qt::BottomDockWidgetArea|Qt::TopDockWidgetArea);

    //核心部件 只能有一个
    QTextEdit * edit = new QTextEdit;
    //把这个核心部件添加进去
    setCentralWidget(edit);
}

MainWindow::~MainWindow()
{
}

