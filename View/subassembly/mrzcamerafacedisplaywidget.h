#ifndef MRZCAMERAFACEDISPLAYWIDGET_H
#define MRZCAMERAFACEDISPLAYWIDGET_H

#include <QWidget>
#include <QPainter>

class MrzCameraFaceDisplayWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MrzCameraFaceDisplayWidget(QWidget *parent = nullptr);

signals:

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // MRZCAMERAFACEDISPLAYWIDGET_H
