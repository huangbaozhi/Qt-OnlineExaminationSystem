#include "mrzmygamwidget.h"
#include "View/OnlineExam/mrzexaminationwidget.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QDateTime>

const QString styleLogo = QString("QLabel{"
                                   "line-height: 23px;"
                                   "color: rgba(255,255,255,1);"
                                   "font-size: 16px;"
                                   "text-align: center;"
                                   "font-family: SourceHanSansSC-regular;"
                                   "border: 1px solid rgba(119,40,245,1);"
                                   "background-color: #7728F5;"
                                   "border-image: url(:/image/icon/exam.png);"
                                   "}");

const QString styleTitle = QString("QLabel{"
                                    "line-height: 24px;"
                                    "color: rgba(58,62,81,1);"
                                    "font-size: 16px;"
                                    "text-align: left;"
                                    "border:0px groove gray;"
                                    "font-family: SourceHanSansSC-regular;}");

const QString styleTime = QString("QLabel{"
                                   "line-height: 20px;"
                                   "color: rgb(109,113,124);"
                                   "font-size: 14px;"
                                   "text-align: left;"
                                   "border:0px groove gray;"
                                   "font-family: SourceHanSansSC-regular;}");

const QString styleButton = QString("QPushButton{"
                                    "line-height: 23px;"
                                    "border-radius: 3px;"
                                    "background-color: rgba(56,148,255,1);"
                                    "color: rgba(255, 255, 255, 1);"
                                    "font-size: 16px;"
                                    "text-align: center;"
                                    "border:0px groove gray;"
                                    "font-family: -regular;}");

MrzMyGameWidget::MrzMyGameWidget(QWidget *parent)
    : QWidget{parent}
{
    this->setFixedSize(290, 538);
    initUi();

    connectFun();
}

MrzMyGameWidget::MrzMyGameWidget(const QString &title,
                                 const QDateTime &startTime,
                                 const QDateTime &endTime,
                                 int duration,
                                 int questions,
                                 int score,
                                 QWidget *parent)
   : QWidget{parent}
{
    initUi(title, startTime, endTime, duration, questions, score);
}

void MrzMyGameWidget::initUi()
{
    QHBoxLayout *pMyGameButtonLyt = new QHBoxLayout(this);
    pMyGameButtonLyt->setContentsMargins(0, 0, 0, 0);

    QWidget *pMainWgt = new QWidget;
    pMyGameButtonLyt->addWidget(pMainWgt);
    pMainWgt->setFixedSize(290, 538);
    pMainWgt->setStyleSheet("QWidget{"
                            "line-height: 20px;"
                            "background-color: rgba(255,255,255,1);"
                            "color: rgba(16,16,16,1);"
                            "font-size: 14px;"
                            "text-align: center;"
                            "}");

    QVBoxLayout *pMainLyt = new QVBoxLayout(pMainWgt);
    pMainLyt->setContentsMargins(0, 0, 0, 0);

    QWidget *pImageWgt = new QWidget();
    pImageWgt->setStyleSheet("QWidget{border-image: url(:/image/icon/megagame.png);background: transparent;}");
    pImageWgt->setFixedSize(290, 196);
    QVBoxLayout *pImageVlyt = new QVBoxLayout(pImageWgt);
    pImageVlyt->setContentsMargins(0, 0, 0, 0);
    QHBoxLayout *pImageLyt = new QHBoxLayout;
    pImageLyt->setContentsMargins(0, 0, 0, 0);
    m_pLogoLbl = new QLabel;
    //m_pLogoLbl->setText("考试中");
    m_pLogoLbl->setAutoFillBackground(true);
    m_pLogoLbl->setStyleSheet(styleLogo);
    m_pLogoLbl->setFixedSize(60, 24);
    pImageLyt->addStretch();
    pImageLyt->addWidget(m_pLogoLbl);
    pImageVlyt->addLayout(pImageLyt);
    pImageVlyt->addStretch();

    QVBoxLayout *pVLyt = new QVBoxLayout;
    pVLyt->setContentsMargins(0, 0, 0, 0);

    QHBoxLayout *pTitleLyt = new QHBoxLayout;
    pTitleLyt->setContentsMargins(0, 0, 0, 0);
    m_pTitleLbl = new QLabel(this);
    m_pTitleLbl->setText("考试名称考试名称考试名称考试名称\n考试名称考试名称考试名称考试名称\n考试名称考试名称考试名称考试名称");
    m_pTitleLbl->setStyleSheet(styleTitle);
    m_pTitleLbl->setFixedSize(250, 72);
    pTitleLyt->addSpacing(20);
    pTitleLyt->addWidget(m_pTitleLbl);
    pTitleLyt->addSpacing(20);

    QHBoxLayout *pStartTimeLyt = new QHBoxLayout;
    pStartTimeLyt->setContentsMargins(0, 0, 0, 0);
    QLabel *pStartTimeLbl = new QLabel;
    pStartTimeLbl->setText("开始时间: ");
    pStartTimeLbl->setStyleSheet(styleTime);
    m_pStartTimeLbl = new QLabel();
    m_pStartTimeLbl->setText("2022-07-27 08:30");
    m_pStartTimeLbl->setStyleSheet(styleTime);
    pStartTimeLyt->addSpacing(20);
    pStartTimeLyt->addWidget(pStartTimeLbl);
    pStartTimeLyt->addWidget(m_pStartTimeLbl);
    pStartTimeLyt->addStretch();


    QHBoxLayout *pEndTimeLyt = new QHBoxLayout;
    pEndTimeLyt->setContentsMargins(0, 0, 0, 0);
    QLabel *pEndTimeLbl = new QLabel;
    pEndTimeLbl->setText("结束时间: ");
    pEndTimeLbl->setStyleSheet(styleTime);
    m_pEndTimeLbl = new QLabel();
    m_pEndTimeLbl->setText("2022-07-27 11:30");
    m_pEndTimeLbl->setStyleSheet(styleTime);
    pEndTimeLyt->addSpacing(20);
    pEndTimeLyt->addWidget(pEndTimeLbl);
    pEndTimeLyt->addWidget(m_pEndTimeLbl);
    pEndTimeLyt->addStretch();

    QHBoxLayout *pExamTimeLyt = new QHBoxLayout;
    pExamTimeLyt->setContentsMargins(0, 0, 0, 0);
    QLabel *pExamTimeLbl = new QLabel;
    pExamTimeLbl->setText("考试时长: ");
    pExamTimeLbl->setStyleSheet(styleTime);
    m_pExamTimeLbl = new QLabel();
    m_pExamTimeLbl->setText("90分钟");
    m_pExamTimeLbl->setStyleSheet(styleTime);
    pExamTimeLyt->addSpacing(20);
    pExamTimeLyt->addWidget(pExamTimeLbl);
    pExamTimeLyt->addWidget(m_pExamTimeLbl);
    pExamTimeLyt->addStretch();

    QHBoxLayout *pProblemNumLyt = new QHBoxLayout;
    pProblemNumLyt->setContentsMargins(0, 0, 0, 0);
    QLabel *pProblemNumLbl = new QLabel;
    pProblemNumLbl->setText("题数: ");
    pProblemNumLbl->setStyleSheet(styleTime);
    m_pProblemNumLbl = new QLabel();
    m_pProblemNumLbl->setText("20");
    m_pProblemNumLbl->setStyleSheet(styleTime);
    pProblemNumLyt->addSpacing(20);
    pProblemNumLyt->addWidget(pProblemNumLbl);
    pProblemNumLyt->addWidget(m_pProblemNumLbl);
    pProblemNumLyt->addStretch();

    QHBoxLayout *pMarkLyt = new QHBoxLayout;
    pMarkLyt->setContentsMargins(0, 0, 0, 0);
    QLabel *pMarkLbl = new QLabel;
    pMarkLbl->setText("满分: ");
    pMarkLbl->setStyleSheet(styleTime);
    m_pMarkLbl = new QLabel();
    m_pMarkLbl->setText("100分");
    m_pMarkLbl->setStyleSheet(styleTime);
    pMarkLyt->addSpacing(20);
    pMarkLyt->addWidget(pMarkLbl);
    pMarkLyt->addWidget(m_pMarkLbl);
    pMarkLyt->addStretch();

    QHBoxLayout *pBtnLyt = new QHBoxLayout;
    pBtnLyt->setContentsMargins(0, 0, 0, 0);
    m_pButton = new QPushButton;
    m_pButton->setText("进入考场");
    m_pButton->setFixedSize(120, 40);
    m_pButton->setStyleSheet(styleButton);
    pBtnLyt->addStretch();
    pBtnLyt->addSpacing(150);
    pBtnLyt->addWidget(m_pButton);
    pBtnLyt->addSpacing(20);
    pBtnLyt->addStretch();

    pVLyt->addLayout(pTitleLyt);
    pVLyt->addStretch();
    pVLyt->addSpacing(15);
    pVLyt->addLayout(pStartTimeLyt);
    pVLyt->addSpacing(15);
    pVLyt->addLayout(pEndTimeLyt);
    pVLyt->addSpacing(15);
    pVLyt->addLayout(pExamTimeLyt);
    pVLyt->addSpacing(15);
    pVLyt->addLayout(pProblemNumLyt);
    pVLyt->addSpacing(15);
    pVLyt->addLayout(pMarkLyt);
    pVLyt->addSpacing(15);
    pVLyt->addLayout(pBtnLyt);
    pVLyt->addSpacing(20);
    pBtnLyt->addStretch();

    pMainLyt->addWidget(pImageWgt);
    pMainLyt->addLayout(pVLyt);
}

void MrzMyGameWidget::initUi(const QString &title, const QDateTime &startTime, const QDateTime &endTime, int duration, int questions, int score)
{
    QHBoxLayout *pMyGameButtonLyt = new QHBoxLayout(this);
    pMyGameButtonLyt->setContentsMargins(0, 0, 0, 0);

    QWidget *pMainWgt = new QWidget;
    pMyGameButtonLyt->addWidget(pMainWgt);
    pMainWgt->setFixedSize(290, 538);
    pMainWgt->setStyleSheet("QWidget{"
                            "line-height: 20px;"
                            "background-color: rgba(255,255,255,1);"
                            "color: rgba(16,16,16,1);"
                            "font-size: 14px;"
                            "text-align: center;"
                            "}");

    QVBoxLayout *pMainLyt = new QVBoxLayout(pMainWgt);
    pMainLyt->setContentsMargins(0, 0, 0, 0);

    QWidget *pImageWgt = new QWidget();
    pImageWgt->setStyleSheet("QWidget{border-image: url(:/image/11.jpg);background: transparent;}");
    pImageWgt->setFixedSize(290, 196);
    QVBoxLayout *pImageVlyt = new QVBoxLayout(pImageWgt);
    pImageVlyt->setContentsMargins(0, 0, 0, 0);
    QHBoxLayout *pImageLyt = new QHBoxLayout;
    pImageLyt->setContentsMargins(0, 0, 0, 0);
    m_pLogoLbl = new QLabel;
    m_pLogoLbl->setText("考试中");
    m_pLogoLbl->setAutoFillBackground(true);
    m_pLogoLbl->setStyleSheet(styleLogo);
    m_pLogoLbl->setFixedSize(60, 24);
    pImageLyt->addStretch();
    pImageLyt->addWidget(m_pLogoLbl);
    pImageVlyt->addLayout(pImageLyt);
    pImageVlyt->addStretch();

    QVBoxLayout *pVLyt = new QVBoxLayout;
    pVLyt->setContentsMargins(0, 0, 0, 0);

    QHBoxLayout *pTitleLyt = new QHBoxLayout;
    pTitleLyt->setContentsMargins(0, 0, 0, 0);
    m_pTitleLbl = new QLabel(this);
    m_pTitleLbl->setText("考试名称考试名称考试名称考试名称\n考试名称考试名称考试名称考试名称\n考试名称考试名称考试名称考试名称");
    m_pTitleLbl->setStyleSheet(styleTitle);
    m_pTitleLbl->setFixedSize(250, 72);
    pTitleLyt->addSpacing(20);
    pTitleLyt->addWidget(m_pTitleLbl);
    pTitleLyt->addSpacing(20);

    QHBoxLayout *pStartTimeLyt = new QHBoxLayout;
    pStartTimeLyt->setContentsMargins(0, 0, 0, 0);
    QLabel *pStartTimeLbl = new QLabel;
    pStartTimeLbl->setText("开始时间: ");
    pStartTimeLbl->setStyleSheet(styleTime);
    m_pStartTimeLbl = new QLabel();
    m_pStartTimeLbl->setText("2022-07-27 08:30");
    m_pStartTimeLbl->setStyleSheet(styleTime);
    pStartTimeLyt->addSpacing(20);
    pStartTimeLyt->addWidget(pStartTimeLbl);
    pStartTimeLyt->addWidget(m_pStartTimeLbl);
    pStartTimeLyt->addStretch();


    QHBoxLayout *pEndTimeLyt = new QHBoxLayout;
    pEndTimeLyt->setContentsMargins(0, 0, 0, 0);
    QLabel *pEndTimeLbl = new QLabel;
    pEndTimeLbl->setText("结束时间: ");
    pEndTimeLbl->setStyleSheet(styleTime);
    m_pEndTimeLbl = new QLabel();
    m_pEndTimeLbl->setText("2022-07-27 11:30");
    m_pEndTimeLbl->setStyleSheet(styleTime);
    pEndTimeLyt->addSpacing(20);
    pEndTimeLyt->addWidget(pEndTimeLbl);
    pEndTimeLyt->addWidget(m_pEndTimeLbl);
    pEndTimeLyt->addStretch();

    QHBoxLayout *pExamTimeLyt = new QHBoxLayout;
    pExamTimeLyt->setContentsMargins(0, 0, 0, 0);
    QLabel *pExamTimeLbl = new QLabel;
    pExamTimeLbl->setText("考试时长: ");
    pExamTimeLbl->setStyleSheet(styleTime);
    m_pExamTimeLbl = new QLabel();
    m_pExamTimeLbl->setText("90分钟");
    m_pExamTimeLbl->setStyleSheet(styleTime);
    pExamTimeLyt->addSpacing(20);
    pExamTimeLyt->addWidget(pExamTimeLbl);
    pExamTimeLyt->addWidget(m_pExamTimeLbl);
    pExamTimeLyt->addStretch();

    QHBoxLayout *pProblemNumLyt = new QHBoxLayout;
    pProblemNumLyt->setContentsMargins(0, 0, 0, 0);
    QLabel *pProblemNumLbl = new QLabel;
    pProblemNumLbl->setText("题数: ");
    pProblemNumLbl->setStyleSheet(styleTime);
    m_pProblemNumLbl = new QLabel();
    m_pProblemNumLbl->setText("20");
    m_pProblemNumLbl->setStyleSheet(styleTime);
    pProblemNumLyt->addSpacing(20);
    pProblemNumLyt->addWidget(pProblemNumLbl);
    pProblemNumLyt->addWidget(m_pProblemNumLbl);
    pProblemNumLyt->addStretch();

    QHBoxLayout *pMarkLyt = new QHBoxLayout;
    pMarkLyt->setContentsMargins(0, 0, 0, 0);
    QLabel *pMarkLbl = new QLabel;
    pMarkLbl->setText("满分: ");
    pMarkLbl->setStyleSheet(styleTime);
    m_pMarkLbl = new QLabel();
    m_pMarkLbl->setText("100分");
    m_pMarkLbl->setStyleSheet(styleTime);
    pMarkLyt->addSpacing(20);
    pMarkLyt->addWidget(pMarkLbl);
    pMarkLyt->addWidget(m_pMarkLbl);
    pMarkLyt->addStretch();

    QHBoxLayout *pBtnLyt = new QHBoxLayout;
    pBtnLyt->setContentsMargins(0, 0, 0, 0);
    m_pButton = new QPushButton;
    m_pButton->setText("进入考场");
    m_pButton->setFixedSize(120, 40);
    m_pButton->setStyleSheet(styleButton);
    pBtnLyt->addStretch();
    pBtnLyt->addSpacing(150);
    pBtnLyt->addWidget(m_pButton);
    pBtnLyt->addSpacing(20);
    pBtnLyt->addStretch();

    pVLyt->addLayout(pTitleLyt);
    pVLyt->addStretch();
    pVLyt->addSpacing(15);
    pVLyt->addLayout(pStartTimeLyt);
    pVLyt->addSpacing(15);
    pVLyt->addLayout(pEndTimeLyt);
    pVLyt->addSpacing(15);
    pVLyt->addLayout(pExamTimeLyt);
    pVLyt->addSpacing(15);
    pVLyt->addLayout(pProblemNumLyt);
    pVLyt->addSpacing(15);
    pVLyt->addLayout(pMarkLyt);
    pVLyt->addSpacing(15);
    pVLyt->addLayout(pBtnLyt);
    pVLyt->addSpacing(20);
    pBtnLyt->addStretch();

    pMainLyt->addWidget(pImageWgt);
    pMainLyt->addLayout(pVLyt);
}

void MrzMyGameWidget::connectFun()
{
    // 人脸识别
    //connect(m_pButton, &QPushButton::clicked, this, &MrzMyGameWidget::signEnterExaminationRoom);

    // 直接进入考试界面
    connect(m_pButton, &QPushButton::clicked, this, &MrzMyGameWidget::slotExaminationWidget);
}

void MrzMyGameWidget::slotExaminationWidget()
{
    m_pExaminationWidget = new MrzExaminationWidget;
    m_pExaminationWidget->show();
}

void MrzMyGameWidget::setExamTitleName(QString title)
{
    m_pTitleLbl->setText(title);
}

void MrzMyGameWidget::setExamStatus(QString status)
{

}
