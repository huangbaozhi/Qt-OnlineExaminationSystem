#include "mrzexampaperpagewidget.h"
#include "View/OnlineExam/mrzquestionwidget.h"

#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStackedWidget>

const QString styleButton = QString("QPushButton{"
                                    "line-height: 20px;"
                                    "border-radius: 3px;"
                                    "background-color: rgba(56,148,255,1);"
                                    "color: rgba(255, 255, 255, 1);"
                                    "font-size: 14px;"
                                    "text-align: center;"
                                    "font-family: -regular;"
                                    "border: 1px solid rgba(56,148,255,1);"
                                    "font-family: SourceHanSansSC-bold;}");

MrzExamPaperPageWidget::MrzExamPaperPageWidget(QWidget *parent)
    : QWidget{parent}
    , currentIndex(0)
{
    setMinimumSize(1068, 924);
    initUi();
    connectFun();
}

void MrzExamPaperPageWidget::initUi()
{
    QVBoxLayout *pMainLyt = new QVBoxLayout(this);
    pMainLyt->setContentsMargins(0, 0, 0, 0);

    QWidget *pMainWgt = new QWidget(this);
    pMainWgt->setFixedSize(1068, 924);
    pMainWgt->setStyleSheet("QWidget{line-height: 20px;"
                             "border-radius: 10px;"
                             "background-color: rgba(255,255,255,1);"
                             "color: rgba(16,16,16,1);"
                             "font-size: 14px;"
                             "text-align: center;"
                             "font-family: -regular;}");
    QVBoxLayout *pStackedLyt = new QVBoxLayout(pMainWgt);
    pStackedLyt ->setContentsMargins(0, 0, 0, 0);

    //m_pQuestionWidget = new MrzQuestionWidget;

    m_pStackedWidget = new QStackedWidget(this);
    m_pStackedWidget->setFixedSize(1028, 785);
    m_pStackedWidget->addWidget(createQuestionPage("图中箭头所指细胞是？（外周血，瑞特-吉姆萨染色，×1000）", {"A：畸形血小板", "B：小血小板", "C：大血小板", "D：破碎细胞", "E：正常血小板"}));
    m_pStackedWidget->addWidget(createQuestionPage("Question 2", {"Option A", "Option B", "Option C"}));

    QHBoxLayout *pButtonLyt = new QHBoxLayout;
    pButtonLyt ->setContentsMargins(0, 0, 0, 0);
    m_pPrevButton = new QPushButton("上一题", this);
    m_pPrevButton->setFixedSize(98, 40);
    m_pPrevButton->setStyleSheet(styleButton);
    m_pNextButton = new QPushButton("下一题", this);
    m_pNextButton->setFixedSize(98, 40);
    m_pNextButton->setStyleSheet(styleButton);

    pButtonLyt->addStretch();
    pButtonLyt->addWidget(m_pPrevButton);
    pButtonLyt->addWidget(m_pNextButton);


    pStackedLyt->addWidget(m_pStackedWidget);
    pStackedLyt->addLayout(pButtonLyt);

    pMainLyt->addStretch();
    pMainLyt->addWidget(pMainWgt);
    pMainLyt->addStretch();
}

void MrzExamPaperPageWidget::connectFun()
{
    connect(m_pNextButton, &QPushButton::clicked, this, &MrzExamPaperPageWidget::slotNextQuestion);
    connect(m_pPrevButton, &QPushButton::clicked, this, &MrzExamPaperPageWidget::slotPrevQuestion);
}

QWidget *MrzExamPaperPageWidget::createQuestionPage(const QString &question, const QStringList &options)
{
    return new MrzQuestionWidget(question, options);
}

void MrzExamPaperPageWidget::slotNextQuestion()
{
    if (currentIndex < m_pStackedWidget->count() - 1) {
        currentIndex++;
        m_pStackedWidget->setCurrentIndex(currentIndex);
    }
}

void MrzExamPaperPageWidget::slotPrevQuestion()
{
    if (currentIndex > 0) {
        currentIndex--;
        m_pStackedWidget->setCurrentIndex(currentIndex);
    }
}
