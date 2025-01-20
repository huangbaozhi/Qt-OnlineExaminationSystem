#include "mrztitlebar.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QDebug>

const QString styleLabel = QString("QLabel{line-height: 40px;"
                                   "color: rgb(255,255,255);"
                                   "font-size: 28px;"
                                   "text-align: left;"
                                   "font-family: SourceHanSansSC-regular;}"
                                   );

const QString styleButton = QString("QPushButton{"
                                    "line-height: 24px;"
                                    "color: rgba(255,255,255,1);"
                                    "font-size: 16px;"
                                    "text-align: left;"
                                    "border:0px groove gray;"
                                    "font-family: SourceHanSansSC-regular;"
                                    "}"
                                    "QPushButton:checked{"
                                    "border-image: url(:/image/button/online_button.png);"
                                    "}"
                                    "QPushButton:unchecked {"
                                    "background-color: lightgray;"   // 未选中状态时的背景色
                                    "border: 2px solid gray;"        // 未选中状态时的边框
                                    "color: black;"                  // 未选中状态时的文字颜色
                                    "}"
                                    );

mrzTitleBarWidget::mrzTitleBarWidget(QWidget *parent)
    : QWidget{parent}
{
    setMinimumSize(1440, 60);


    initUi();
    connectFun();
}

void mrzTitleBarWidget::initUi()
{
    QHBoxLayout *pMainLyt = new QHBoxLayout(this);
    pMainLyt->setContentsMargins(0, 0, 0, 0);

    QWidget *pMainWgt = new QWidget();
    pMainWgt->setStyleSheet("QWidget{background-color: rgba(57,126,253,1);}");
    pMainLyt->addWidget(pMainWgt);

    QHBoxLayout *phLyt = new QHBoxLayout(pMainWgt);
    phLyt->setContentsMargins(95, 0, 95, 0);

    m_pLogoLbl = new QLabel(this);
    m_pLogoLbl->setFixedSize(60, 60);
    m_pLogoLbl->setStyleSheet("QLabel{border-image: url(:/image/LOGO.png);}");

    m_pTitleLbl = new QLabel(this);
    m_pTitleLbl->setText("木知考试系统");
    m_pTitleLbl->setFixedHeight(60);
    m_pTitleLbl->setStyleSheet(styleLabel);

    m_pOnlineExamBtn = new QPushButton(this);
    m_pOnlineExamBtn->setObjectName("OnlineExam Button");
    m_pOnlineExamBtn->setText("在线考试");
    m_pOnlineExamBtn->setFixedHeight(60);
    m_pOnlineExamBtn->setStyleSheet(styleButton);

    m_pExerciseOnlineBtn = new QPushButton(this);
    m_pExerciseOnlineBtn->setObjectName("OnlineExercise Button");
    m_pExerciseOnlineBtn->setText("在线练习");
    m_pExerciseOnlineBtn->setFixedHeight(60);
    m_pExerciseOnlineBtn->setStyleSheet(styleButton);

    m_pPersonCenterBtn = new QPushButton(this);
    m_pPersonCenterBtn->setObjectName("PersonCenter Button");
    m_pPersonCenterBtn->setStyleSheet("QPushButton{border-image: url(:/image/LOGO.png);border:0px groove gray;}");
    m_pPersonCenterBtn->setFixedSize(60, 60);

    phLyt->addWidget(m_pLogoLbl);
    phLyt->addSpacing(24);
    phLyt->addWidget(m_pTitleLbl);
    phLyt->addSpacing(60);
    phLyt->addWidget(m_pOnlineExamBtn);
    phLyt->addSpacing(40);
    phLyt->addWidget(m_pExerciseOnlineBtn);
    phLyt->addStretch();
    phLyt->addWidget(m_pPersonCenterBtn);

    m_pOnlineExamBtn->setCheckable(true);
    m_pExerciseOnlineBtn->setCheckable(true);
    m_pPersonCenterBtn->setCheckable(true);

    m_pOnlineExamBtn->setChecked(true);
}

void mrzTitleBarWidget::connectFun()
{
    connect(m_pOnlineExamBtn, &QPushButton::toggled, this, &mrzTitleBarWidget::slotOnlineButtonToggled);
    connect(m_pExerciseOnlineBtn, &QPushButton::toggled, this, &mrzTitleBarWidget::slotOnlineButtonToggled);
    connect(m_pPersonCenterBtn, &QPushButton::toggled, this, &mrzTitleBarWidget::slotOnlineButtonToggled);
}

void mrzTitleBarWidget::slotOnlineButtonToggled(bool ckecked)
{
    QPushButton *pBtn = qobject_cast<QPushButton *>(sender());
    if (pBtn)
    {
        if (ckecked)
        {
            if (pBtn->objectName() == "OnlineExam Button")
            {
                m_pExerciseOnlineBtn->setChecked(false);
                m_pPersonCenterBtn->setChecked(false);
                emit signOnlineExam("OnlineExam");
            }
            else if (pBtn->objectName() == "OnlineExercise Button")
            {
                m_pOnlineExamBtn->setChecked(false);
                m_pPersonCenterBtn->setChecked(false);
                emit signOnlineExercise("OnlineExercise");
            }
            else if (pBtn->objectName() == "PersonCenter Button")
            {
                m_pExerciseOnlineBtn->setChecked(false);
                m_pOnlineExamBtn->setChecked(false);
                emit signPersonCenter("PersonCenter");
            }
        }
    }
}
