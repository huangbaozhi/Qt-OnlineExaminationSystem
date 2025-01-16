#ifndef MRZONLINEEXERCISEWIDGET_H
#define MRZONLINEEXERCISEWIDGET_H

#include <QWidget>

class MrzMyExerciseWidget;

class MrzOnlineExerciseWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MrzOnlineExerciseWidget(QWidget *parent = nullptr);

signals:

private:
    void initUi();

private:
    MrzMyExerciseWidget *m_pMyExerciseWidget;

};

#endif // MRZONLINEEXERCISEWIDGET_H
