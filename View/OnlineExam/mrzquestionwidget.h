#ifndef MRZQUESTIONWIDGET_H
#define MRZQUESTIONWIDGET_H

#include <QWidget>

class QLabel;

class MrzQuestionWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MrzQuestionWidget(QWidget *parent = nullptr);

    MrzQuestionWidget(const QString &question, const QStringList &options, QWidget *parent = nullptr);

signals:

private:
    void initUi();

private:
    QString mQuestion;
    QStringList mOptions;

    QLabel *m_pQuestionLbl;
    QLabel *m_pQuestionNum;
    QLabel *m_pCountDownLbl;
};

#endif // MRZQUESTIONWIDGET_H
