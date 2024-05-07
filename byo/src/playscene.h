#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include<QPaintEvent>
#include"coinbutton.h"
class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit PlayScene(int level);
    int levelNum;
    void paintEvent(QPaintEvent*) override;

    //维护每关数据
    int gameArr[4][4];
    //维护硬币
    CoinButton* coinArr[4][4];
    //是否胜利
    bool isWin;
signals:
    void levelback();
};

#endif // PLAYSCENE_H
