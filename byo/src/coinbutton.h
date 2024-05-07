#ifndef COINBUTTON_H
#define COINBUTTON_H
#include<QTimer>
#include <QPushButton>

class CoinButton : public QPushButton
{
    Q_OBJECT
public:
    //explicit CoinButton(QWidget *parent = nullptr);
    CoinButton(QString btnImg);

    //金币的属性
    int posX;
    int posY;
    bool flag;  // 金银币，

    void changeFlag();
    //翻面定时器
    QTimer* timerGold;
    QTimer* timerSilver;
    int min = 1;
    int max = 8;

    //执行动画
    bool isAnimation = false;
    void mousePressEvent(QMouseEvent* e) override;

    //是否胜利
    bool isWin = false;
signals:
};

#endif // COINBUTTON_H
