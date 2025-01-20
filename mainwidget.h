#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

class mrzTitleBarWidget;
class MrzOnlineExamWidget;
class MrzOnlineExerciseWidget;
class MrzPersonalCenterWidget;
class QStackedWidget;

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private:
    void initUi();
    void connectFun();

private slots:
    void turnPages(QString onlineStatus);

private:
    mrzTitleBarWidget *m_pMrzTitleBarWidget;
    MrzOnlineExamWidget *m_pMrzOnlineExamWidget;
    MrzOnlineExerciseWidget *m_pMrzOnlineExerciseWidget;
    MrzPersonalCenterWidget *m_pMrzPersonalCenterWidget;

    QStackedWidget *m_pStackedWidget;

};
#endif // MAINWIDGET_H
