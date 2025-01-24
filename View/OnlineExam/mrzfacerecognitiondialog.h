#ifndef MRZFACERECOGNITIONDIALOG_H
#define MRZFACERECOGNITIONDIALOG_H

#include <QWidget>
#include <QDialog>

class QPushButton;
class QLabel;
class MrzExaminationWidget;
class MrzCameraFaceDisplayWidget;

class MrzFaceRecognitionDialog : public QDialog
{
    Q_OBJECT
public:
    explicit MrzFaceRecognitionDialog(QWidget *parent = nullptr);

signals:
    void signStartVerification();
    void signFaceCollection();
    void signFaceImage(QImage image);

private:
    void initUi();
    void connectFun();

public:
    void setConfirmButtonName(QString name);

public slots:


private slots:
    void slotStartExam();
    void setImage(const QImage &image);

private:

    QPushButton *m_pCloseBtn;
    // QPushButton *m_pDirectCameraBtn;
    // QPushButton *m_pWellLitBtn;
    // QPushButton *m_pFaceNoCoverBtn;
    QPushButton *m_pStartVerificationBtn;

    MrzExaminationWidget *m_pExaminationWidget;
    MrzCameraFaceDisplayWidget *m_pFaceCameraWgt;

};

#endif // MRZFACERECOGNITIONDIALOG_H
