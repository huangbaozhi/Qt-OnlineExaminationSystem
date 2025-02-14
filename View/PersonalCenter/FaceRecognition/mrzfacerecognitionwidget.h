#ifndef MRZFACERECOGNITIONWIDGET_H
#define MRZFACERECOGNITIONWIDGET_H

#include <QWidget>
#include <opencv2/opencv.hpp>
#include <opencv2/face.hpp>
#include <QImage>
#include <QPixmap>
#include <QTimer>

using namespace cv;
using namespace cv::face;
using namespace std;

class MrzFaceRecognitionDialog;

class MrzFaceRecognitionWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MrzFaceRecognitionWidget(QWidget *parent = nullptr);

signals:
    void signShowFaceImage(QImage image);

public:
    QByteArray getSaveFaceToDatabase();

private:
    void initUi();

    QImage matToQImage(const Mat &mat);

private slots:
    // 人脸采集
    void slotFaceCollection();

    // 打开摄像头并实时显示
    void startVideoStream();

    void processFrame();

    // 训练人脸识别模型
    void trainFaceRecognizer();

    void saveFaceToDatabase(const Mat &faceImg, const QString &name);



private:
    cv::VideoCapture cap;                           // 用于视频捕捉
    cv::CascadeClassifier faceCascade;              // 人脸检测分类器
    cv::Ptr<cv::face::LBPHFaceRecognizer> model;    // 人脸识别模型
    std::vector<cv::Mat> images;                    // 存储训练图像
    std::vector<int> labels;                        // 存储图像对应的标签

    MrzFaceRecognitionDialog *m_pFaceRecognitionDialog;

    QTimer *timer;

    QByteArray m_faceDataByteArray;

};

#endif // MRZFACERECOGNITIONWIDGET_H
