#include "mrzcamerafacedisplaywidget.h"

MrzCameraFaceDisplayWidget::MrzCameraFaceDisplayWidget(QWidget *parent)
    : QWidget{parent}
{}

void MrzCameraFaceDisplayWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);  // 启用抗锯齿，使圆形更加平滑

    // 设置画笔和颜色
    //painter.setPen(Qt::black);      // 黑色的圆形边框
    painter.setBrush(Qt::black);    // 黑色的圆形边框

    // 绘制一个圆形，参数为圆心和半径
    painter.drawEllipse(0, 10, 230, 230);  // (x, y, width, height)
}
