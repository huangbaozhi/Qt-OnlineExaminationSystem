#ifndef MRZPERSONALCENTERWIDGET_H
#define MRZPERSONALCENTERWIDGET_H

#include <QWidget>

class MrzPersonalDataWidget;
class MrzChangePasswordWidget;
class QLabel;
class QPushButton;
class QStackedWidget;

class MrzPersonalCenterWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MrzPersonalCenterWidget(QWidget *parent = nullptr);

signals:

private:
    void initUi();
    void connectFun();

private slots:
    void slotSwitchPages();

private:
    MrzPersonalDataWidget *m_pPersonalDataWidget;
    MrzChangePasswordWidget *m_pChangePasswordWidget;

    QLabel *m_pLabel;
    QLabel *m_pNameLbl;
    QLabel *m_pSchoolLbl;
    QPushButton *m_pPersonalDataBtn;
    QPushButton *m_pChangePasswordBtn;
    QStackedWidget *m_pStackedWidget;
};

#endif // MRZPERSONALCENTERWIDGET_H
