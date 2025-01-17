#include "mrzfacerecognitiondialog.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

MrzFaceRecognitionDialog::MrzFaceRecognitionDialog(QWidget *parent)
    : QDialog{parent}
{
    setMinimumSize(429, 657);
    initUi();
}

void MrzFaceRecognitionDialog::initUi()
{
    QVBoxLayout *pMainLyt = new QVBoxLayout(this);
    pMainLyt->setContentsMargins(0, 0, 0, 0);

    QHBoxLayout *pTitleLyt = new QHBoxLayout;
    QLabel *pTitleLbl = new QLabel;
    pTitleLbl->setText("人脸识别验证");
    m_pCloseBtn = new QPushButton;
    pTitleLyt->addWidget(pTitleLbl);
    pTitleLyt->addWidget(m_pCloseBtn);

    QWidget *pFaceWgt = new QWidget(this);
    QVBoxLayout *pFaceLyt = new QVBoxLayout(pFaceWgt);
    QLabel *pFaceTitleLbl = new QLabel();
    pFaceTitleLbl->setText("确认为本人操作");
    QLabel *pDescriptionLbl = new QLabel(this);
    pDescriptionLbl->setText("请保持正脸在取景框中，根据屏幕指示完成识别");
    QLabel *pFaceLbl = new QLabel();
    QLabel *pTipLbl = new QLabel();
    pTipLbl->setText("请先去个人中心上传证件照！");
    pFaceLyt->addWidget(pFaceTitleLbl);
    pFaceLyt->addWidget(pDescriptionLbl);
    pFaceLyt->addWidget(pFaceLbl);
    pFaceLyt->addWidget(pTipLbl);

    QHBoxLayout *pButtonLyt = new QHBoxLayout;
    pButtonLyt->setContentsMargins(0, 0, 0, 0);

    QVBoxLayout *pDirectCameraLyt = new QVBoxLayout;
    QLabel *pDirectCameraImg = new QLabel;
    m_pDirectCameraBtn = new QPushButton;
    m_pDirectCameraBtn->setText("正对摄像头");
    pDirectCameraLyt->addWidget(pDirectCameraImg);
    pDirectCameraLyt->addWidget(m_pDirectCameraBtn);

    QVBoxLayout *pWellLitLyt = new QVBoxLayout;
    QLabel *pWellLitImg = new QLabel;
    m_pWellLitBtn = new QPushButton;
    m_pWellLitBtn->setText("光线充足");
    pWellLitLyt->addWidget(pWellLitImg);
    pWellLitLyt->addWidget(m_pWellLitBtn);

    QVBoxLayout *pFaceNoCoverLyt = new QVBoxLayout;
    QLabel *pFaceNoCoverImg = new QLabel;
    m_pFaceNoCoverBtn = new QPushButton;
    m_pFaceNoCoverBtn->setText("脸部无遮挡");
    pFaceNoCoverLyt->addWidget(pFaceNoCoverImg);
    pFaceNoCoverLyt->addWidget(m_pFaceNoCoverBtn);

    pButtonLyt->addLayout(pDirectCameraLyt);
    pButtonLyt->addLayout(pWellLitLyt);
    pButtonLyt->addLayout(pFaceNoCoverLyt);

    QHBoxLayout *pVerifyLyt = new QHBoxLayout;
    pStartVerificationBtn = new QPushButton;
    pStartVerificationBtn->setText("开始验证");
    pVerifyLyt->addStretch();
    pVerifyLyt->addWidget(pStartVerificationBtn);
    pVerifyLyt->addStretch();

    pMainLyt->addLayout(pTitleLyt);
    pMainLyt->addWidget(pFaceWgt);
    pMainLyt->addLayout(pButtonLyt);
    pMainLyt->addLayout(pVerifyLyt);
}

void MrzFaceRecognitionDialog::connectFun()
{

}
