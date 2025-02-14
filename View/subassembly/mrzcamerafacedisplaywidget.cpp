#include "mrzcamerafacedisplaywidget.h"

MrzCameraFaceDisplayWidget::MrzCameraFaceDisplayWidget(QWidget *parent)
    : QLabel{parent}
{}

void MrzCameraFaceDisplayWidget::setImage(const QImage &image)
{
    //m_image = image;
    //update(); // 触发重绘
    this->setPixmap(QPixmap::fromImage(image));
}

void MrzCameraFaceDisplayWidget::paintEvent(QPaintEvent *event)
{
    // QPainter painter(this);
    // painter.setRenderHint(QPainter::Antialiasing);  // 启用抗锯齿，使圆形更加平滑

    // // 设置画笔和颜色
    // //painter.setPen(Qt::black);      // 黑色的圆形边框
    // painter.setBrush(Qt::black);    // 黑色的圆形边框

    // // 绘制一个圆形，参数为圆心和半径
    // painter.drawEllipse(0, 10, 230, 230);  // (x, y, width, height)

    // if (!m_image.isNull()) {
    //     // 将图像绘制到窗口中
    //     painter.drawImage(0, 10, m_image);
    // }
}
