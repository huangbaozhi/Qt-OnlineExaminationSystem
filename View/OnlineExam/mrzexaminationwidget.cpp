#include "mrzexaminationwidget.h"
#include "View/OnlineExam/mrzanswersheetwidget.h"
#include "View/OnlineExam/mrzexampaperpagewidget.h"
#include "View/OnlineExam/mrzexampapertitlewidget.h"

#include <QVBoxLayout>

MrzExaminationWidget::MrzExaminationWidget(QWidget *parent)
    : QWidget{parent}
{
    setMinimumSize(1440, 1024);
    initUi();
}

void MrzExaminationWidget::initUi()
{
    QVBoxLayout *pMainLyt = new QVBoxLayout(this);

    m_pExamPaperTitleWidget = new MrzExamPaperTitleWidget;

    QHBoxLayout *pExamPaperLyt = new QHBoxLayout;
    pExamPaperLyt->setContentsMargins(0, 0, 0, 0);
    m_pAnswerSheetWidget = new MrzAnswerSheetWidget;
    m_pExamPaperPageWidget = new MrzExamPaperPageWidget;
    pExamPaperLyt->addWidget(m_pAnswerSheetWidget);
    pExamPaperLyt->addWidget(m_pExamPaperPageWidget);

    pMainLyt->addWidget(m_pExamPaperTitleWidget);
    pMainLyt->addLayout(pExamPaperLyt);
}
