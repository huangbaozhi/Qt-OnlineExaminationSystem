#include "mainwidget.h"
#include <QApplication>

#ifdef WIN32
#else
#endif

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget w;
    w.show();
    return a.exec();
}
