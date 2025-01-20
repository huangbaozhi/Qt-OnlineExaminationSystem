#ifndef MRZEXAMPAPERTITLEWIDGET_H
#define MRZEXAMPAPERTITLEWIDGET_H

#include <QWidget>

class QLabel;
class QPushButton;

class MrzExamPaperTitleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MrzExamPaperTitleWidget(QWidget *parent = nullptr);

signals:

private:
    void initUi();

private:
    QLabel *m_pTitleLbl;
    QLabel *m_pTimeLbl;

    QPushButton *m_pSubmitExamBtn;
};

#endif // MRZEXAMPAPERTITLEWIDGET_H
