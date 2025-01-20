#ifndef MRZCHANGEPASSWORDWIDGET_H
#define MRZCHANGEPASSWORDWIDGET_H

#include <QWidget>

class QPushButton;
class QLabel;
class QLineEdit;

class MrzChangePasswordWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MrzChangePasswordWidget(QWidget *parent = nullptr);

signals:

private:
    void initUi();

private:
    QPushButton *m_pSaveBtn;
    QLineEdit *m_pOriginalPasswordEdit;
    QLineEdit *m_pNewPasswordEdit;
    QLineEdit *m_pEnterAgainPasswordEdit;
};

#endif // MRZCHANGEPASSWORDWIDGET_H
