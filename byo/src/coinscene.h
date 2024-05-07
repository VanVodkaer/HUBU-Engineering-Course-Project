#ifndef COINSCENE_H
#define COINSCENE_H

#include <QMainWindow>
#include"choosescene.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class CoinScene;
}
QT_END_NAMESPACE

class CoinScene : public QMainWindow
{
    Q_OBJECT

public:
    CoinScene(QWidget *parent = nullptr);
    ~CoinScene();
    //开始图片
    void paintEvent(QPaintEvent* );
    //创建
    ChooseScene* chooseScene = NULL;

private:
    Ui::CoinScene *ui;
};
#endif // COINSCENE_H
