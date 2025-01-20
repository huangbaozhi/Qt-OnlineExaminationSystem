#include "mrzfacerecognitiondialog.h"
#include "View/subassembly/mrzcamerafacedisplaywidget.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

const QString styleLbl = QString("QLabel{"
                                 "line-height: 28px;"
                                 "color: rgba(16,16,16,1);"
                                 "font-size: 20px;"
                                 "text-align: center;"
                                 "font-family: PingFangSC-bold;"
                                 "border: none;"
                            "}"
                        );

const QString styleButton = QString("QPushButton{"
                                    "border-image: url(:/image/button/close_button.png);"
                                    "border:0px groove gray;"
                                "}"
                            );

const QString styleOkLbl = QString("QLabel{"
                                    "line-height: 18px;"
                                    "color: rgba(16,16,16,1);"
                                    "font-size: 22px;"
                                    "text-align: center;"
                                    "font-family: PingFangSC-bold;"
                                "}"
                            );

const QString styleTipLbl = QString("QLabel{"
                                   "line-height: 21px;"
                                   "color: rgba(255,42,72,1);"
                                   "font-size: 15px;"
                                   "text-align: center;"
                                   "font-family: PingFangSC-regular;"
                                "}"
                            );

const QString styleVerifyButton = QString("QPushButton{"
                                          "line-height: 25px;"
                                          "background-color: rgba(1,109,240,1);"
                                          "color: rgba(255,255,255,1);"
                                          "font-size: 18px;"
                                          "text-align: center;"
                                          "font-family: PingFangSC-bold;"
                                          "border:0px groove gray;"
                                        "}"
                                    );

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

    QWidget *pTitleWgt = new QWidget(this);
    pTitleWgt->setFixedHeight(60);
    pTitleWgt->setStyleSheet("QWidget{border-bottom: 1px solid rgba(0,0,0,0.1);"
                                    "border-left: none;"
                                    "border-top: none;"
                                    "border-right: none;}");
    QHBoxLayout *pTitleLyt = new QHBoxLayout(pTitleWgt);
    pTitleLyt->setContentsMargins(0, 0, 0, 0);
    QLabel *pTitleLbl = new QLabel;
    pTitleLbl->setText("人脸识别验证");
    pTitleLbl->setStyleSheet(styleLbl);
    m_pCloseBtn = new QPushButton;
    m_pCloseBtn->setFixedSize(60, 60);
    m_pCloseBtn->setStyleSheet(styleButton);
    pTitleLyt->addSpacing(7);
    pTitleLyt->addWidget(pTitleLbl);
    pTitleLyt->addWidget(m_pCloseBtn);

    QWidget *pFaceWgt = new QWidget(this);
    QVBoxLayout *pFaceLyt = new QVBoxLayout(pFaceWgt);
    pFaceLyt->setContentsMargins(0, 0, 0, 0);

    QHBoxLayout *pFaceTitleLyt = new QHBoxLayout;
    pFaceTitleLyt->setContentsMargins(0, 0, 0, 0);
    QLabel *pFaceTitleLbl = new QLabel();
    pFaceTitleLbl->setText("确认为本人操作");
    pFaceTitleLbl->setStyleSheet(styleOkLbl);
    pFaceTitleLyt->addStretch();
    pFaceTitleLyt->addWidget(pFaceTitleLbl);
    pFaceTitleLyt->addStretch();

    QHBoxLayout *pDescriptionLyt = new QHBoxLayout;
    pDescriptionLyt->setContentsMargins(0, 0, 0, 0);
    QLabel *pDescriptionLbl = new QLabel(this);
    pDescriptionLbl->setText("请保持正脸在取景框中，根据屏幕指示完成识别");
    pDescriptionLbl->setStyleSheet("QLabel{line-height: 18px;color: rgba(146,146,146,1);font-size: 16px;text-align: center;font-family: PingFangSC-regular;}");
    pDescriptionLyt->addStretch();
    pDescriptionLyt->addWidget(pDescriptionLbl);
    pDescriptionLyt->addStretch();

    QHBoxLayout *pFaceCameraLyt = new QHBoxLayout;
    pFaceCameraLyt->setContentsMargins(0, 0, 0, 0);
    MrzCameraFaceDisplayWidget *pFaceCameraWgt = new MrzCameraFaceDisplayWidget;
    //QWidget *pFaceCameraWgt = new QWidget(this);
    pFaceCameraWgt->setFixedSize(250, 250);
    pFaceCameraWgt->setStyleSheet("QWidget{background-color: rgba(17,18,14,1);border-radius: 230px;}");
    pFaceCameraLyt->addStretch();
    pFaceCameraLyt->addWidget(pFaceCameraWgt);
    pFaceCameraLyt->addStretch();

    QHBoxLayout *pTipLyt = new QHBoxLayout;
    pTipLyt->setContentsMargins(0, 0, 0, 0);
    QLabel *pTipLbl = new QLabel();
    pTipLbl->setText("请先去个人中心上传证件照！");
    pTipLbl->setStyleSheet(styleTipLbl);
    pTipLyt->addStretch();
    pTipLyt->addWidget(pTipLbl);
    pTipLyt->addStretch();

    pFaceLyt->addLayout(pFaceTitleLyt);
    pFaceLyt->addSpacing(15);
    pFaceLyt->addLayout(pDescriptionLyt);
    pFaceLyt->addSpacing(9);
    pFaceLyt->addLayout(pFaceCameraLyt);
    pFaceLyt->addSpacing(12);
    pFaceLyt->addLayout(pTipLyt);

    QLabel *pLineLbl = new QLabel;
    pLineLbl->setFixedHeight(1);
    //pLineLbl->setStyleSheet("QLabel{border: 1px solid rgba(187,187,187,1);}");
    pLineLbl->setStyleSheet("QWidget{border-bottom: 1px solid rgba(0,0,0,0.1);"
                             "border-left: none;"
                             "border-top: none;"
                             "border-right: none;}");

    QHBoxLayout *pButtonLyt = new QHBoxLayout;
    pButtonLyt->setContentsMargins(0, 0, 0, 0);

    QVBoxLayout *pDirectCameraLyt = new QVBoxLayout;
    pDirectCameraLyt->setContentsMargins(0, 0, 0, 0);
    QHBoxLayout *pHpDirectCameraLyt = new QHBoxLayout;
    pHpDirectCameraLyt->setContentsMargins(0, 0, 0, 0);
    QLabel *pDirectCameraImg = new QLabel;
    pDirectCameraImg->setFixedSize(40, 40);
    pDirectCameraImg->setStyleSheet("QLabel{border-image: url(:/image/icon/Camera_dialog.png)}");
    pHpDirectCameraLyt->addWidget(pDirectCameraImg);
    QLabel *pDirectCameraLbl = new QLabel;
    pDirectCameraLbl->setText("正对摄像头");
    pDirectCameraLyt->addStretch();
    //pDirectCameraLyt->addWidget(pDirectCameraImg);
    pDirectCameraLyt->addLayout(pHpDirectCameraLyt);
    pDirectCameraLyt->addWidget(pDirectCameraLbl);
    pDirectCameraLyt->addStretch();

    QVBoxLayout *pWellLitLyt = new QVBoxLayout;
    pWellLitLyt->setContentsMargins(0, 0, 0, 0);
    QHBoxLayout *pHWellLitLyt = new QHBoxLayout;
    pHWellLitLyt->setContentsMargins(0, 0, 0, 0);
    QLabel *pWellLitImg = new QLabel;
    pWellLitImg->setFixedSize(40, 40);
    pWellLitImg->setStyleSheet("QLabel{border-image: url(:/image/icon/plenty_light_dialog.png)}");
    pHWellLitLyt->addWidget(pWellLitImg);
    QLabel *pWellLitLbl = new QLabel;
    pWellLitLbl->setText("光线充足");
    pWellLitLyt->addStretch();
    //pWellLitLyt->addWidget(pWellLitImg);
    pWellLitLyt->addLayout(pHWellLitLyt);
    pWellLitLyt->addWidget(pWellLitLbl);
    pWellLitLyt->addStretch();

    QVBoxLayout *pFaceNoCoverLyt = new QVBoxLayout;
    pFaceNoCoverLyt->setContentsMargins(0, 0, 0, 0);
    QHBoxLayout *pHFaceNoCoverLyt = new QHBoxLayout;
    pHFaceNoCoverLyt->setContentsMargins(0, 0, 0, 0);
    QLabel *pFaceNoCoverImg = new QLabel;
    pFaceNoCoverImg->setFixedSize(40, 40);
    pFaceNoCoverImg->setStyleSheet("QLabel{border-image: url(:/image/icon/face_unobstructed_dialog.png)}");
    pHFaceNoCoverLyt->addWidget(pFaceNoCoverImg);
    QLabel *pFaceNoCoverLbl = new QLabel;
    pFaceNoCoverLbl->setText("脸部无遮挡");
    pFaceNoCoverLyt->addStretch();
    //pFaceNoCoverLyt->addWidget(pFaceNoCoverImg);
    pFaceNoCoverLyt->addLayout(pHFaceNoCoverLyt);
    //pFaceNoCoverLyt->addSpacing(10);
    pFaceNoCoverLyt->addWidget(pFaceNoCoverLbl);
    pFaceNoCoverLyt->addStretch();

    pButtonLyt->addStretch();
    pButtonLyt->addLayout(pDirectCameraLyt);
    pButtonLyt->addSpacing(60);
    pButtonLyt->addLayout(pWellLitLyt);
    pButtonLyt->addSpacing(60);
    pButtonLyt->addLayout(pFaceNoCoverLyt);
    pButtonLyt->addStretch();

    QHBoxLayout *pVerifyLyt = new QHBoxLayout;
    pVerifyLyt->setContentsMargins(0, 0, 0, 0);
    pStartVerificationBtn = new QPushButton;
    pStartVerificationBtn->setFixedSize(268, 46);
    pStartVerificationBtn->setText("开始验证");
    pStartVerificationBtn->setStyleSheet(styleVerifyButton);
    pVerifyLyt->addStretch();
    pVerifyLyt->addWidget(pStartVerificationBtn);
    pVerifyLyt->addStretch();

    //pMainLyt->addLayout(pTitleLyt);
    pMainLyt->addWidget(pTitleWgt);
    pMainLyt->addSpacing(12);
    pMainLyt->addWidget(pFaceWgt);
    pMainLyt->addSpacing(31);
    pMainLyt->addWidget(pLineLbl);
    pMainLyt->addSpacing(17);
    pMainLyt->addLayout(pButtonLyt);
    pMainLyt->addSpacing(33);
    pMainLyt->addLayout(pVerifyLyt);
    pMainLyt->addSpacing(35);
}

void MrzFaceRecognitionDialog::connectFun()
{

}
