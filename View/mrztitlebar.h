#ifndef MRZTITLEBAR_H
#define MRZTITLEBAR_H

#include <QWidget>

class QLabel;
class QPushButton;

class mrzTitleBarWidget : public QWidget
{
    Q_OBJECT
public:
    explicit mrzTitleBarWidget(QWidget *parent = nullptr);

signals:
    void signOnlineExam(QString OnlineExam);
    void signOnlineExercise(QString OnlineExercise);
    void signPersonCenter(QString PersonCenter);

private:
    void initUi();
    void connectFun();

private slots:
    void slotOnlineButtonToggled(bool ckecked);

private:
    QLabel          *m_pLogoLbl;
    QLabel          *m_pTitleLbl;

    QPushButton     *m_pPersonCenterBtn;
    QPushButton     *m_pOnlineExamBtn;
    QPushButton     *m_pOfflineExamBtn;
    QPushButton     *m_pExerciseOnlineBtn;
};

#endif // MRZTITLEBAR_H
