#ifndef MRZLOGINDIALOG_H
#define MRZLOGINDIALOG_H

#include <QWidget>
#include <QDialog>

class QPushButton;
class QLineEdit;

class MrzLoginDialog : public QDialog
{
    Q_OBJECT
public:
    explicit MrzLoginDialog(QWidget *parent = nullptr);

signals:

private:
    void initUi();
    void connectFun();

private slots:
    void slotLogin();
    void slotCancel();

private:
    QPushButton *m_pCloseBtn;
    QPushButton *m_pLoginBtn;
    QPushButton *m_pReadAlreadyBtn;
    QPushButton *m_pScanCodeLoginBtn;
    QPushButton *m_pMoreOptionsBtn;

    QLineEdit *m_pAccountEdit;
    QLineEdit *m_pPasswordEdit;
};

#endif // MRZLOGINDIALOG_H
