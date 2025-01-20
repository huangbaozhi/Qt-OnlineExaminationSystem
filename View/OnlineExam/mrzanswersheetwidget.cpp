#include "mrzanswersheetwidget.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>

const QString styleLabel = QString("QLabel{line-height: 29px;"
                                   "color: rgba(0,123,211,1);"
                                   "border-radius: 0px;"
                                   "font-size: 20px;"
                                   "text-align: left;"
                                   "font-family: SourceHanSansSC-regular;}");

const QString styleNumLabel = QString("QLabel{line-height: 20px;"
                                      "background-color: rgba(242,244,246,1);"
                                      "color: rgb(0,123,211);"
                                      "border-radius: 0px;"
                                      "font-size: 20px;"
                                      "font-family: SourceHanSansSC-regular;}");

const QString styleScheduleLbl = QString("QLabel{line-height: 26px;"
                                          "color: rgba(16,16,16,0.8);"
                                          "font-size: 18px;"
                                          "text-align: left;"
                                          "font-family: SourceHanSansSC-regular;"
                                          "border:none;}");

const QString styleTipLbl = QString("QLabel{line-height: 24px;"
                                         "color: rgba(0,0,0,0.5);"
                                         "font-size: 16px;"
                                         "text-align: left;"
                                         "font-family: SourceHanSansSC-regular;"
                                         "border:none;}");

const QString styleStudenInifLabel = QString("QLabel{line-height: 24px;"
                                   "color: rgba(0,123,211,1);"
                                   "border-radius: 0px;"
                                   "font-size: 16px;"
                                   "text-align: left;"
                                   "font-family: SourceHanSansSC-regular;}");

const QString styleInifLabel = QString("QLabel{line-height: 24px;"
                                             "color: rgba(16,16,16,1);"
                                             "border-radius: 0px;"
                                             "font-size: 16px;"
                                             "text-align: left;"
                                             "font-family: SourceHanSansSC-regular;}");

MrzAnswerSheetWidget::MrzAnswerSheetWidget(QWidget *parent)
    : QWidget{parent}
{
    setMinimumSize(302, 924);
    initUi();
}

void MrzAnswerSheetWidget::initUi()
{
    QVBoxLayout *pMainLyt = new QVBoxLayout(this);
    pMainLyt->setContentsMargins(0, 0, 0, 0);

    QWidget *pAnswerWgt = new QWidget;
    pAnswerWgt->setFixedSize(302, 599);
    pAnswerWgt->setStyleSheet("QWidget{"
                            "line-height: 20px;"
                            "border-radius: 10px;"
                            "background-color: rgba(255,255,255,1);"
                            "color: rgba(16,16,16,1);"
                            "font-size: 14px;"
                            "text-align: center;"
                            "font-family: -regular;"
                            "}");
    QVBoxLayout *pVAnswerLyt = new QVBoxLayout(pAnswerWgt);
    pVAnswerLyt->setContentsMargins(0, 0, 0, 0);

    QHBoxLayout *pHAnswerLyt = new QHBoxLayout;
    QLabel *pAnswerLbl = new QLabel;
    pAnswerLbl->setText("答题卡");
    pAnswerLbl->setStyleSheet(styleLabel);
    pHAnswerLyt->addStretch();
    pHAnswerLyt->addWidget(pAnswerLbl);
    pHAnswerLyt->addStretch();

    pVAnswerLyt->addSpacing(21);
    pVAnswerLyt->addLayout(pHAnswerLyt);
    pVAnswerLyt->addSpacing(21);

    // 题数
    QWidget *pAnswerNumWgt = new QWidget;
    QGridLayout *pAnswerNumGridLyt = new QGridLayout(pAnswerNumWgt);
    pAnswerNumGridLyt->setContentsMargins(0, 0, 0, 0);
    QStringList answers = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12"};
    int row = 0, col = 0;
    for (const QString &text : answers)
    {
        m_pAnswerNumLbl = new QLabel(text, this);
        m_pAnswerNumLbl->setFixedSize(39, 39);
        m_pAnswerNumLbl->setAlignment(Qt::AlignCenter);
        m_pAnswerNumLbl->setStyleSheet(styleNumLabel);
        pAnswerNumGridLyt->addWidget(m_pAnswerNumLbl, row, col);
        col++;
        if (col > 5)
        {
            col = 0;
            row++;
        }
    }
    pVAnswerLyt->addWidget(pAnswerNumWgt);

    QLabel *pLine1 = new QLabel;
    QLabel *pLine2 = new QLabel;

    QWidget *pScheduleWgt = new QWidget;
    pScheduleWgt->setFixedHeight(47);
    pScheduleWgt->setStyleSheet("QWidget{"
                             "border-radius: 0px;"
                             "border-bottom:  1px solid rgba(0,123,211,1);"
                             "border-left: none;"
                             "border-top:  1px solid rgba(0,123,211,1);"
                             "border-right: none;}");
    QHBoxLayout *pScheduleLyt = new QHBoxLayout(pScheduleWgt);
    //pScheduleLyt->setContentsMargins(0, 0, 0, 0);
    QLabel *pScheduleLbl = new QLabel;
    pScheduleLbl->setText("进度:");
    pScheduleLbl->setStyleSheet(styleScheduleLbl);
    m_pScheduleLbl = new QLabel;
    m_pScheduleLbl->setText("3/12");
    m_pScheduleLbl->setStyleSheet(styleScheduleLbl);
    pScheduleLyt->addStretch();
    pScheduleLyt->addWidget(pScheduleLbl);
    pScheduleLyt->addWidget(m_pScheduleLbl);
    pScheduleLyt->addStretch();

    // 标题
    QWidget *pTipWgt = new QWidget;
    pTipWgt->setFixedHeight(47);
    QHBoxLayout *pTipLyt = new QHBoxLayout(pTipWgt);
    pTipLyt->setContentsMargins(0, 0, 0, 0);
    QLabel *pNoAnswerStatusLbl = new QLabel;
    pNoAnswerStatusLbl->setFixedSize(20, 20);
    pNoAnswerStatusLbl->setStyleSheet("QLabel{border-image: url(:/image/icon/answer_status_no.png);}");
    QLabel *pNoAnswerLbl = new QLabel;
    pNoAnswerLbl->setText("未答");
    pNoAnswerLbl->setStyleSheet(styleTipLbl);
    QLabel *pAnsweredStatusLbl = new QLabel;
    pAnsweredStatusLbl->setFixedSize(20, 20);
    pAnsweredStatusLbl->setStyleSheet("QLabel{border-image: url(:/image/icon/answer_status_ok.png);}");
    QLabel *pAnsweredLbl = new QLabel;
    pAnsweredLbl->setText("已答");
    pAnsweredLbl->setStyleSheet(styleTipLbl);
    QLabel *pCurrentStatusLbl = new QLabel;
    pCurrentStatusLbl->setFixedSize(20, 20);
    pCurrentStatusLbl->setStyleSheet("QLabel{border-image: url(:/image/icon/answer_status_current.png);}");
    QLabel *pCurrentLbl = new QLabel;
    pCurrentLbl->setText("当前");
    pCurrentLbl->setStyleSheet(styleTipLbl);
    pTipLyt->addStretch();
    pTipLyt->addWidget(pNoAnswerStatusLbl);
    pTipLyt->addWidget(pNoAnswerLbl);
    pTipLyt->addStretch();
    pTipLyt->addWidget(pAnsweredStatusLbl);
    pTipLyt->addWidget(pAnsweredLbl);
    pTipLyt->addStretch();
    pTipLyt->addWidget(pCurrentStatusLbl);
    pTipLyt->addWidget(pCurrentLbl);
    pTipLyt->addStretch();

    pVAnswerLyt->addStretch();
    pVAnswerLyt->addWidget(pLine1);
    //pVAnswerLyt->addLayout(pScheduleLyt);
    pVAnswerLyt->addWidget(pScheduleWgt);
    pVAnswerLyt->addWidget(pLine2);
    //pVAnswerLyt->addLayout(pTipLyt);
    pVAnswerLyt->addWidget(pTipWgt);

    // 考生信息
    QWidget *pCandidateInfoWgt = new QWidget;
    pCandidateInfoWgt->setFixedSize(302, 301);
    pCandidateInfoWgt->setStyleSheet("QWidget{"
                              "line-height: 20px;"
                              "border-radius: 10px;"
                              "background-color: rgba(255,255,255,1);"
                              "color: rgba(16,16,16,1);"
                              "font-size: 14px;"
                              "text-align: center;"
                              "font-family: -regular;"
                              "}");
    QVBoxLayout *pCandidateInfoLyt = new QVBoxLayout(pCandidateInfoWgt);
    pCandidateInfoLyt->setContentsMargins(0, 0, 0, 0);

    QHBoxLayout *pHCandidateInfoLyt = new QHBoxLayout;
    pHCandidateInfoLyt->setContentsMargins(0, 0, 0, 0);
    QLabel *pCandidateInfoLbl = new QLabel;
    pCandidateInfoLbl->setText("考生信息");
    pCandidateInfoLbl->setStyleSheet(styleStudenInifLabel);
    pHCandidateInfoLyt->addSpacing(20);
    pHCandidateInfoLyt->addWidget(pCandidateInfoLbl);
    pHCandidateInfoLyt->addStretch();

    QHBoxLayout *pCandidateImgLyt = new QHBoxLayout;
    QLabel *pCandidateInfoImg = new QLabel;
    pCandidateInfoImg->setFixedSize(100, 100);
    pCandidateInfoImg->setStyleSheet("QLabel{border-image: url(:/image/LOGO.png);}");
    pCandidateImgLyt->addStretch();
    pCandidateImgLyt->addWidget(pCandidateInfoImg);
    pCandidateImgLyt->addStretch();

    QHBoxLayout *pNameLyt = new QHBoxLayout;
    QLabel *pNameLbl = new QLabel;
    pNameLbl->setText("姓名:");
    pNameLbl->setStyleSheet(styleTipLbl);
    m_pNameLbl = new QLabel;
    m_pNameLbl->setText("XXX");
    m_pNameLbl->setStyleSheet(styleInifLabel);
    pNameLyt->addSpacing(77);
    pNameLyt->addWidget(pNameLbl);
    pNameLyt->addSpacing(20);
    pNameLyt->addWidget(m_pNameLbl);
    pNameLyt->addStretch();

    QHBoxLayout *pSexLyt = new QHBoxLayout;
    QLabel *pSexLbl = new QLabel;
    pSexLbl->setText("性别:");
    pSexLbl->setStyleSheet(styleTipLbl);
    m_pSexLbl = new QLabel;
    m_pSexLbl->setText("男");
    m_pSexLbl->setStyleSheet(styleInifLabel);
    pSexLyt->addSpacing(77);
    pSexLyt->addWidget(pSexLbl);
    pSexLyt->addSpacing(20);
    pSexLyt->addWidget(m_pSexLbl);
    pSexLyt->addStretch();

    QHBoxLayout *pSchoolLyt = new QHBoxLayout;
    QLabel *pSchoolLbl = new QLabel;
    pSchoolLbl->setText("学校:");
    pSchoolLbl->setStyleSheet(styleTipLbl);
    m_pSchoolLbl = new QLabel;
    m_pSchoolLbl->setText("xx学院");
    m_pSchoolLbl->setStyleSheet(styleInifLabel);
    pSchoolLyt->addSpacing(77);
    pSchoolLyt->addWidget(pSchoolLbl);
    pSchoolLyt->addSpacing(20);
    pSchoolLyt->addWidget(m_pSchoolLbl);
    pSchoolLyt->addStretch();

    pCandidateInfoLyt->addSpacing(20);
    pCandidateInfoLyt->addLayout(pHCandidateInfoLyt);
    pCandidateInfoLyt->addSpacing(20);
    pCandidateInfoLyt->addLayout(pCandidateImgLyt);
    pCandidateInfoLyt->addSpacing(15);
    pCandidateInfoLyt->addLayout(pNameLyt);
    pCandidateInfoLyt->addSpacing(15);
    pCandidateInfoLyt->addLayout(pSexLyt);
    pCandidateInfoLyt->addSpacing(15);
    pCandidateInfoLyt->addLayout(pSchoolLyt);
    pCandidateInfoLyt->addSpacing(29);

    pMainLyt->addStretch();
    pMainLyt->addWidget(pAnswerWgt);
    pMainLyt->addSpacing(15);
    pMainLyt->addWidget(pCandidateInfoWgt);
    pMainLyt->addStretch();

}
