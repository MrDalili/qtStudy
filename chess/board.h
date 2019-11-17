#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include "Chess.h"
class Board : public QWidget
{
    Q_OBJECT
public:
    explicit Board(QWidget *parent = nullptr);

    Chess _list[32];//存放所有的棋子的数组
    //绘制棋盘
    void paintEvent(QPaintEvent *);
    //绘制棋子
    void drawChess(QPainter& painter, int i);
signals:

public slots:
};

#endif // BOARD_H
