#ifndef CHESS_H
#define CHESS_H


class Chess
{
public:
    Chess();
    ~Chess();

    enum TYPE{ JIANG, CHE, PAO, MA, BING, SHI, XIANG};

    int _row;//行
    int _col;//列
    int _id;//编号
    bool _die;//是否死亡
    bool _res;//是蓝色方还是红色方
    TYPE _type;//类型
};

#endif // CHESS_H
