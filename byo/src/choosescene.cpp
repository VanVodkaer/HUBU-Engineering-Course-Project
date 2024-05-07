#include "choosescene.h"
#include"global.h"
#include"startbutton.h"
#include<QPixmap>
#include<QMenuBar>
#include<QPainter>
#include<QDebug>
#include<QTimer>
#include<QLabel>
#include<QTimer>
ChooseScene::ChooseScene(QWidget *parent)
    : QMainWindow{parent}
{
    //固定界面
    this->setFixedSize(WIDTH, HEIGHT);
    //设置图标
    this->setWindowIcon(QPixmap(":/image/PlayLevelSceneBg.png"));
    //设置标题
    this->setWindowTitle("关卡选择");
    //设置图标
    this->setWindowIcon(QIcon(":/image/Coin0001.png"));
    QMenuBar* bar =  menuBar();

    setMenuBar(bar);

    QMenu* startMenu = bar->addMenu("开始");
    QAction* quitAction = startMenu->addAction("退出");
    connect(quitAction, &QAction::triggered, this, [=](){
        this->close();
    });
    StartButton* backBtn = new StartButton(":/image/BackButton.png", ":/image/BackButtonSelected.png");
    backBtn->setParent(this);
    //backBtn->setFixedSize(BACKBTN_WIDTH, BACKBTN_HEIGHT);  // 只改变了按键大小，却没改变图片大小
    backBtn->move(this->width() - backBtn->width(), this->height() - backBtn->height());
    connect(backBtn, &StartButton::clicked, this, [=](){
        qDebug() << "点击返回";
        emit this->chooseback();
    });

    //选择关卡按钮
    for(int i = 0; i < 20; ++i)
    {
        StartButton* chooseBtn = new StartButton(":/image/LevelIcon.png");
        chooseBtn->setParent(this);
        chooseBtn->move(100 + (i % 4) * 120, 150 + (i / 4) * 120);   // 需要与下面的label-move数值同步修改

         //监听每个按钮
        connect(chooseBtn, &StartButton::clicked, this, [=](){
            qDebug() << QString("您选择的是第 %1 关").arg(i + 1);

            //进入游戏场景
            this->hide();
            play = new PlayScene(i + 1);
            //设置游戏场景位置
            play->setGeometry(this->geometry());
            play->show();

            //监听返回信号
            connect(play, &PlayScene::levelback, this, [=](){
                QTimer::singleShot(70, this, [=](){
                    this->setGeometry(play->geometry());
                    this->show();
                    delete play;
                    play = NULL;
                });
            });
        });
        //设置关卡名
        QLabel* label = new QLabel;
        label->setParent(this);
        label->setFixedSize(chooseBtn->width(), chooseBtn->height());
        label->setText(QString::number(i + 1));
        label->move(100 + (i % 4) * 120, 150 + (i / 4) * 120);

        //设置label上的文字对齐方式
        label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        //让鼠标穿透label
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
    }
}

void ChooseScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/PlayLevelSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

}
