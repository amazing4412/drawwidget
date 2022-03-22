#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator qtTranslator;
    qtTranslator.load("qt_zh_CN.qm","./");
    a.installTranslator(&qtTranslator);

    QTranslator Qtbase;
    Qtbase.load("qtbase_zh_CN.qm");
        a.installTranslator(&Qtbase);


    QFont font("chenjie",12);
    a.setFont(font);
    MainWindow w;
    w.show();

    return a.exec();
}
