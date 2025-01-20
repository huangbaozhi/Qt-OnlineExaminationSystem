#include "mrzchangepasswordwidget.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

const QString styleLineEdit = QString("QLineEdit{"
                                      "line-height: 20px;"
                                      "border-radius: 3px;"
                                      "background-color: rgba(255,255,255,1);"
                                      "color: rgba(193, 194, 197, 1);"
                                      "font-size: 14px;"
                                      "text-align: left;"
                                      "border: 1px solid rgba(220,224,231,1);"
                                      "font-family: SourceHanSansSC-regular;}");

const QString styleLabel = QString("QLabel{line-height: 20px;"
                                   "color: rgb(16,16,16);"
                                   "font-size: 14px;"
                                   "text-align: left;"
                                   "font-family: SourceHanSansSC-regular;"
                                   "border: none;}");

const QString styleRadion = QString("QRadioButton{line-height: 20px;"
                                    "color: rgb(16,16,16);"
                                    "font-size: 14px;"
                                    "text-align: left;"
                                    "font-family: SourceHanSansSC-regular;"
                                    "border: none;}");

const QString styleTipLabel = QString("QLabel{line-height: 20px;"
                                      "color: rgba(255,0,0,1);"
                                      "font-size: 14px;"
                                      "text-align: left;"
                                      "font-family: SourceHanSansSC-regular;"
                                      "border: none;}");

const QString styleButton = QString("QPushButton{line-height: 17px;"
                                    "color: rgb(255,255,255);"
                                    "font-size: 14px;"
                                    "text-align: center;"
                                    "font-family: SourceHanSansSC-regular;"
                                    "border-radius: 2px 2px 2px 2px;"
                                    "background-color: rgba(86,119,252,1);"
                                    "border: 0px solid rgba(255,0,0,0);}");

MrzChangePasswordWidget::MrzChangePasswordWidget(QWidget *parent)
    : QWidget{parent}
{
    initUi();
}

void MrzChangePasswordWidget::initUi()
{
    QVBoxLayout *pMainLyt = new QVBoxLayout(this);
    pMainLyt->setContentsMargins(0, 0, 0, 0);

    QHBoxLayout *pChangePasswordLyt = new QHBoxLayout;
    pChangePasswordLyt ->setContentsMargins(0, 0, 0, 0);
    QLabel *pChangePasswordLbl = new QLabel;
    pChangePasswordLbl->setText("修改密码");
    pChangePasswordLbl->setStyleSheet("QLabel{line-height: 29px;"
                              "color: rgb(16,16,16);"
                              "font-size: 20px;"
                              "text-align: left;"
                              "font-family: SourceHanSansSC-regular;}");
    pChangePasswordLyt->addSpacing(25);
    pChangePasswordLyt->addWidget(pChangePasswordLbl);
    pChangePasswordLyt->addStretch();

    // 原密码
    QHBoxLayout *pOriginalPasswordLyt = new QHBoxLayout;
    pOriginalPasswordLyt->setContentsMargins(0, 0, 0, 0);
    QLabel *pTipOriginalPasswordLbl = new QLabel;
    pTipOriginalPasswordLbl->setText("*");
    pTipOriginalPasswordLbl->setStyleSheet(styleTipLabel);
    QLabel *pOriginalPasswordLbl = new QLabel;
    pOriginalPasswordLbl->setText("原密码");
    pOriginalPasswordLbl->setStyleSheet(styleLabel);
    pOriginalPasswordLbl->setAlignment(Qt::AlignCenter);
    m_pOriginalPasswordEdit = new QLineEdit;
    m_pOriginalPasswordEdit->setFixedSize(380, 40);
    m_pOriginalPasswordEdit->setStyleSheet(styleLineEdit);
    pOriginalPasswordLyt->addSpacing(158);
    pOriginalPasswordLyt->addWidget(pTipOriginalPasswordLbl);
    pOriginalPasswordLyt->addSpacing(5);
    pOriginalPasswordLyt->addWidget(pOriginalPasswordLbl);
    pOriginalPasswordLyt->addSpacing(13);
    pOriginalPasswordLyt->addWidget(m_pOriginalPasswordEdit);
    pOriginalPasswordLyt->addStretch();

    // 新密码
    QHBoxLayout *pNewPasswordLyt = new QHBoxLayout;
    pNewPasswordLyt->setContentsMargins(0, 0, 0, 0);
    QLabel *pTipNewPasswordLbl = new QLabel;
    pTipNewPasswordLbl->setText("*");
    pTipNewPasswordLbl->setStyleSheet(styleTipLabel);
    QLabel *pNewPasswordLbl = new QLabel;
    pNewPasswordLbl->setText("原密码");
    pNewPasswordLbl->setStyleSheet(styleLabel);
    pNewPasswordLbl->setAlignment(Qt::AlignCenter);
    m_pNewPasswordEdit = new QLineEdit;
    m_pNewPasswordEdit->setFixedSize(380, 40);
    m_pNewPasswordEdit->setStyleSheet(styleLineEdit);
    pNewPasswordLyt->addSpacing(158);
    pNewPasswordLyt->addWidget(pTipNewPasswordLbl);
    pNewPasswordLyt->addSpacing(5);
    pNewPasswordLyt->addWidget(pNewPasswordLbl);
    pNewPasswordLyt->addSpacing(13);
    pNewPasswordLyt->addWidget(m_pNewPasswordEdit);
    pNewPasswordLyt->addStretch();

    // 再次输入
    QHBoxLayout *pEnterAgainPasswordLyt = new QHBoxLayout;
    pEnterAgainPasswordLyt->setContentsMargins(0, 0, 0, 0);
    QLabel *pTipEnterAgainPasswordLbl = new QLabel;
    pTipEnterAgainPasswordLbl->setText("*");
    pTipEnterAgainPasswordLbl->setStyleSheet(styleTipLabel);
    QLabel *pEnterAgainPasswordLbl = new QLabel;
    pEnterAgainPasswordLbl->setText("原密码");
    pEnterAgainPasswordLbl->setStyleSheet(styleLabel);
    pEnterAgainPasswordLbl->setAlignment(Qt::AlignCenter);
    m_pEnterAgainPasswordEdit = new QLineEdit;
    m_pEnterAgainPasswordEdit->setFixedSize(380, 40);
    m_pEnterAgainPasswordEdit->setStyleSheet(styleLineEdit);
    pEnterAgainPasswordLyt->addSpacing(158);
    pEnterAgainPasswordLyt->addWidget(pTipEnterAgainPasswordLbl);
    pEnterAgainPasswordLyt->addSpacing(5);
    pEnterAgainPasswordLyt->addWidget(pEnterAgainPasswordLbl);
    pEnterAgainPasswordLyt->addSpacing(13);
    pEnterAgainPasswordLyt->addWidget(m_pEnterAgainPasswordEdit);
    pEnterAgainPasswordLyt->addStretch();

    QHBoxLayout *pSaveLyt = new QHBoxLayout;
    m_pSaveBtn = new QPushButton;
    m_pSaveBtn->setFixedSize(94, 36);
    m_pSaveBtn->setText("保存");
    m_pSaveBtn->setStyleSheet(styleButton);
    pSaveLyt->addSpacing(239);
    pSaveLyt->addWidget(m_pSaveBtn);
    pSaveLyt->addStretch();

    pMainLyt->addSpacing(20);
    pMainLyt->addLayout(pChangePasswordLyt);
    pMainLyt->addSpacing(22);
    pMainLyt->addLayout(pOriginalPasswordLyt);
    pMainLyt->addSpacing(22);
    pMainLyt->addLayout(pNewPasswordLyt);
    pMainLyt->addSpacing(22);
    pMainLyt->addLayout(pEnterAgainPasswordLyt);
    pMainLyt->addSpacing(40);
    pMainLyt->addLayout(pSaveLyt);
    pMainLyt->addStretch();
}
