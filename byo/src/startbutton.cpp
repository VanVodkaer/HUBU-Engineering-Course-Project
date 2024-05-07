#include "startbutton.h"
#include<QDebug>
#include<QPropertyAnimation>

StartButton::StartButton(QString normalImg, QString pressImg)
{
    this->normalImgPath = normalImg;
    this->pressImgPath = pressImg;
    QPixmap pix;
    bool ret = pix.load(normalImg);
    //调节start按钮大小
    if(this->normalImgPath == ":/image/MenuSceneStartButton.png")
    {pix = pix.scaled(170, 170);}
    //调节back按键大小
    if(this->normalImgPath == ":/image/BackButton.png")   // 要与下面切换图片的大小相同步
    {pix = pix.scaled(120, 60);}
    //设置关卡按键大小
    if(this->normalImgPath == ":/image/LevelIcon.png")
    {pix = pix.scaled(120, 120);}   // 要与choosescene.cpp中的按键位置同步修改
    if(!ret)
    {
        qDebug() << "图片加载失败! ";
        return;
    }
    this->setFixedSize(pix.width(), pix.height());
    //设置不规则图片
    this->setStyleSheet("QPushButton{border:0px}");
    //设置图标
    this->setIcon(pix);
    //设置图标大小
    this->setIconSize(QSize(pix.width(), pix.height()));
}
void StartButton::zoomUnder()
{
    //创建动态对象
    QPropertyAnimation* animation = new QPropertyAnimation(this, "geometry");
    //设置动画时间间隔
    animation->setDuration(200);
    //起始位置
    animation->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));
    //结束位置
    animation->setEndValue(QRect(this->x(), this->y() + 10, this->width(), this->height()));
    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //执行动画
    animation->start();
}

void StartButton::zoomUp()
{
    //创建动态对象
    QPropertyAnimation* animation = new QPropertyAnimation(this, "geometry");
    //设置动画时间间隔
    animation->setDuration(200);
    //起始位置
    animation->setStartValue(QRect(this->x(), this->y() + 10, this->width(), this->height()));
    //结束位置
    animation->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));
    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //执行动画
    animation->start();
}

void StartButton::mousePressEvent(QMouseEvent* e)
{
    if(this->pressImgPath != "")
    {
        //切换图片
        QPixmap pix;
        bool ret = pix.load(this->pressImgPath);
        //调节back按键大小
        if(this->normalImgPath == ":/image/BackButton.png")
        {pix = pix.scaled(120, 60);}
        if(!ret)
        {
            qDebug() << "图片加载失败! ";
            return;
        }
        this->setFixedSize(pix.width(), pix.height());
        //设置不规则图片
        this->setStyleSheet("QPushButton{border:0px}");
        //设置图标
        this->setIcon(pix);
        //设置图标大小
        this->setIconSize(QSize(pix.width(), pix.height()));
    }
    //剩下的交给父类执行
    return QPushButton::mousePressEvent(e);
}
void StartButton::mouseReleaseEvent(QMouseEvent* e)
{
    if(this->pressImgPath != "")
    {
        //切换图片
        QPixmap pix;
        bool ret = pix.load(this->normalImgPath);
        //调节back按键大小
        if(this->normalImgPath == ":/image/BackButton.png")
        {pix = pix.scaled(120, 60);}
        if(!ret)
        {
            qDebug() << "图片加载失败! ";
            return;
        }
        this->setFixedSize(pix.width(), pix.height());
        //设置不规则图片
        this->setStyleSheet("QPushButton{border:0px}");
        //设置图标
        this->setIcon(pix);
        //设置图标大小
        this->setIconSize(QSize(pix.width(), pix.height()));
    }
    //剩下的交给父类执行
    return QPushButton::mouseReleaseEvent(e);
}
