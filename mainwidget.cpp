#include "mainwidget.h"
#include "View/mrztitlebar.h"
#include "View/OnlineExam/mrzonlineexamwidget.h"
#include "View/OnlineExercise/mrzonlineexercisewidget.h"

#include <QHBoxLayout>
#include <QBoxLayout>
#include <QScrollArea>
#include <QStackedWidget>
#include <QLabel>
#include <QPushButton>
#include <QStackedWidget>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    setMinimumSize(1440, 1024);
    this->setStyleSheet("background-color: rgba(246,250,255,1);");

    initUi();
    connectFun();
}

MainWidget::~MainWidget()
{

}

void MainWidget::initUi()
{
    QVBoxLayout *pMainLyt = new QVBoxLayout(this);
    pMainLyt->setContentsMargins(0, 0, 0, 0);

    m_pMrzTitleBarWidget = new mrzTitleBarWidget();
    pMainLyt->addWidget(m_pMrzTitleBarWidget);

    m_pMrzOnlineExamWidget = new MrzOnlineExamWidget;
    m_pMrzOnlineExerciseWidget = new MrzOnlineExerciseWidget;

    m_pStackedWidget = new QStackedWidget(this);
    m_pStackedWidget->addWidget(m_pMrzOnlineExamWidget);
    m_pStackedWidget->addWidget(m_pMrzOnlineExerciseWidget);
    m_pStackedWidget->setCurrentWidget(m_pMrzOnlineExamWidget);

    pMainLyt->addWidget(m_pStackedWidget);
}

void MainWidget::connectFun()
{
    connect(m_pMrzTitleBarWidget, &mrzTitleBarWidget::signOnlineExam, this, &MainWidget::turnPages);
    connect(m_pMrzTitleBarWidget, &mrzTitleBarWidget::signOnlineExercise, this, &MainWidget::turnPages);
}

void MainWidget::turnPages(QString onlineStatus)
{
    if (onlineStatus == "OnlineExam" && m_pMrzOnlineExamWidget)
    {
        m_pStackedWidget->setCurrentWidget(m_pMrzOnlineExamWidget);
    }
    else if (onlineStatus== "OnlineExercise" && m_pMrzOnlineExerciseWidget)
    {
        m_pStackedWidget->setCurrentWidget(m_pMrzOnlineExerciseWidget);
    }

}
