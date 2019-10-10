#include "mytool.h"
#include "ui_mytool.h"

mytool::mytool(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mytool)
{
    ui->setupUi(this);

    //QSpinBox移动 Slider跟着移动
    void(QSpinBox:: * signal)(int) = &QSpinBox::valueChanged;
    connect(ui->spinBox,signal,ui->horizontalSlider,&QSlider::setValue);

    //Slider移动 SpinBox跟着移动
    connect(ui->horizontalSlider,&QSlider::valueChanged,ui->spinBox,&QSpinBox::setValue);
}

void mytool::setValue(int v){
    ui->horizontalSlider->valueChanged(v);
}
int mytool::getValue(){
    return ui->horizontalSlider->value();
}
mytool::~mytool()
{
    delete ui;
}
