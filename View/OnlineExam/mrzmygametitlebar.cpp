#include "mrzmygametitlebar.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

const QString styleLabel = QString("QLabel{line-height: 29px;"
                                   "color: rgba(255,255,255,1);"
                                    "font-size: 20px;"
                                    "text-align: left;"
                                    "font-family: SourceHanSansSC-regular;}");

const QString styleButton = QString("QPushButton{"
                                    "line-height: 24px;"
                                    "color: rgb(16,16,16);"
                                    "font-size: 16px;"
                                    "text-align: left;"
                                    "border:0px groove gray;"
                                    "font-family: SourceHanSansSC-bold;}");

MrzMyGameTitleBar::MrzMyGameTitleBar(QWidget *parent)
    : QWidget{parent}
{
    this->setMinimumWidth(1200);
    this->setFixedHeight(60);

    initUi();
}


void MrzMyGameTitleBar::initUi()
{
    QHBoxLayout *pTitleLyt = new QHBoxLayout(this);
    pTitleLyt->setContentsMargins(0, 0, 0, 0);

    m_pBackgroundWgt = new QWidget;
    m_pBackgroundWgt->setFixedHeight(60);
    m_pBackgroundWgt->setStyleSheet("QWidget{border-image: url(:/image/icon/backgroud_mygame.png);background: transparent;}");

    QHBoxLayout *pBackGroundLyt = new QHBoxLayout(m_pBackgroundWgt);
    pBackGroundLyt->setContentsMargins(0, 0, 0, 0);

    m_pLogoLbl = new QLabel(this);
    m_pLogoLbl->setFixedSize(30, 30);
    m_pLogoLbl->setStyleSheet("QLabel{border-image: url(:/image/icon/trophy.png);}");

    m_pTitleLbl = new QLabel;
    m_pTitleLbl->setStyleSheet(styleLabel);

    pBackGroundLyt->addStretch();
    pBackGroundLyt->addWidget(m_pLogoLbl);
    pBackGroundLyt->addSpacing(19);
    pBackGroundLyt->addWidget(m_pTitleLbl);
    pBackGroundLyt->addStretch();

    m_pUnderWayBtn = new QPushButton(this);
    m_pUnderWayBtn->setText("进行中");
    m_pUnderWayBtn->setStyleSheet(styleButton);
    m_pUnderWayBtn->setFixedSize(48, 60);

    m_pNotFoundBtn = new QPushButton(this);
    m_pNotFoundBtn->setText("未发现");
    m_pNotFoundBtn->setStyleSheet(styleButton);
    m_pNotFoundBtn->setFixedSize(48, 60);

    m_pSigningUpBtn = new QPushButton(this);
    m_pSigningUpBtn->setText("报名中");
    m_pSigningUpBtn->setStyleSheet(styleButton);
    m_pSigningUpBtn->setFixedSize(48, 60);

    m_pAlreadyRegisteredBtn = new QPushButton(this);
    m_pAlreadyRegisteredBtn->setText("已报名");
    m_pAlreadyRegisteredBtn->setStyleSheet(styleButton);
    m_pAlreadyRegisteredBtn->setFixedSize(48, 60);

    m_pNotYetStartedBtn = new QPushButton(this);
    m_pNotYetStartedBtn->setText("未开始");
    m_pNotYetStartedBtn->setStyleSheet(styleButton);
    m_pNotYetStartedBtn->setFixedSize(48, 60);

    m_pDuringTheExamBtn = new QPushButton(this);
    m_pDuringTheExamBtn->setText("考试中");
    m_pDuringTheExamBtn->setStyleSheet(styleButton);
    m_pDuringTheExamBtn->setFixedSize(48, 60);

    m_pCompletedBtn = new QPushButton(this);
    m_pCompletedBtn->setText("已完成");
    m_pCompletedBtn->setStyleSheet(styleButton);
    m_pCompletedBtn->setFixedSize(48, 60);

    m_pAlreadyEndedBtn = new QPushButton(this);
    m_pAlreadyEndedBtn->setText("已结束");
    m_pAlreadyEndedBtn->setStyleSheet(styleButton);
    m_pAlreadyEndedBtn->setFixedSize(48, 60);

    //pTitleLyt->addWidget(m_pTitleLbl);
    pTitleLyt->addWidget(m_pBackgroundWgt);
    pTitleLyt->addSpacing(45);
    pTitleLyt->addWidget(m_pUnderWayBtn);
    pTitleLyt->addSpacing(30);
    pTitleLyt->addWidget(m_pNotFoundBtn);
    pTitleLyt->addSpacing(30);
    pTitleLyt->addWidget(m_pSigningUpBtn);
    pTitleLyt->addSpacing(30);
    pTitleLyt->addWidget(m_pAlreadyRegisteredBtn);
    pTitleLyt->addSpacing(30);
    pTitleLyt->addWidget(m_pNotYetStartedBtn);
    pTitleLyt->addSpacing(30);
    pTitleLyt->addWidget(m_pDuringTheExamBtn);
    pTitleLyt->addSpacing(30);
    pTitleLyt->addWidget(m_pCompletedBtn);
    pTitleLyt->addSpacing(30);
    pTitleLyt->addWidget(m_pAlreadyEndedBtn);
    pTitleLyt->addStretch();
}

void MrzMyGameTitleBar::setTitleBackGround(QString background)
{
    m_pBackgroundWgt->setStyleSheet(background);
}

void MrzMyGameTitleBar::setTitleName(QString title)
{
    m_pTitleLbl->setText(title);
}
