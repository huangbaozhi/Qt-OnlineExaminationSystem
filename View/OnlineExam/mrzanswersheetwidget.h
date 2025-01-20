#ifndef MRZANSWERSHEETWIDGET_H
#define MRZANSWERSHEETWIDGET_H

#include <QWidget>

/**
 * @author muruz
 * @brief The MrzAnswerSheetWidget class
 * @details 答题卡界面
 */

class QLabel;

class MrzAnswerSheetWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MrzAnswerSheetWidget(QWidget *parent = nullptr);

signals:

private:
    void initUi();

private:
    QLabel *m_pAnswerNumLbl;
    QLabel *m_pScheduleLbl;
    QLabel *m_pNameLbl;
    QLabel *m_pSexLbl;
    QLabel *m_pSchoolLbl;
};

#endif // MRZANSWERSHEETWIDGET_H
