#include "coinbutton.h"

// CoinButton::CoinButton(QWidget *parent)
//     : QWidget{parent}
// {}
#include<QPixmap>
#include<QDebug>
CoinButton::CoinButton(QString btnImg)
{
    QPixmap pix;
    bool ret = pix.load(btnImg);
    pix = pix.scaled(100, 100);
    if(!ret)
    {
        qDebug() << QString("加载 %1 图片失败").arg(btnImg);
        return;
    }
    this->setFixedSize(pix.width(), pix.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(), pix.height()));

    this->timerGold = new QTimer(this);
    this->timerSilver = new QTimer(this);
    //监听翻金币的信号
    connect(timerGold, &QTimer::timeout, this, [=](){
        QPixmap pix;
        bool ret = pix.load(QString(":/image/Coin000%1.png").arg(this->min++));
        pix = pix.scaled(100, 100);
        if(!ret)
        {
            qDebug() << QString("加载 Coin000%1.png 图片失败").arg(this->min - 1);
            return;
        }
        this->setFixedSize(pix.width(), pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(), pix.height()));
        if(this->min > this->max)
        {
            min = 1;
            isAnimation = false;
            timerGold->stop();
        }
    });

    //监听翻银币的信号
    connect(timerSilver, &QTimer::timeout, this, [=](){
        QPixmap pix;
        bool ret = pix.load(QString(":/image/Coin000%1.png").arg(this->max--));
        pix = pix.scaled(100, 100);
        if(!ret)
        {
            qDebug() << QString("加载 Coin000%1.png 图片失败").arg(this->min + 1);
            return;
        }
        this->setFixedSize(pix.width(), pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(), pix.height()));
        if(this->min > this->max)
        {
            max = 8;
            isAnimation = false;
            timerSilver->stop();
        }
    });
}

void CoinButton::mousePressEvent(QMouseEvent* e)
{
    if(this->isAnimation || this->isWin)
    {
        return;  // 动画完毕后才能使用else中的内容，继续翻金币， 用于截断
    }
    else
    {
        return QPushButton::mousePressEvent(e);
    }
}
void CoinButton::changeFlag()
{

    if(this->flag)
    {
        timerGold->start(30);
        this->flag = false;
    }
    else
    {
        timerSilver->start(30);
        this->flag = true;
    }
    isAnimation = true;  // 更改动画状态
}
