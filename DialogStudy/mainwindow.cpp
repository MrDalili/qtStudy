#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDialog>
#include <QMessageBox>
#include <QColorDialog>
#include <QFileDialog>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QMovie>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    ui->actionNew->setIcon(QIcon(":/Image/LuffyQ.png"));
//    //点击新建菜单项，弹出学习的对话框
//    connect(ui->actionNew,&QAction::triggered,this,[=](){
        //对话框
        //模态:不可以对其他的窗口进行操作
//         QDialog dlg(this);
//         dlg.resize(200,100);
//         dlg.exec();//阻塞
        //非模态：可以对其他窗口进行操作
        //QDialog qlg2(this);//这样创建会创建在栈上，一闪而过在lamammd表达式中
//        QDialog * dlg2 = new QDialog(this);
//        dlg2->resize(100,200);
//        dlg2->show();
        //需要设置属性，因为这样才能让窗口关闭的时候，释放掉
//        dlg2->setAttribute(Qt::WA_DeleteOnClose);
        //使用标准对话框 QMessmageBox
        //错误对话框 参数1 父窗口  参数2 tittle 参数3 content
//        QMessageBox::critical(this,"错误！","critical");
        //信息对话框
//        QMessageBox::information(this,"信息","info");
        //询问对话框

//        if(QMessageBox::Save == QMessageBox::question(this,"问题","question",QMessageBox::Save | QMessageBox::Cancel,QMessageBox::Cancel)){
//            qDebug() << "点击的Save";
//        }else {
//            qDebug() << "点击的Cancel";
//        }

        //警告对话框
//        QMessageBox::warning(this,"警告！","warning");
        //选择颜色对话框
//        QColor color = QColorDialog::getColor(QColor(255,0,0));
//        qDebug() << "red" << color.red() << "green" << color.green() << "blue" << color.blue();
//        //文件对话框
//        QString path = QFileDialog::getOpenFileName(this,"打开文件","c:\\","(*.txt *.doc)");
//        qDebug() << path;
//    });
    //单选按钮 默认选中 男
//    ui->rBtnMan->setChecked(true);
//    //绑定事件 点击女的时候就输出选女的了
//    connect(ui->rBtnWoman,&QRadioButton::clicked,[=](){
//        qDebug() << "点击女的了!";
//    });
    //多选框 选中后打印内容
    //选中2 未选中0 tristate 1状态
//    connect(ui->checkBox,&QCheckBox::stateChanged,[=](int state){
//        qDebug() << state;
//    });
    //利用ListWideget写诗
//    QListWidgetItem * item = new QListWidgetItem("锄禾日当午");

//    //设置对齐方式
//    item->setTextAlignment(Qt::AlignHCenter);
//    //添加一行元素
//    ui->listWidget->addItem(item);

//   QStringList == QList<QString>
//    QStringList list;
//    list << "锄禾日当午" << "汗滴禾下土" << "谁之盘中餐" << "粒粒皆辛苦";
//    ui->listWidget->addItems(list);
    ui->listWidget->addItems(QStringList() << "锄禾日当午" << "汗滴禾下土" << "谁之盘中餐" << "粒粒皆辛苦");

    //treeWidget空间使用
    //添加头
    ui->treeWidget->setHeaderLabels(QStringList()<<"英雄名称"<<"英雄性别");
    //添加项目
    QTreeWidgetItem * item = new QTreeWidgetItem(QStringList()<<"力量");
    QTreeWidgetItem * item1 = new QTreeWidgetItem(QStringList()<<"敏捷");
    QTreeWidgetItem * item2 = new QTreeWidgetItem(QStringList()<<"智力");
    //添加顶层项目
    ui->treeWidget->addTopLevelItem(item);
    ui->treeWidget->addTopLevelItem(item1);
    ui->treeWidget->addTopLevelItem(item2);

    //第二层的元素
    QStringList heroL1;
    QStringList heroL2;
    QStringList heroM1;
    QStringList heroM2;
    QStringList heroZ1;
    QStringList heroZ2;
    heroL1 << "刚被猪" << "前排坦克，能在吸收伤害的同时造成可观的范围输出";
    heroL2 << "船长" << "前排坦克，能肉能输出能控场的全能英雄";

    heroM1 << "月骑" << "中排物理输出，可以使用分裂利刃攻击多个目标";
    heroM2 << "小鱼人" << "前排战士，擅长偷取敌人的属性来增强自身战力";

    heroZ1 << "死灵法师" << "前排法师坦克，魔法抗性较高，拥有治疗技能";
    heroZ2 << "巫医" << "后排辅助法师，可以使用奇特的巫术诅咒敌人与治疗队友";

    //追加子节点 子项目也是QTreeWidgetItem
    QTreeWidgetItem * li1 = new QTreeWidgetItem(heroL1);
    QTreeWidgetItem * li2 =new QTreeWidgetItem(heroL2);
    item->addChild(li1);
    item->addChild(li2);

    //QTableWidget使用
    //先告诉空间有多少列
    QStringList list;
    list << "姓名" << "性别" << "年龄";
    //设置列数
    ui->tableWidget->setColumnCount(list.size());
    //设置水平头
    ui->tableWidget->setHorizontalHeaderLabels(list);

    //设置行数
    ui->tableWidget->setRowCount(5);

    //设置正文
//    ui->tableWidget->setItem(0,0,new QTableWidgetItem("亚瑟"));
    //用for循环来填
    //准备数据
    //准备数据
    QStringList nameList;
    nameList << "亚瑟"<< "妲己"<< "安琪拉"<< "东皇太一"<< "李白";

    QList<QString> sexList;
    sexList << "男" << "女"<< "女"<< "男"<< "男";

    for(int i = 0 ; i < 5; i++){
        int col = 0;
        //添加名称
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(nameList[i]));
        //添加性别
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(sexList.at(i)));
        //添加年龄
        //int 转 QString number
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(QString::number(i+18)));

    }

    connect(ui->add,&QPushButton::clicked,this,[=](){
       //先判断是不是有赵云，有的话不添加，没有的话添加
        bool isEmpty = ui->tableWidget->findItems("赵云",Qt::MatchExactly).empty();

        if(isEmpty){
            //如果没有的话，添加
            ui->tableWidget->insertRow(0);
            ui->tableWidget->setItem(0,0,new QTableWidgetItem("赵云"));
            ui->tableWidget->setItem(0,1,new QTableWidgetItem("男"));
            ui->tableWidget->setItem(0,1,new QTableWidgetItem(QString::number(20)));
        }else {
            QMessageBox::warning(this,"警告！","已存在赵云");
        }
    });

    connect(ui->deleteZ,&QPushButton::clicked,this,[=](){
        //判断一下有没有赵云
        bool isEmpty = ui->tableWidget->findItems("赵云",Qt::MatchExactly).empty();
        //判断
        if(isEmpty){
            QMessageBox::warning(this,"警告","赵云已经没了不能删除了");
        }else {
            //先找到赵云所在的行
            int row = ui->tableWidget->findItems("赵云",Qt::MatchExactly).first()->row();
            //找到行数 删除掉
            ui->tableWidget->removeRow(row);
        }
    });

    //设置默认选中的第0项
    ui->stackedWidget->setCurrentIndex(2);

    //给按钮添加事件，切换stackWidget中的页面
    connect(ui->btnScroll,&QPushButton::clicked,[=](){
       ui->stackedWidget->setCurrentIndex(0);
    });

    connect(ui->btnTab_2,&QPushButton::clicked,[=](){
       ui->stackedWidget->setCurrentIndex(1);
    });

    connect(ui->btnToolBox_2,&QPushButton::clicked,[=](){
       QMessageBox::question(this,"宁大力可以当你的宝宝吗","宁大力可以当你的宝宝吗",QMessageBox::Ok | QMessageBox::Cancel,QMessageBox::Ok);
    });

    //下拉框
    //给下拉框添加内容
    ui->comboBox->addItems(QStringList() << "宁大力" << "马林青");

    connect(ui->btnChoose,&QPushButton::clicked,[=](){
       ui->comboBox->setCurrentText("马林青");
    });

    //利用QLabel显示静态图片
    ui->img->setPixmap(QPixmap(":/Image/Luffy.png"));

    //利用QLabel显示动态图片
    QMovie * movie = new QMovie(":/Image/mario.gif");
    ui->movie->setMovie(movie);
    //播放gif
    movie->start();


}

MainWindow::~MainWindow()
{
    delete ui;
}

