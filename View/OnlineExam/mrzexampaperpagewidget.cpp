#include "mrzexampaperpagewidget.h"

#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

MrzExamPaperPageWidget::MrzExamPaperPageWidget(QWidget *parent)
    : QWidget{parent}
{
    setMinimumSize(1068, 924);
    initUi();
}

void MrzExamPaperPageWidget::initUi()
{
    QVBoxLayout *pMainLyt = new QVBoxLayout(this);

    QWidget *pTitleWgt = new QWidget(this);
    pTitleWgt->setFixedSize(1068, 924);
    pTitleWgt->setStyleSheet("QWidget{line-height: 20px;"
                             "border-radius: 10px;"
                             "background-color: rgba(255,255,255,1);"
                             "color: rgba(16,16,16,1);"
                             "font-size: 14px;"
                             "text-align: center;"
                             "font-family: -regular;}");


    pMainLyt->addStretch();
    pMainLyt->addWidget(pTitleWgt);
    pMainLyt->addStretch();
}
