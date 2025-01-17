#ifndef MRZONLINEEXAMWIDGET_H
#define MRZONLINEEXAMWIDGET_H

#include <QWidget>

class QPushButton;
class QLabel;
class MrzMyGameWidget;
class MrzMyGameTitleBar;

class MrzOnlineExamWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MrzOnlineExamWidget(QWidget *parent = nullptr);

    static MrzOnlineExamWidget *instance();

signals:

private:
    void initUi();
    void connectFun();
private slots:
    void slotFaceRecognition();
private:
    MrzMyGameWidget *m_pMrzMyGame[100];
    MrzMyGameWidget *m_pMrzMyExam[100];
    MrzMyGameWidget *m_pMrzMyExercise[100];

    MrzMyGameTitleBar *m_pMyGame;
    MrzMyGameTitleBar *m_pMyExam;
    MrzMyGameTitleBar *m_pMyExercise;
};

#endif // MRZONLINEEXAMWIDGET_H
