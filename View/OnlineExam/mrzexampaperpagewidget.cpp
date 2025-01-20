#include "mrzexampaperpagewidget.h"

#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

MrzExamPaperPageWidget::MrzExamPaperPageWidget(QWidget *parent)
    : QWidget{parent}
{}

void MrzExamPaperPageWidget::initUi()
{
    QVBoxLayout *pMainLyt = new QVBoxLayout(this);

    QWidget *pTitleWgt = new QWidget(this);
}
