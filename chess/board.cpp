#include "Board.h"
#include <QPainter>

Board::Board(QWidget *parent) : QWidget(parent)
{

}


void Board::paintEvent(QPaintEvent *){
    QPainter painter(this);
    int d = 45;
    // 画10横线
    for (int i = 1; i <= 10 ; ++i) {
        painter.drawLine(QPoint(d , i*d) , QPoint(9*d , i*d));
    }
    //画竖线
    for (int i = 1; i <= 9 ; ++i) {
        if(i == 1 || i == 9)
            painter.drawLine(QPoint(i*d , d) , QPoint(i*d , 10*d));
        else{
            painter.drawLine(QPoint(i*d , d) , QPoint(i*d , 5*d));
            painter.drawLine(QPoint(i*d , 6*d) , QPoint(i*d , 10*d));
        }
    }
    //画9宫格
    painter.drawLine(QPoint(4*d , 1*d) , QPoint(6*d , 3*d));
    painter.drawLine(QPoint(6*d , 1*d) , QPoint(4*d , 3*d));
    painter.drawLine(QPoint(4*d , 8*d) , QPoint(6*d , 10*d));
    painter.drawLine(QPoint(4*d , 10*d) , QPoint(6*d , 8*d));

    //绘制32个棋子
    for (int i = 0 ; i < 32 ; ++i) {
        drawChess(painter,i);
    }
};

void Board::drawChess(QPainter &painter, int i){

}
