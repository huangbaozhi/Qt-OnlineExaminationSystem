#include "mrzpersonalcenterwidget.h"
#include "View/PersonalCenter/mrzpersonaldatawidget.h"
#include "View/PersonalCenter/mrzchangepasswordwidget.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QStackedWidget>

const QString styleLabel = QString("QLabel{"
                                   "line-height: 20px;"
                                   "color: rgba(255,255,255,1);"
                                   "font-size: 14px;"
                                   "text-align: center;"
                                   "border-radius: 3px;"
                                   "font-family: SourceHanSansSC-regular;"
                                   "border-image: url(:/image/icon/person_student_image.png);}");

const QString styleNameLbl = QString("QLabel{"
                                     "line-height: 29px;"
                                     "color: rgb(16,16,16);"
                                     "font-size: 20px;"
                                     "text-align: left;"
                                     "font-family: SourceHanSansSC-regular;}");

const QString styleSchoolLbl = QString("QLabel{"
                                       "line-height: 20px;"
                                       "color: rgb(16,16,16);"
                                       "font-size: 14px;"
                                       "text-align: left;"
                                       "font-family: SourceHanSansSC-regular;}");

const QString styleButton = QString("QPushButton{"
                                       "line-height: 24px;"
                                       "color: rgb(16,16,16);"
                                       "font-size: 16px;"
                                       "text-align: center;"
                                       "font-family: SourceHanSansSC-regular;}");

const QString styleBtn = QString("QPushButton{"
                                    "line-height: 24px;"
                                    "color: rgb(16,16,16);"
                                    "font-size: 16px;"
                                    "text-align: center;"
                                    "border:0px groove gray;"
                                    "border-radius: 0px;"
                                    "font-family: SourceHanSansSC-regular;"
                                    "}"
                                    "QPushButton:checked{"
                                    "border-image: url(:/image/button/personal_password.png);"
                                    "}"
                                    "QPushButton:unchecked {"
                                    "background-color: lightgray;"   // 未选中状态时的背景色
                                    "border: 0px solid gray;"        // 未选中状态时的边框
                                    "color: black;"                  // 未选中状态时的文字颜色
                                    "}"
                                    );

MrzPersonalCenterWidget::MrzPersonalCenterWidget(QWidget *parent)
    : QWidget{parent}
{
    setMinimumSize(1440, 1024);
    setStyleSheet("QWidget{background-color: rgba(246,250,255,1);}");
    initUi();
    connectFun();
}

void MrzPersonalCenterWidget::initUi()
{
    QVBoxLayout *pMainLyt = new QVBoxLayout(this);
    pMainLyt->setContentsMargins(0, 0, 0, 0);

    QWidget *pHeadImgWgt = new QWidget;
    pHeadImgWgt->setFixedHeight(100);
    pHeadImgWgt->setStyleSheet("QWidget{line-height: 20px;"
                                "background-color: rgba(255,255,255,1);"
                                "color: rgba(16,16,16,1);"
                                "font-size: 14px;"
                                "text-align: center;"
                                "font-family: -regular;"
                                "border:none;}");
    QHBoxLayout *pHeadImgLyt = new QHBoxLayout(pHeadImgWgt);
    pHeadImgLyt->setContentsMargins(0, 0, 0, 0);
    QLabel *pHeadLbl = new QLabel;
    pHeadLbl->setFixedSize(80, 80);
    pHeadLbl->setStyleSheet("QLabel{border-image: url(:/image/LOGO.png);}");

    QVBoxLayout *pVLabelLyt = new QVBoxLayout;
    pVLabelLyt->setContentsMargins(0, 0, 0, 0);
    QHBoxLayout *pLabelLyt = new QHBoxLayout;
    pLabelLyt->setContentsMargins(0, 0, 0, 0);
    m_pLabel = new QLabel;
    m_pLabel->setText("学生一枚");
    m_pLabel->setFixedSize(65, 24);
    m_pLabel->setStyleSheet(styleLabel);
    m_pLabel->setAlignment(Qt::AlignCenter);

    m_pNameLbl = new QLabel;
    m_pNameLbl->setText("木如知");
    m_pNameLbl->setStyleSheet(styleNameLbl);
    pLabelLyt->addWidget(m_pLabel);
    pLabelLyt->addSpacing(40);
    pLabelLyt->addWidget(m_pNameLbl);
    pLabelLyt->addStretch();

    m_pSchoolLbl = new QLabel;
    m_pSchoolLbl->setText("哔哩哔哩大学 · 杭州校区 | 社畜专业");
    m_pSchoolLbl->setStyleSheet(styleSchoolLbl);

    pVLabelLyt->addStretch();
    pVLabelLyt->addLayout(pLabelLyt);
    pVLabelLyt->addSpacing(12);
    pVLabelLyt->addWidget(m_pSchoolLbl);
    pVLabelLyt->addStretch();

    pHeadImgLyt->addSpacing(144);
    pHeadImgLyt->addWidget(pHeadLbl);
    pHeadImgLyt->addSpacing(24);
    pHeadImgLyt->addLayout(pVLabelLyt);
    pHeadImgLyt->addStretch();

    QHBoxLayout *pButtomLyt = new QHBoxLayout;
    pButtomLyt->setContentsMargins(0, 0, 0, 0);
    // 左侧
    QWidget *pLeftBtnWgt = new QWidget;
    pLeftBtnWgt->setFixedSize(200, 776);
    pLeftBtnWgt->setStyleSheet("QWidget{border-radius: 10px;background-color: rgba(255,255,255,1);}");
    QVBoxLayout *pLeftBtnLyt = new QVBoxLayout(pLeftBtnWgt);
    pLeftBtnLyt->setContentsMargins(0, 0, 0, 0);

    m_pPersonalDataBtn = new QPushButton;
    m_pPersonalDataBtn->setFixedSize(200, 40);
    m_pPersonalDataBtn->setText("个人资料");
    m_pPersonalDataBtn->setStyleSheet(styleBtn);
    m_pChangePasswordBtn = new QPushButton;
    m_pChangePasswordBtn->setFixedSize(200, 40);
    m_pChangePasswordBtn->setText("修改密码");
    m_pChangePasswordBtn->setStyleSheet(styleBtn);
    pLeftBtnLyt->addWidget(m_pPersonalDataBtn);
    pLeftBtnLyt->addWidget(m_pChangePasswordBtn);
    pLeftBtnLyt->addStretch();

    m_pPersonalDataBtn->setCheckable(true);
    m_pChangePasswordBtn->setCheckable(true);

    m_pPersonalDataBtn->setChecked(true);

    // 右侧
    QWidget *pRightBtnWgt = new QWidget;
    pRightBtnWgt->setFixedSize(921, 776);
    pRightBtnWgt->setStyleSheet("QWidget{border-radius: 10px;background-color: rgba(255,255,255,1);}");
    QVBoxLayout *pRightBtnLyt = new QVBoxLayout(pRightBtnWgt);
    pRightBtnLyt->setContentsMargins(0, 0, 0, 0);

    m_pPersonalDataWidget = new MrzPersonalDataWidget;
    m_pChangePasswordWidget = new MrzChangePasswordWidget;

    m_pStackedWidget = new QStackedWidget(this);
    m_pStackedWidget->addWidget(m_pPersonalDataWidget);
    m_pStackedWidget->addWidget(m_pChangePasswordWidget);
    m_pStackedWidget->setCurrentWidget(m_pPersonalDataWidget);
    pRightBtnLyt->addWidget(m_pStackedWidget);

    pButtomLyt->addStretch();
    pButtomLyt->addWidget(pLeftBtnWgt);
    pButtomLyt->addSpacing(30);
    pButtomLyt->addWidget(pRightBtnWgt);
    pButtomLyt->addStretch();

    pMainLyt->addWidget(pHeadImgWgt);
    pMainLyt->addSpacing(20);
    pMainLyt->addLayout(pButtomLyt);
    pMainLyt->addStretch();
}

void MrzPersonalCenterWidget::connectFun()
{
    connect(m_pPersonalDataBtn, &QPushButton::clicked, this, &MrzPersonalCenterWidget::slotSwitchPages);
    connect(m_pChangePasswordBtn, &QPushButton::clicked, this, &MrzPersonalCenterWidget::slotSwitchPages);
}

void MrzPersonalCenterWidget::slotSwitchPages()
{
    QPushButton *button = qobject_cast<QPushButton *>(QObject::sender());

    if (button == m_pPersonalDataBtn && m_pPersonalDataWidget)
    {
        m_pChangePasswordBtn->setChecked(false);
        m_pStackedWidget->setCurrentWidget(m_pPersonalDataWidget);
    }
    else if (button == m_pChangePasswordBtn && m_pChangePasswordWidget)
    {
        m_pPersonalDataBtn->setChecked(false);
        m_pStackedWidget->setCurrentWidget(m_pChangePasswordWidget);
    }
}
