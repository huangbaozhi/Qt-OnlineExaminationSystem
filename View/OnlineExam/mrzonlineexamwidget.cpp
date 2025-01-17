#include "mrzonlineexamwidget.h"
#include "View/OnlineExam/mrzmygamwidget.h"
#include "View/OnlineExam/mrzmygametitlebar.h"
#include "View/OnlineExam/mrzfacerecognitiondialog.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QDateTime>
#include <QScrollArea>

MrzOnlineExamWidget::MrzOnlineExamWidget(QWidget *parent)
    : QWidget{parent}
{
    setMinimumSize(1250, 964);
    initUi();
    connectFun();
}

static MrzOnlineExamWidget *G_MrzOnlineExamWidget = nullptr;
MrzOnlineExamWidget *MrzOnlineExamWidget::instance()
{
    if (!G_MrzOnlineExamWidget)
    {
        G_MrzOnlineExamWidget = new MrzOnlineExamWidget();
    }
    return G_MrzOnlineExamWidget;
}

void MrzOnlineExamWidget::initUi()
{
    QWidget *pMainWgt = new QWidget(this);
    QVBoxLayout *pMainLyt = new QVBoxLayout(pMainWgt);
    pMainLyt->setContentsMargins(0, 0, 0, 0);

    // 我的大赛
    m_pMyGame = new MrzMyGameTitleBar;
    m_pMyGame->setTitleBackGround("QWidget{border-image: url(:/image/icon/backgroud_mygame.png);background: transparent;}");
    m_pMyGame->setTitleName("我的大赛");
    pMainLyt->addWidget(m_pMyGame);

    QHBoxLayout *pMyGameLyt = new QHBoxLayout();
    pMyGameLyt->setContentsMargins(0, 0, 0, 0);

    for (int i = 0; i < 4; ++i)
    {
        m_pMrzMyGame[i] = new MrzMyGameWidget;
        m_pMrzMyGame[i]->setExamTitleName(QString("考试名称: %1").arg(i));
        pMyGameLyt->addWidget(m_pMrzMyGame[i]);
    }

    pMainLyt->addSpacing(25);
    pMainLyt->addLayout(pMyGameLyt);
    pMainLyt->addSpacing(20);


    // 我的考试
    m_pMyExam = new MrzMyGameTitleBar;
    m_pMyExam->setTitleBackGround("QWidget{border-image: url(:/image/icon/backgroud_my_exam.png);background: transparent;}");
    m_pMyExam->setTitleName("我的考试");
    pMainLyt->addWidget(m_pMyExam);

    QHBoxLayout *pMyExamLyt = new QHBoxLayout();
    pMyExamLyt->setContentsMargins(0, 0, 0, 0);

    for (int i = 0; i < 4; ++i)
    {
        m_pMrzMyExam[i] = new MrzMyGameWidget;
        m_pMrzMyExam[i]->setExamTitleName(QString("考试名称: %1").arg(i));
        pMyExamLyt->addWidget(m_pMrzMyExam[i]);
    }
    //pMyExamLyt->addStretch();

    pMainLyt->addLayout(pMyExamLyt);
    pMainLyt->addSpacing(20);

    // 我的练习
    m_pMyExercise = new MrzMyGameTitleBar;
    m_pMyExercise->setTitleBackGround("QWidget{border-image: url(:/image/icon/backgroud_my_exercise.png);background: transparent;}");
    m_pMyExercise->setTitleName("我的练习");
    pMainLyt->addWidget(m_pMyExercise);

    QHBoxLayout *pMyExerciseLyt = new QHBoxLayout();
    pMyExerciseLyt->setContentsMargins(0, 0, 0, 0);

    for (int i = 0; i < 4; ++i)
    {
        m_pMrzMyExercise[i] = new MrzMyGameWidget;
        m_pMrzMyExercise[i]->setExamTitleName(QString("考试名称: %1").arg(i));
        pMyExerciseLyt->addWidget(m_pMrzMyExercise[i]);
    }
    //pMyExerciseLyt->addStretch();
    pMainLyt->addLayout(pMyExerciseLyt);
    pMainLyt->addSpacing(25);


    // 使用 QScrollArea 包装内容区域
    QHBoxLayout *pScrollLyt = new QHBoxLayout(this);
    pScrollLyt->setContentsMargins(0, 0, 0, 0);
    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setStyleSheet("QScrollArea{border: none;}");
    scrollArea->setMinimumWidth(1250);
    scrollArea->setWidget(pMainWgt);
    //scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn); // 始终显示垂直滚动条
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // 始终显示垂直滚动条
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // 隐藏水平滚动条

    pScrollLyt->addStretch();
    pScrollLyt->addWidget(scrollArea);
    pScrollLyt->addStretch();
}

void MrzOnlineExamWidget::connectFun()
{
    connect(m_pMrzMyGame[0], &MrzMyGameWidget::signEnterExaminationRoom, this, &MrzOnlineExamWidget::slotFaceRecognition);
}

void MrzOnlineExamWidget::slotFaceRecognition()
{
    MrzFaceRecognitionDialog faceRecognitionDialog;
    faceRecognitionDialog.exec();
}
