#include "mrzexampapertitlewidget.h"

#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>

const QString styleButton = QString("QPushButton{"
                                    "line-height: 26px;"
                                    "border-radius: 20px;"
                                    "background-color: rgba(255,255,255,1);"
                                    "color: rgba(233,157,66,1);"
                                    "font-size: 18px;"
                                    "text-align: center;"
                                    "font-family: -regular;"
                                    "border: 1px solid rgba(56,148,255,1);}");

const QString styleTitleLbl = QString("QLabel{"
                                      "line-height: 29px;"
                                      "color: rgba(255,255,255,1);"
                                      "font-size: 20px;"
                                      "text-align: left;"
                                      "font-family: SourceHanSansSC-regular;}");

const QString styleTimeLbl = QString("QLabel{"
                                      "line-height: 40px;"
                                      "color: rgb(255,255,255);"
                                      "font-size: 28px;"
                                      "text-align: left;"
                                      "font-family: SourceHanSansSC-regular;}");

MrzExamPaperTitleWidget::MrzExamPaperTitleWidget(QWidget *parent)
    : QWidget{parent}
{
    initUi();
}

void MrzExamPaperTitleWidget::initUi()
{
    QHBoxLayout *pMainLyt = new QHBoxLayout(this);
    pMainLyt->setContentsMargins(0, 0, 0, 0);

    QWidget *pMainWgt = new QWidget(this);
    pMainWgt->setStyleSheet("QWidget{background-color: rgba(57,126,253,1);}");
    QHBoxLayout *pTitleLyt = new QHBoxLayout(pMainWgt);

    m_pTitleLbl = new QLabel;
    m_pTitleLbl->setText("考题名称考题名称考题");
    m_pTitleLbl->setStyleSheet(styleTitleLbl);

    //QHBoxLayout *pTimeLyt = new QHBoxLayout;
    QLabel *pTimeImg = new QLabel;
    pTimeImg->setFixedSize(40, 40);
    pTimeImg->setStyleSheet("QLabel{border-image: url(:/image/icon/time_image.png);}");

    m_pTimeLbl = new QLabel;
    m_pTimeLbl->setText("87：20");
    m_pTimeLbl->setStyleSheet(styleTimeLbl);

    m_pSubmitExamBtn = new QPushButton;
    m_pSubmitExamBtn->setFixedSize(130, 40);
    m_pSubmitExamBtn->setText("交卷");
    m_pSubmitExamBtn->setStyleSheet(styleButton);

    pTitleLyt->addSpacing(30);
    pTitleLyt->addWidget(m_pTitleLbl);
    pTitleLyt->addStretch();
    pTitleLyt->addWidget(pTimeImg);
    pTitleLyt->addWidget(m_pTimeLbl);
    pTitleLyt->addStretch();
    pTitleLyt->addWidget(m_pSubmitExamBtn);
    pTitleLyt->addSpacing(30);

    pMainLyt->addWidget(pMainWgt);
}
