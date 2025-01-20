#ifndef MRZEXAMINATIONWIDGET_H
#define MRZEXAMINATIONWIDGET_H

#include <QWidget>

class MrzExaminationWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MrzExaminationWidget(QWidget *parent = nullptr);

signals:

private:
    void initUi();

private:

};

#endif // MRZEXAMINATIONWIDGET_H
