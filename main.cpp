#include "mainwidget.h"
#include <QApplication>
#include "Model/DataStorage/mrzsqldatastorage.h"
#include "View/LoginWidgets/mrzlogindialog.h"

#ifdef WIN32
#else
#endif

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MrzSqlDataStorage::instance()->createDatabase();

    MrzLoginDialog loginDialog;
    int res = loginDialog.exec();
    if(res == QDialog::Accepted)
    {
        MainWidget *mainWidget = new MainWidget;
        mainWidget->setWindowIcon(QIcon(""));
        mainWidget->show();
    }
    else
    {
        return 0;
    }

    return a.exec();
}
