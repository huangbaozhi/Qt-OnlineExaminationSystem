#ifndef MRZPERSONALDATAWIDGET_H
#define MRZPERSONALDATAWIDGET_H

#include <QWidget>
#include <QAbstractButton>

class QLabel;
class QLineEdit;
class QRadioButton;
class QPushButton;
class QHBoxLayout;
class QButtonGroup;
class MrzFaceRecognitionDialog;
class MrzFaceRecognitionWidget;

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
    void slotFaceCollection(QAbstractButton *button);

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

    //MrzFaceRecognitionDialog *m_pMrzFaceRecognitionDialog;
    MrzFaceRecognitionWidget *m_pMrzFaceRecognitionWidget;

    QByteArray m_faceDataByteArray;

};

#endif // MRZPERSONALDATAWIDGET_H
