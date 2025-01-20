#ifndef MRZFACERECOGNITIONDIALOG_H
#define MRZFACERECOGNITIONDIALOG_H

#include <QWidget>
#include <QDialog>

class QPushButton;
class QLabel;
class MrzExaminationWidget;

class MrzFaceRecognitionDialog : public QDialog
{
    Q_OBJECT
public:
    explicit MrzFaceRecognitionDialog(QWidget *parent = nullptr);

signals:

private:
    void initUi();
    void connectFun();

private slots:
    void slotStartExam();

private:

    QPushButton *m_pCloseBtn;
    // QPushButton *m_pDirectCameraBtn;
    // QPushButton *m_pWellLitBtn;
    // QPushButton *m_pFaceNoCoverBtn;
    QPushButton *m_pStartVerificationBtn;

    MrzExaminationWidget *m_pExaminationWidget;

};

#endif // MRZFACERECOGNITIONDIALOG_H
