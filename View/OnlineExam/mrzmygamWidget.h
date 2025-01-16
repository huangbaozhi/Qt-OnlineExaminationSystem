#ifndef MRZMYGAMWIDGET_H
#define MRZMYGAMWIDGET_H

#include <QWidget>
#include <QPushButton>

class QLabel;

class MrzMyGameWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MrzMyGameWidget(QWidget *parent = nullptr);
    MrzMyGameWidget(const QString &title, const QDateTime &startTime, const QDateTime &endTime, int duration, int questions, int score, QWidget *parent = nullptr);

signals:

public:
    void setExamTitleName(QString title);
    void setExamStatus(QString status);

private:
    void initUi();
    void initUi(const QString &title, const QDateTime &startTime, const QDateTime &endTime, int duration, int questions, int score);

private:
    QPushButton *m_pButton;

    QLabel      *m_pLogoLbl;
    QLabel      *m_pTitleLbl;
    QLabel      *m_pStartTimeLbl;
    QLabel      *m_pEndTimeLbl;
    QLabel      *m_pExamTimeLbl;
    QLabel      *m_pProblemNumLbl;
    QLabel      *m_pMarkLbl;

};

#endif // MRZMYGAMWIDGET_H
