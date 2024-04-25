#include "serialassistant.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SerialAssistant w;
    w.setWindowTitle("鱼圆的串口助手");
    w.show();
    return a.exec();
}
