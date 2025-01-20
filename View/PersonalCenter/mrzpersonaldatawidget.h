#ifndef MRZPERSONALDATAWIDGET_H
#define MRZPERSONALDATAWIDGET_H

#include <QWidget>

class QLabel;
class QLineEdit;
class QRadioButton;
class QPushButton;
class QHBoxLayout;
class QButtonGroup;

class MrzPersonalDataWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MrzPersonalDataWidget(QWidget *parent = nullptr);

signals:

private:
    void initUi();
    void connectFun();
    void createDatabase();
    void loadDataFromDatabase();

    QString getSelectedButtonText(QButtonGroup *group);

private slots:
    void saveDataInfo();

private:

    QLineEdit *m_pRealNameEdit;
    QLineEdit *m_pPhoneEdit;
    QLineEdit *m_pEmailEdit;
    QLineEdit *m_pIDNumberEdit;
    QLineEdit *m_pSchoolEdit;

    QRadioButton *m_pSexRadioButton;
    QRadioButton *m_pGroupRadioButton;
    QRadioButton *m_pRadioButtonButton;
    QRadioButton *m_pPlayerTypeRadioButton;

    QButtonGroup *m_pSexButtonGroup;
    QButtonGroup *m_pGroupButtonGroup;
    QButtonGroup *m_pCollectionButtonGroup;
    QButtonGroup *m_pPlayerTypeButtonGroup;

    QPushButton *m_pSaveBtn;

    QHBoxLayout *m_pCollectionLyt;

};

#endif // MRZPERSONALDATAWIDGET_H
