#ifndef CHOOSESCENE_H
#define CHOOSESCENE_H

#include <QMainWindow>
#include"playscene.h"
class ChooseScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseScene(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    //创建游戏场景
    PlayScene* play = NULL;
signals:
    void chooseback();
};

#endif // CHOOSESCENE_H
