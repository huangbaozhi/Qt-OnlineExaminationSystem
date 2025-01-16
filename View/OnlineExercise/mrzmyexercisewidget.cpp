#include "mrzmyexercisewidget.h"
#include "mrzexercisebutton.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QList>

const QString styleLabel = QString("QLabel{"
                                   "line-height: 29px;"
                                    "color: rgb(58,62,81);"
                                    "font-size: 20px;"
                                    "text-align: left;"
                                    "font-family: SourceHanSansSC-regular;"
                                    "border-bottom: 1px solid rgba(0,0,0,0.1);;"
                                    "border-left: none;"
                                    "border-top: none;"
                                    "border-right: none;}"
                                   );

MrzMyExerciseWidget::MrzMyExerciseWidget(QWidget *parent)
    : QWidget{parent}
{
    setMinimumSize(1200, 964);
    initUi();
}

void MrzMyExerciseWidget::initUi()
{
    QHBoxLayout *pMainLyt = new QHBoxLayout(this);
    pMainLyt->setContentsMargins(0, 0, 0, 0);

    QVBoxLayout *pMainVLyt = new QVBoxLayout;
    pMainVLyt->setContentsMargins(0, 0, 0, 0);
    pMainLyt->addLayout(pMainVLyt);

    // 我的练习
    QWidget *pMyExerciseWgt = new QWidget(this);
    pMyExerciseWgt->setFixedHeight(170);
    pMyExerciseWgt->setStyleSheet("QWidget{background-color: rgba(255,255,255,1);}");
    QHBoxLayout *pMyExerciseLyt = new QHBoxLayout(pMyExerciseWgt);
    pMyExerciseLyt->setContentsMargins(0, 0, 0, 0);

    QVBoxLayout *pVMyExerciseLyt = new QVBoxLayout;
    pVMyExerciseLyt->setContentsMargins(0, 0, 0, 0);
    pMyExerciseLyt->addSpacing(20);
    pMyExerciseLyt->addLayout(pVMyExerciseLyt);
    pMyExerciseLyt->addSpacing(20);

    QLabel *pMyExerciseLbl = new QLabel(this);
    pMyExerciseLbl->setFixedHeight(60);
    pMyExerciseLbl->setText("我的练习");
    pMyExerciseLbl->setStyleSheet(styleLabel);
    pVMyExerciseLyt->addWidget(pMyExerciseLbl);

    QHBoxLayout *pExerciseButtonLyt = new QHBoxLayout;
    pExerciseButtonLyt->setContentsMargins(0, 0, 0, 0);

    for (int i = 0; i < 3; ++i)
    {
        m_pMrzExerciseButton[i] = new MrzExerciseButton;
        pExerciseButtonLyt->addWidget(m_pMrzExerciseButton[i]);
    }
    pVMyExerciseLyt->addLayout(pExerciseButtonLyt);

    // 专项练习
    QWidget *pSpecialExerciseWgt = new QWidget(this);
    pSpecialExerciseWgt->setFixedHeight(170);
    pSpecialExerciseWgt->setStyleSheet("QWidget{background-color: rgba(255,255,255,1);}");
    QHBoxLayout *pSpecialExerciseLyt = new QHBoxLayout(pSpecialExerciseWgt);
    pSpecialExerciseLyt->setContentsMargins(0, 0, 0, 0);

    QVBoxLayout *pVSpecialExerciseLyt = new QVBoxLayout;
    pVSpecialExerciseLyt->setContentsMargins(0, 0, 0, 0);
    pSpecialExerciseLyt->addSpacing(20);
    pSpecialExerciseLyt->addLayout(pVSpecialExerciseLyt);
    pSpecialExerciseLyt->addSpacing(20);

    QLabel *pSpecialExerciseLbl = new QLabel(this);
    pSpecialExerciseLbl->setFixedHeight(60);
    pSpecialExerciseLbl->setText("专项练习");
    pSpecialExerciseLbl->setStyleSheet(styleLabel);
    pVSpecialExerciseLyt->addWidget(pSpecialExerciseLbl);

    QHBoxLayout *pSpecialExerciseButtonLyt = new QHBoxLayout;
    pSpecialExerciseButtonLyt->setContentsMargins(0, 0, 0, 0);

    for (int i = 0; i < 3; ++i)
    {
        m_pMrzSpecialExerciseButton[i] = new MrzExerciseButton;
        pSpecialExerciseButtonLyt->addWidget(m_pMrzSpecialExerciseButton[i]);
    }
    pVSpecialExerciseLyt->addLayout(pSpecialExerciseButtonLyt);

    // 练习数据
    QWidget *pPracticeDataWgt = new QWidget(this);
    pPracticeDataWgt->setStyleSheet("QWidget{background-color: rgba(255,255,255,1);}");
    // QHBoxLayout *pPracticeDataLyt = new QHBoxLayout(pPracticeDataWgt);
    // pPracticeDataLyt->setContentsMargins(0, 0, 0, 0);

    QVBoxLayout *pVPracticeDataLyt = new QVBoxLayout(pPracticeDataWgt);
    pVPracticeDataLyt->setContentsMargins(0, 0, 0, 0);

    QLabel *pPracticeDataLbl = new QLabel(this);
    pPracticeDataLbl->setText("练习数据");
    pPracticeDataLbl->setFixedHeight(60);
    pPracticeDataLbl->setStyleSheet(styleLabel);
    pVPracticeDataLyt->addWidget(pPracticeDataLbl);

    QHBoxLayout *pHPracticeDataLyt = new QHBoxLayout;
    pHPracticeDataLyt->setContentsMargins(0, 0, 0, 0);
    pVPracticeDataLyt->addLayout(pHPracticeDataLyt);

    // 当前练习
    QVBoxLayout *pVDayPracticeLyt = new QVBoxLayout;
    pVDayPracticeLyt->setContentsMargins(0, 0, 0, 0);
    pHPracticeDataLyt->addLayout(pVDayPracticeLyt);

    QHBoxLayout *pDayPracticeLyt = new QHBoxLayout;
    pDayPracticeLyt->setContentsMargins(0, 0, 0, 0);
    QLabel *pDayPracticeTitleLbl = new QLabel(this);
    pDayPracticeTitleLbl->setText("当天练习");
    QLabel *pDayPracticeTimeLbl = new QLabel(this);
    pDayPracticeTimeLbl->setText("8-17");
    pDayPracticeLyt->addWidget(pDayPracticeTitleLbl);
    pDayPracticeLyt->addWidget(pDayPracticeTimeLbl);
    pDayPracticeLyt->addStretch();
    pVDayPracticeLyt->addLayout(pDayPracticeLyt);

    m_pTableWidget = new QTableWidget(this);
    m_pTableWidget->setFixedSize(600, 310);
    m_pTableWidget->setRowCount(7);   // 设置表格行数
    m_pTableWidget->setColumnCount(3); // 设置表格列数
    // QStringList headerLabel;
    // headerLabel << "练习时长" << "练习次数" << "练习题数" << "正确率";
    // m_pTableWidget->setHorizontalHeaderLabels(headerLabel);

    m_pTableWidget->setHorizontalHeaderLabels(QStringList() << "日期" << "练习次数" << "练习题数");

    // 填充表格数据
    QStringList dates = {"8-11", "8-12", "8-13", "8-14", "8-15", "8-16", "8-17"};
    QList<int> practiceCounts1 = {5, 8, 3, 6, 7, 9, 4};  // 练习次数
    QList<int> problemCounts1 = {10, 15, 8, 12, 14, 18, 9}; // 练习题数

    for (int i = 0; i < dates.size(); ++i) {
        m_pTableWidget->setItem(i, 0, new QTableWidgetItem(dates[i]));
        m_pTableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(practiceCounts1[i])));
        m_pTableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(problemCounts1[i])));
    }

    pVDayPracticeLyt->addWidget(m_pTableWidget);

    // 最近一周练习数据
    QVBoxLayout *pVLastWeekLyt = new QVBoxLayout;
    pVLastWeekLyt->setContentsMargins(0, 0, 0, 0);
    pHPracticeDataLyt->addLayout(pVLastWeekLyt);

    QHBoxLayout *pLastWeekLyt = new QHBoxLayout;
    pLastWeekLyt->setContentsMargins(0, 0, 0, 0);
    pVLastWeekLyt->addLayout(pLastWeekLyt);

    QLabel *pLastWeekTitleLbl = new QLabel(this);
    pLastWeekTitleLbl->setText("最近一周练习数据");
    QLabel *pLastWeekTimeLbl = new QLabel(this);
    pLastWeekTimeLbl->setText("8-17~8-11");
    pLastWeekLyt->addWidget(pLastWeekTitleLbl);
    pLastWeekLyt->addWidget(pLastWeekTimeLbl);
    pLastWeekLyt->addStretch();

    // 直方图
    // 创建柱状图系列
    QBarSet *set1 = new QBarSet("练习次数");
    QBarSet *set2 = new QBarSet("练习题数");

    // 填充数据
    *set1 << 5 << 8 << 3 << 6 << 7 << 9 << 4;  // 练习次数
    *set2 << 10 << 15 << 8 << 12 << 14 << 18 << 9; // 练习题数

    QBarSeries *series = new QBarSeries();
    series->append(set1);
    series->append(set2);

    // 创建图表
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("练习次数和练习题数");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // 设置横轴
    QStringList categories = {"8-11", "8-12", "8-13", "8-14", "8-15", "8-16", "8-17"};
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // 设置纵轴
    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("数量");
    axisY->setRange(0, 20); // 根据你的数据调整范围
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // 创建图表视图
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // 将图表视图添加到布局中
    pVLastWeekLyt->addWidget(chartView);

    pMainVLyt->addSpacing(25);
    pMainVLyt->addWidget(pMyExerciseWgt);
    pMainVLyt->addSpacing(25);
    pMainVLyt->addWidget(pSpecialExerciseWgt);
    pMainVLyt->addSpacing(25);
    pMainVLyt->addWidget(pPracticeDataWgt);
    pMainVLyt->addStretch();
}
