#ifndef MRZEXAMPAPERPAGEWIDGET_H
#define MRZEXAMPAPERPAGEWIDGET_H

#include <QWidget>

class MrzExamPaperPageWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MrzExamPaperPageWidget(QWidget *parent = nullptr);

signals:

private:
    void initUi();
};

#endif // MRZEXAMPAPERPAGEWIDGET_H
