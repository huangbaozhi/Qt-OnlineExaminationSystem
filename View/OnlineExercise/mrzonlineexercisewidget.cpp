#include "mrzonlineexercisewidget.h"
#include "mrzmyexercisewidget.h"

#include <QVBoxLayout>
#include <QScrollArea>
#include <QHBoxLayout>

MrzOnlineExerciseWidget::MrzOnlineExerciseWidget(QWidget *parent)
    : QWidget{parent}
{
    initUi();
}

void MrzOnlineExerciseWidget::initUi()
{
    m_pMyExerciseWidget = new MrzMyExerciseWidget;

    // 使用 QScrollArea 包装内容区域
    QHBoxLayout *pScrollLyt = new QHBoxLayout(this);
    pScrollLyt->setContentsMargins(0, 0, 0, 0);
    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setStyleSheet("QScrollArea{border: none;}");
    scrollArea->setMinimumWidth(1250);
    scrollArea->setWidget(m_pMyExerciseWidget);
    //scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn); // 始终显示垂直滚动条
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // 始终显示垂直滚动条
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // 隐藏水平滚动条

    pScrollLyt->addStretch();
    pScrollLyt->addWidget(scrollArea);
    pScrollLyt->addStretch();
}
