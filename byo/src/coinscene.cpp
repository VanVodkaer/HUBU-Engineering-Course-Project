#include "coinscene.h"
#include "ui_coinscene.h"
#include"startbutton.h"
#include"choosescene.h"
#include<QDebug>
#include<QPixmap>
#include<QAction>
#include<QPainter>
#include<QTimer>
#include<QMediaPlayer>
#include<QUrl>
#include"global.h"
CoinScene::CoinScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CoinScene)
{
    ui->setupUi(this);
    //设置主界面
    setFixedSize(WIDTH, HEIGHT);
    setWindowIcon(QIcon(":/image/Coin0001.png"));
    setWindowTitle("翻金币");
    //实现退出按钮
    connect(ui->actionquit, &QAction::triggered, this, [=](){
        this->close();
    });

    //实现开始按钮
    StartButton* startbtn = new StartButton(":/image/MenuSceneStartButton.png");
    startbtn->setParent(this);
    startbtn->move((this->width() - startbtn->width()) * 0.5, this->height() * 0.6);

    //start按钮音效
    QMediaPlayer* startSound = new QMediaPlayer(this);
    startSound->setVolume(80);  // 音量为0 - 100
    startSound->setMedia(QUrl(":/audio/btn.wav"));


    //实例化选择场景
    chooseScene = new ChooseScene;

    //增加按钮功能
    connect(startbtn, &StartButton::clicked, this, [=](){
        qDebug() << "点击了start";
        //声音特效
        startSound->play();
        //弹起特效
        startbtn->zoomUnder();
        startbtn->zoomUp();
        //延时切换
        QTimer::singleShot(370, this, [=](){
            //记录场景位置
            chooseScene->setGeometry(this->geometry());
            //场景切换
            this->hide();
            chooseScene->show();

        });
    });

    //监听返回信号
    connect(chooseScene, &ChooseScene::chooseback, this, [=](){
        QTimer::singleShot(70, this, [=](){
            //使用记录的场景位置
            this->setGeometry(chooseScene->geometry());
            chooseScene->hide();
            this->show();
        });
    });

}


void CoinScene::paintEvent(QPaintEvent* )
{
    //设置背景图片
    QPainter painter(this);
    QPixmap startScene;
    startScene.load(":/image/PlayLevelSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), startScene);
    //加载背景图标
    startScene.load(":/image/Title.png");
    painter.drawPixmap(0, 150, this->width() , this->height() * 0.27, startScene);
}
CoinScene::~CoinScene()
{
    delete ui;
}
