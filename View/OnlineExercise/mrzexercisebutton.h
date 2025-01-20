#ifndef MRZEXERCISEBUTTON_H
#define MRZEXERCISEBUTTON_H

#include <QWidget>
#include <QPushButton>

class QLabel;

class MrzExerciseButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MrzExerciseButton(QWidget *parent = nullptr);

signals:

private:
    void initUi();

public:
    void setStyleImage(QString style);
    void setTitle(QString title);
    void setQuestionNum(int number);
    void setClear(QString clear);

private:
    QLabel *m_pLogoLbl;
    QLabel *m_pTitleLbl;
    QLabel *m_pQuestionNumLbl;

    QPushButton *m_pClearBtn;

};

#endif // MRZEXERCISEBUTTON_H
