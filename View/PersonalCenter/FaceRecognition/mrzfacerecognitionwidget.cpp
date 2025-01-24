#include "mrzfacerecognitionwidget.h"
#include "View/OnlineExam/mrzfacerecognitiondialog.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QTimer>

MrzFaceRecognitionWidget::MrzFaceRecognitionWidget(QWidget *parent)
    : QWidget{parent}
{
    initUi();
}

void MrzFaceRecognitionWidget::initUi()
{
    // 加载人脸检测分类器
    if (!faceCascade.load("E:\\Qt\\openCV3.4.12\\opencv-3.4.5\\data\\haarcascades\\haarcascade_frontalface_default.xml")) {
        qDebug() << "Error: Could not load classifier!";
        return;
    }

    // 初始化人脸识别模型
    model = cv::face::LBPHFaceRecognizer::create();

    // 打开摄像头
    cap.open(0);
    if (!cap.isOpened()) {
        qDebug() << "Error: Cannot open the camera!";
        return;
    }

    QHBoxLayout *pMainLyt = new QHBoxLayout(this);
    pMainLyt->setContentsMargins(0, 0, 0, 0);

    m_pFaceRecognitionDialog = new MrzFaceRecognitionDialog;
    m_pFaceRecognitionDialog->setConfirmButtonName("人脸采集");
    pMainLyt->addWidget(m_pFaceRecognitionDialog);

    // 采集人脸
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MrzFaceRecognitionWidget::startVideoStream);
    timer->start(30); // 每30毫秒更新一次


}

void MrzFaceRecognitionWidget::slotFaceCollection()
{
    // 将图像转换为灰度图
    cv::Mat gray;
    cv::Mat frame;
    cap >> frame;
    cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);

    // 进行人脸检测
    std::vector<cv::Rect> faces;
    faceCascade.detectMultiScale(gray, faces);

    // 在图像中绘制人脸框
    for (size_t i = 0; i < faces.size(); i++)
    {
        cv::rectangle(frame, faces[i], cv::Scalar(255, 0, 0), 2);
        //saveFaceToDatabase(frame, "New Person");
    }
    QImage img = matToQImage(frame);



}

void MrzFaceRecognitionWidget::startVideoStream()
{
    // 将图像转换为灰度图
    cv::Mat gray;
    cv::Mat frame;
    cap >> frame;
    cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);

    // 进行人脸检测
    std::vector<cv::Rect> faces;
    faceCascade.detectMultiScale(gray, faces);

    // 在图像中绘制人脸框
    for (size_t i = 0; i < faces.size(); i++)
    {
        cv::rectangle(frame, faces[i], cv::Scalar(255, 0, 0), 2);
        //saveFaceToDatabase(frame, "New Person");
    }

    // 转换为 QImage 以便在 Qt 中显示
    // QImage img = QImage((const uchar*)frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);
    // img = img.rgbSwapped();

    QImage img = matToQImage(frame);
    //m_pFaceRecognitionDialog->setImage(img);
    emit signShowFaceImage(img);
    connect(this, &MrzFaceRecognitionWidget::signShowFaceImage, m_pFaceRecognitionDialog, &MrzFaceRecognitionDialog::signFaceImage);
}

QImage MrzFaceRecognitionWidget::matToQImage(const Mat &mat)
{
    // 将 OpenCV 图像（Mat）转换为 QImage
    if (mat.channels() == 3)
    {
        // 转换为 RGB 图像
        cvtColor(mat, mat, COLOR_BGR2RGB);
        return QImage(mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
    } else if (mat.channels() == 1)
    {
        // 转换为灰度图像
        return QImage(mat.data, mat.cols, mat.rows, mat.step, QImage::Format_Grayscale8);
    }
    return QImage();
}
