#ifndef MRZMYGAMETITLEWIDGET_H
#define MRZMYGAMETITLEWIDGET_H

#include <QWidget>

class QLabel;
class QPushButton;

class MrzMyGameTitleBar : public QWidget
{
    Q_OBJECT
public:
    explicit MrzMyGameTitleBar(QWidget *parent = nullptr);

signals:

public:
    void setTitleName(QString title);

private:
    void initUi();

private:
    QLabel  *m_pTitleLbl;

    QPushButton *m_pUnderWayBtn;
    QPushButton *m_pNotFoundBtn;
    QPushButton *m_pSigningUpBtn;
    QPushButton *m_pAlreadyRegisteredBtn;
    QPushButton *m_pNotYetStartedBtn;
    QPushButton *m_pDuringTheExamBtn;
    QPushButton *m_pCompletedBtn;
    QPushButton *m_pAlreadyEndedBtn;
};

#endif // MRZMYGAMETITLEWIDGET_H
