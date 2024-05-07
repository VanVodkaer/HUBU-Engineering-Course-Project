#include "coinscene.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CoinScene w;
    w.show();
    return a.exec();
}
