#include "mrzquestionwidget.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QRadioButton>

const QString styleLbl = QString("QLabel{"
                                 "line-height: 24px;"
                                 "color: rgba(0,0,0,1);"
                                 "font-size: 16px;"
                                 "text-align: left;"
                                 "font-family: SourceHanSansSC-regular;}");

const QString styleRadioButton = QString("QRadioButton{"
                                 "line-height: 22px;"
                                 "color: rgb(16,16,16);"
                                 "font-size: 16px;"
                                 "text-align: left;"
                                 "font-family: SourceHanSansSC-regular;}");

const QString styleRadioLbl = QString("QLabel{"
                                      "line-height: 24px;"
                                      "border-radius: 0px;"
                                      "color: rgba(189,49,36,1);"
                                      "font-size: 16px;"
                                      "text-align: left;"
                                      "font-family: SourceHanSansSC-regular;}");

MrzQuestionWidget::MrzQuestionWidget(QWidget *parent)
    : QWidget{parent}
{
    //initUi();
}

MrzQuestionWidget::MrzQuestionWidget(const QString &question, const QStringList &options, QWidget *parent)
{
    mQuestion = question;
    mOptions = options;

    initUi();
}

void MrzQuestionWidget::initUi()
{
    QVBoxLayout *pMainLyt = new QVBoxLayout(this);
    pMainLyt->setContentsMargins(0, 0, 0, 0);

    QHBoxLayout *pQuestionLyt = new QHBoxLayout;
    pQuestionLyt->setContentsMargins(0, 0, 0, 0);
    m_pQuestionNum = new QLabel;
    m_pQuestionNum->setFixedWidth(100);
    m_pQuestionNum->setText("1");
    m_pQuestionNum->setStyleSheet("QLabel{"
                                  "line-height: 41px;"
                                  "border-radius: 0px;"
                                  "background-color: rgba(0,123,211,1);"
                                  "color: rgba(255,255,255,1);"
                                  "font-size: 28px;"
                                  "font-family: SourceHanSansSC-regular;}");
    m_pQuestionNum->setAlignment(Qt::AlignTop | Qt::AlignHCenter);

    QVBoxLayout *pTopicLyt = new QVBoxLayout;
    pTopicLyt->setContentsMargins(0, 0, 0, 0);
    QHBoxLayout *pOptionLyt = new QHBoxLayout;
    pOptionLyt ->setContentsMargins(0, 0, 0, 0);
    QLabel *pRadioLbl = new QLabel;
    pRadioLbl->setText("【单选】（1分）");
    pRadioLbl->setStyleSheet(styleRadioLbl);
    QLabel *pCountDownLbl = new QLabel;
    pCountDownLbl->setText("本题倒计时:");
    pCountDownLbl->setStyleSheet("QLabel{"
                                 "line-height: 24px;"
                                 "color: rgb(16,16,16);"
                                 "font-size: 16px;"
                                 "text-align: left;"
                                 "font-family: SourceHanSansSC-regular;}");
    m_pCountDownLbl = new QLabel;
    m_pCountDownLbl->setText("35");
    m_pCountDownLbl->setStyleSheet(styleRadioLbl);

    pOptionLyt->addWidget(pRadioLbl);
    pOptionLyt->addStretch();
    pOptionLyt->addWidget(pCountDownLbl);
    pOptionLyt->addWidget(m_pCountDownLbl);

    // 题目
    m_pQuestionLbl = new QLabel(mQuestion, this);
    m_pQuestionLbl->setStyleSheet(styleLbl);
    pTopicLyt->addLayout(pOptionLyt);
    pTopicLyt->addWidget(m_pQuestionLbl);
    pTopicLyt->addStretch();

    pQuestionLyt->addWidget(m_pQuestionNum);
    pQuestionLyt->addLayout(pTopicLyt);
    pMainLyt->addLayout(pQuestionLyt);

    QHBoxLayout *pHRadioButtonLyt = new QHBoxLayout;
    pHRadioButtonLyt ->setContentsMargins(0, 0, 0, 0);
    pHRadioButtonLyt->addSpacing(100);
    QVBoxLayout *pRadioButtonLyt = new QVBoxLayout;
    pRadioButtonLyt->setContentsMargins(0, 0, 0, 0);

    for (const QString &option : mOptions)
    {
        QRadioButton *pRadioButton = new QRadioButton(option, this);
        pRadioButton->setStyleSheet(styleRadioButton);
        pRadioButtonLyt->addWidget(pRadioButton);
    }
    pHRadioButtonLyt->addLayout(pRadioButtonLyt);
    pMainLyt->addLayout(pHRadioButtonLyt);
    pMainLyt->addStretch();
}
