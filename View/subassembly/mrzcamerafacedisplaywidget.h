#ifndef MRZCAMERAFACEDISPLAYWIDGET_H
#define MRZCAMERAFACEDISPLAYWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QImage>
#include <QLabel>

class MrzCameraFaceDisplayWidget : public QLabel
{
    Q_OBJECT
public:
    explicit MrzCameraFaceDisplayWidget(QWidget *parent = nullptr);

signals:

public:
    void setImage(const QImage &image);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QImage m_image;
};

#endif // MRZCAMERAFACEDISPLAYWIDGET_H
