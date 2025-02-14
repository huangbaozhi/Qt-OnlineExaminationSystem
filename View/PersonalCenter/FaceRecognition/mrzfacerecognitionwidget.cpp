#include "mrzfacerecognitionwidget.h"
#include "View/OnlineExam/mrzfacerecognitiondialog.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QTimer>
#include <QSqlDatabase>
#include <QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QByteArray>
#include <QBuffer>
#include <QDebug>
#include <vector>

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
    // QTimer *timer = new QTimer(this);
    // connect(timer, &QTimer::timeout, this, &MrzFaceRecognitionWidget::startVideoStream);
    // timer->start(30); // 每30毫秒更新一次

    // 设置定时器每隔 30 毫秒触发一次
    QTimer *timer = new QTimer(this);
    //connect(timer, &QTimer::timeout, this, &MainWindow::updateFrame);
    connect(timer, &QTimer::timeout, this, &MrzFaceRecognitionWidget::processFrame);
    timer->start(30);  // 每 30 毫秒捕获一次图像帧

    // 训练人脸识别模型
    trainFaceRecognizer();

    // 采集人脸
    connect(m_pFaceRecognitionDialog, &MrzFaceRecognitionDialog::signFaceCollection, this, &MrzFaceRecognitionWidget::slotFaceCollection);
}

// 采集人脸
void MrzFaceRecognitionWidget::slotFaceCollection()
{
    // 捕获一帧图像
    cv::Mat frame;
    cap >> frame;
    if (frame.empty()) return;

    // 转换为灰度图
    cv::Mat gray;
    cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);

    // 检测人脸
    std::vector<cv::Rect> faces;
    faceCascade.detectMultiScale(gray, faces);

    for (size_t i = 0; i < faces.size(); i++) {
        // 提取人脸区域
        cv::Mat targetFace = gray(faces[i]);
        cv::rectangle(frame, faces[i], cv::Scalar(0, 255, 0), 2);

        // 保存目标人脸图像
        cv::imwrite("targetFace.jpg", targetFace);

        // 将图像添加到训练集
        images.push_back(targetFace);
        labels.push_back(1);  // 假设是第1号人的脸

        //saveFaceToDatabase(targetFace, "New Person");

        // 显示人脸图像
        QImage img = QImage(frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);
        emit signShowFaceImage(img);
        connect(this, &MrzFaceRecognitionWidget::signShowFaceImage, m_pFaceRecognitionDialog, &MrzFaceRecognitionDialog::signFaceImage);
        //ui->imageLabel->setPixmap(QPixmap::fromImage(img));
    }
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

void MrzFaceRecognitionWidget::processFrame()
{
    Mat frame;
    cap >> frame;  // 获取一帧图像

    if (frame.empty()) {
        qDebug() << "Error capturing frame!";
        return;
    }

    // 将图像转为灰度图
    Mat gray;
    cvtColor(frame, gray, COLOR_BGR2GRAY);

    // 检测人脸
    vector<Rect> faces;
    faceCascade.detectMultiScale(gray, faces, 1.1, 2, 0, Size(30, 30));

    for (const auto& face : faces) {
        // 绘制人脸矩形框
        rectangle(frame, face, Scalar(255, 0, 0), 2);

        // 提取人脸区域
        Mat faceROI = gray(face);

        // 进行人脸识别
        int label;
        double confidence;
        model->predict(faceROI, label, confidence);

        // 显示识别结果
        string text = "Unknown";
        if (label >= 0) {
            text = "ID: " + to_string(label) + ", Confidence: " + to_string(confidence);
        }

        putText(frame, text, Point(face.x, face.y - 10), FONT_HERSHEY_SIMPLEX, 0.9, Scalar(255, 0, 0), 2);

        // 如果识别到的人脸为新的人脸，存储到数据库
        if (label == -1) {  // 如果未识别到，则认为是新的人脸
            //saveFaceToDatabase(faceROI, "New Person");
        }
    }

    // 将 OpenCV 图像转换为 QImage 以显示在 QLabel 中
    QImage img = matToQImage(frame);
    //ui->imageLabel->setPixmap(QPixmap::fromImage(img));
    emit signShowFaceImage(img);
    connect(this, &MrzFaceRecognitionWidget::signShowFaceImage, m_pFaceRecognitionDialog, &MrzFaceRecognitionDialog::signFaceImage);
}

void MrzFaceRecognitionWidget::trainFaceRecognizer()
{
    // 假设目标图像已经保存为 targetFace.jpg
    cv::Mat targetFace = cv::imread("targetFace.jpg");
    if (targetFace.empty()) {
        qDebug() << "Error: Could not load target face!";
        return;
    }

    // 转为灰度图
    cv::Mat gray;
    cv::cvtColor(targetFace, gray, cv::COLOR_BGR2GRAY);

    // 加载人脸检测分类器
    std::vector<cv::Rect> faces;
    faceCascade.detectMultiScale(gray, faces);

    if (faces.empty()) {
        qDebug() << "Error: No face detected in target image!";
        return;
    }

    // 提取人脸区域
    cv::Mat face = gray(faces[0]);

    // 保存目标图像的人脸到训练集
    images.push_back(face);
    labels.push_back(1);  // 假设目标图像是第1号人的脸

    // 训练人脸识别模型
    model->train(images, labels);
    model->save("face_model.xml");  // 保存训练好的模型
    qDebug() << "Training complete and model saved!";
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
