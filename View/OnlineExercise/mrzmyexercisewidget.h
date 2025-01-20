#ifndef MRZMYEXERCISEWIDGET_H
#define MRZMYEXERCISEWIDGET_H

#include <QWidget>

#include <QtCharts>
#include <QBarSeries>
#include <QChartView>
#include <QValueAxis>
#include <QCategoryAxis>

//using namespace QtCharts;

class MrzExerciseButton;
class QPushButton;
class QLabel;

class MrzMyExerciseWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MrzMyExerciseWidget(QWidget *parent = nullptr);

signals:

private:
    void initUi();

private:
    QLabel *m_pTitleLbl;
    QTableWidget *m_pTableWidget;

    MrzExerciseButton *m_pMrzExerciseButton;

    MrzExerciseButton *m_pMrzSpecialExerciseButton;
};

#endif // MRZMYEXERCISEWIDGET_H
