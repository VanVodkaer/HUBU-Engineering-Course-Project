#ifndef STARTBUTTON_H
#define STARTBUTTON_H

#include <QPushButton>
#include<QMouseEvent>
class StartButton : public QPushButton
{
    Q_OBJECT
public:
    //explicit StartButton(QWidget *parent = nullptr);
    // 参数1正常显示的
    explicit StartButton(QString normalImg, QString pressImg = "");
    QString normalImgPath;
    QString pressImgPath;
    //添加弹跳特效的代码
    void zoomUnder();  // 向下
    void zoomUp();    // 向上
    //按钮按下释放事件
    void mousePressEvent(QMouseEvent* e);
    void mouseReleaseEvent(QMouseEvent* e);
signals:
};

#endif // STARTBUTTON_H
