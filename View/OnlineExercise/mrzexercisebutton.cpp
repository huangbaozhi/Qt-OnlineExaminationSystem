#include "mrzexercisebutton.h"

#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>

const QString styleButton = QString("QPushButton{"
                                    "line-height: 24px;"
                                    "color: rgba(255,0,0,1);"
                                    "font-size: 16px;"
                                    "text-align: left;"
                                    "font-family: SourceHanSansSC-regular;"
                                    "border:0px groove gray;"
                                    "}"
                                    );

const QString style = QString("QPushButton{"
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

MrzExerciseButton::MrzExerciseButton(QWidget *parent)
    : QPushButton{parent}
{
    this->setFixedHeight(60);
    this->setStyleSheet("QPushButton{"
                        "line-height: 24px;"
                        "color: rgba(255,255,255,1);"
                        "font-size: 16px;"
                        "text-align: left;"
                        "border:0px groove gray;"
                        "font-family: SourceHanSansSC-regular;"
                        "}"
                        "QPushButton:checked{"
                        "background-color: rgba(255,255,255,1);"
                        "}"
                        "QPushButton:unchecked {"
                        "background-color: lightgray;"   // 未选中状态时的背景色
                        "border: 2px solid gray;"        // 未选中状态时的边框
                        "color: black;"                  // 未选中状态时的文字颜色
                        "}");

    initUi();
}

void MrzExerciseButton::initUi()
{
    QHBoxLayout *pMyExerciseLyt = new QHBoxLayout(this);
    pMyExerciseLyt->setContentsMargins(0, 0, 0, 0);

    m_pLogoLbl = new QLabel(this);
    m_pLogoLbl->setFixedSize(40, 40);
    m_pLogoLbl->setStyleSheet("QLabel{border-image: url(:/image/icon/my_error.png);}");

    QVBoxLayout *pMyQuestionLyt = new QVBoxLayout;
    pMyQuestionLyt->setContentsMargins(0, 0, 0, 0);

    m_pTitleLbl = new QLabel(this);
    m_pTitleLbl->setText("我的错题");
    m_pTitleLbl->setFixedSize(80, 29);
    m_pTitleLbl->setStyleSheet("QLabel{line-height: 29px;color: rgb(58,62,81);font-size: 20px;text-align: left;font-family: SourceHanSansSC-regular;}");
    m_pQuestionNumLbl = new QLabel(this);
    m_pQuestionNumLbl->setFixedSize(80, 20);
    m_pQuestionNumLbl->setText("(1道)");
    m_pQuestionNumLbl->setStyleSheet("QLabel{line-height: 20px;color: rgb(58,62,81);font-size: 14px;text-align: left;font-family: SourceHanSansSC-regular}");
    pMyQuestionLyt->addWidget(m_pTitleLbl);
    pMyQuestionLyt->addWidget(m_pQuestionNumLbl);

    m_pClearBtn = new QPushButton(this);
    m_pClearBtn->setFixedSize(64, 24);
    m_pClearBtn->setText("清空错题");
    m_pClearBtn->setStyleSheet(styleButton);

    pMyExerciseLyt->addSpacing(20);
    pMyExerciseLyt->addWidget(m_pLogoLbl);
    pMyExerciseLyt->addSpacing(20);
    pMyExerciseLyt->addLayout(pMyQuestionLyt);
    pMyExerciseLyt->addSpacing(96);
    pMyExerciseLyt->addWidget(m_pClearBtn);
    pMyExerciseLyt->addStretch();
}

void MrzExerciseButton::setStyleImage(QString style)
{
    m_pLogoLbl->setStyleSheet(style);
    QString styleSheet = QString("QLabel{border-image: url(%1);}").arg(style);
    m_pLogoLbl->setStyleSheet(styleSheet);
}

void MrzExerciseButton::setTitle(QString title)
{
    m_pTitleLbl->setText(title);
}

void MrzExerciseButton::setQuestionNum(int number)
{
    m_pQuestionNumLbl->setText(QString::number(number) + "道");
}

void MrzExerciseButton::setClear(QString clear)
{
    m_pClearBtn->setText(clear);
}
