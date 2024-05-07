#include "playscene.h"
#include<QDebug>
#include<QMenuBar>
#include<QAction>
#include<QPainter>
#include<QPixmap>
#include<QLabel>
#include"global.h"
#include"startbutton.h"
#include<QMediaPlayer>
#include<QSound>
#include"dataconfig.h"
PlayScene::PlayScene(int level)
{
    qDebug() << QString("进入了第%1关").arg(level);
    this->levelNum = level;

    //关卡设置界面
    this->setFixedSize(WIDTH, HEIGHT);
    this->setWindowIcon(QIcon(":/image/Coin0001.png"));
    this->setWindowTitle(QString("翻金币 : 第 %1 关").arg(level));

    QMenuBar* bar = menuBar();
    QMenu* startMenu = bar->addMenu("开始");
    QAction* quitAction = startMenu->addAction("退出");
    //退出功能
    connect(quitAction, &QAction::triggered, this, [=](){
        this->close();
    });

    //返回按钮
    StartButton* backBtn = new StartButton(":/image/BackButton.png", ":/image/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width() - backBtn->width(), this->height() - backBtn->height());
    connect(backBtn, &StartButton::clicked, this, [=](){
        emit this->levelback();
    });

    //显示当前关卡数
    QLabel* label = new QLabel(this);
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(20);
    label->setFont(font);
    label->setText(QString("level ") + QString::number(this->levelNum));
    //设置矩形框
    label->setGeometry(QRect(40, this->height() - 50, 150, 50));

    //初始化每关二维数组
    DataConfig config;
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            this->gameArr[i][j] = config.m_data[this->levelNum][i][j];
        }
    }
    //声音设置
    QMediaPlayer* successSound = new QMediaPlayer(this);
    successSound->setVolume(80);  // 音量为0 - 100
    successSound->setMedia(QUrl(":/audio/success.wav"));

    QSound* coinSound = new QSound(":/audio/coinMusic.wav", this);
    coinSound->setLoops(5);

    //显示金币背景图
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            QLabel* label = new QLabel;
            label->setGeometry(100 + i * 120, 280  + j * 120, 120, 120);  // 前面参数为move位置
            // 需要与下面pix.scaled数值同步， 也需要修改coinBtn的位置

            QPixmap pix = QPixmap(":/image/BoardNode.png");
            pix = pix.scaled(120, 120);
            label->setPixmap(pix);
            label->setParent(this);

            //判断金币还是银币
            QString str;
            //金币
            if(gameArr[i][j] == 1)
            {
                str = ":/image/Coin0001.png";
            }
            else if(gameArr[i][j] == 0)
            {
                str = ":/image/Coin0008.png";
            }
            //创建金银币币按键
            CoinButton* coinBtn = new CoinButton(str);
            coinBtn->setParent(this);
            coinBtn->move(110 + i * 120, 290  + j * 120);  // 排放时按列排放的， 列不变行先改变来进行排序
            //金币属性
            coinBtn->posX = i;
            coinBtn->posY = j;
            coinBtn->flag = this->gameArr[i][j];  // 1为金币，0为银币

            //金币存入，用于维护
            coinArr[i][j] = coinBtn;

            connect(coinBtn, &CoinButton::clicked, this, [=](){
                coinBtn->changeFlag();
                //声音
                coinSound->play();
                this->gameArr[i][j] = !this->gameArr[i][j];
                QTimer::singleShot(100, this, [=]()
                {
                    //反转周围金币
                    if(coinBtn->posX + 1 <= 3)
                    {
                        coinArr[coinBtn->posX + 1][coinBtn->posY]->changeFlag();
                        this->gameArr[coinBtn->posX + 1][coinBtn->posY] = !this->gameArr[coinBtn->posX + 1][coinBtn->posY];
                    }
                    if(coinBtn->posY + 1 <=3)
                    {
                        coinArr[coinBtn->posX][coinBtn->posY + 1]->changeFlag();
                        this->gameArr[coinBtn->posX][coinBtn->posY + 1] = !this->gameArr[coinBtn->posX][coinBtn->posY + 1];
                    }
                    if(coinBtn->posX - 1 >= 0)
                    {
                        coinArr[coinBtn->posX - 1][coinBtn->posY]->changeFlag();
                        this->gameArr[coinBtn->posX - 1][coinBtn->posY] = !this->gameArr[coinBtn->posX - 1][coinBtn->posY];
                    }
                    if(coinBtn->posY - 1 >= 0)
                    {
                        coinArr[coinBtn->posX][coinBtn->posY - 1]->changeFlag();
                        this->gameArr[coinBtn->posX][coinBtn->posY - 1] = !this->gameArr[coinBtn->posX][coinBtn->posY - 1];
                    }
                    //胜利判断
                    this->isWin = true;
                    for(int i = 0; i < 4; ++i)
                    {
                        for(int j = 0; j < 4; ++j)
                        {
                            if(coinArr[i][j]->flag == false)
                            {
                                this->isWin = false;
                                break;
                            }
                        }
                    }
                    if(this->isWin)
                    {
                        qDebug() << "victory!";
                        //声音
                        successSound->play();
                        //禁止胜利后点击
                        for(int i = 0; i < 4; ++i)
                        {
                            for(int j =0; j  <4; ++j)
                            {
                                coinArr[i][j]->isWin = true; // 设硬币
                            }
                        }
                        QPixmap pixWin;
                        pixWin.load(":/image/LevelCompletedDialogBg.png");
                        pixWin = pixWin.scaled(530, 250);
                        QLabel* labelWin = new QLabel(this);
                        labelWin->setGeometry((this->width() - pixWin.width()) * 0.5,
                                             40 + (this->height() - pixWin.height()) * 0.5,
                                            pixWin.width(), pixWin.height());
                        labelWin->setPixmap(pixWin);
                        QTimer::singleShot(150, this, [=]()
                                           {labelWin->show();});
                    }
                });
            });
        }
    }
}

void PlayScene::paintEvent(QPaintEvent* )
{
    //加载背景
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/PlayLevelSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);
    //加载标题
    pix.load(":/image/Title.png");
    painter.drawPixmap(0, 40, pix.width(), pix.height(), pix);
}

