#ifndef MRZEXAMINATIONWIDGET_H
#define MRZEXAMINATIONWIDGET_H

#include <QWidget>

class MrzAnswerSheetWidget;
class MrzExamPaperPageWidget;
class MrzExamPaperTitleWidget;

class MrzExaminationWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MrzExaminationWidget(QWidget *parent = nullptr);

signals:

private:
    void initUi();

private:

    MrzAnswerSheetWidget *m_pAnswerSheetWidget;
    MrzExamPaperPageWidget *m_pExamPaperPageWidget;
    MrzExamPaperTitleWidget *m_pExamPaperTitleWidget;
};

#endif // MRZEXAMINATIONWIDGET_H
