#ifndef MRZEXAMPAPERPAGEWIDGET_H
#define MRZEXAMPAPERPAGEWIDGET_H

#include <QWidget>

class MrzQuestionWidget;
class QPushButton;
class QStackedWidget;

class MrzExamPaperPageWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MrzExamPaperPageWidget(QWidget *parent = nullptr);

signals:

private:
    void initUi();
    void connectFun();
    QWidget *createQuestionPage(const QString &question, const QStringList &options);

private slots:
    void slotNextQuestion();
    void slotPrevQuestion();


private:
    MrzQuestionWidget *m_pQuestionWidget;
    QStackedWidget *m_pStackedWidget;
    int currentIndex;;
    QPushButton *m_pNextButton;
    QPushButton *m_pPrevButton;
};

#endif // MRZEXAMPAPERPAGEWIDGET_H
