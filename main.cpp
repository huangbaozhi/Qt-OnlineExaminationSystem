#include "mainwidget.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QDateTime>

class CustomWidget : public QWidget {
public:
    explicit CustomWidget(const QString &title, const QDateTime &startTime, const QDateTime &endTime, int duration, int questions, int score, QWidget *parent = nullptr)
        : QWidget(parent) {
        QVBoxLayout *layout = new QVBoxLayout(this);

        // Title
        QLabel *titleLabel = new QLabel(title, this);
        titleLabel->setAlignment(Qt::AlignCenter);
        layout->addWidget(titleLabel);

        // Information
        QLabel *infoLabel = new QLabel(
            QString("开始时间: %1\n结束时间: %2\n考试时长: %3分钟\n题数: %4\n满分: %5")
                .arg(startTime.toString("yyyy-MM-dd HH:mm"))
                .arg(endTime.toString("yyyy-MM-dd HH:mm"))
                .arg(duration)
                .arg(questions)
                .arg(score),
            this);
        layout->addWidget(infoLabel);

        // Button
        QPushButton *enterButton = new QPushButton("进入考场", this);
        layout->addWidget(enterButton);
    }
};


#include <QApplication>

int main(int argc, char *argv[])
{

    // 启用高DPI支持
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    // QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    // QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);

    // QCoreApplication::setAttribute(Qt::AA_DisableHighDpiScaling, true);

    QApplication a(argc, argv);
    MainWidget w;
    w.show();


    // Main window
    // QWidget mainWindow;
    // mainWindow.setWindowTitle("考试界面");
    // QGridLayout *mainLayout = new QGridLayout(&mainWindow);

    // // Create multiple widgets
    // for (int i = 0; i < 6; ++i) {
    //     QString title = QString("考试名称 %1").arg(i + 1);
    //     QDateTime startTime = QDateTime::currentDateTime().addDays(i);
    //     QDateTime endTime = startTime.addSecs(90 * 60);
    //     int duration = 90;
    //     int questions = 20;
    //     int score = 100;

    //     CustomWidget *widget = new CustomWidget(title, startTime, endTime, duration, questions, score);
    //     mainLayout->addWidget(widget, i / 2, i % 2); // 2 columns
    // }

    // mainWindow.show();

    return a.exec();
}
