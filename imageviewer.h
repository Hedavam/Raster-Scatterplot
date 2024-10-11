#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <QGraphicsView>

class ImageViewer : public QGraphicsView
{
    Q_OBJECT

    QGraphicsScene scene;
    QImage image;
    QGraphicsPixmapItem *giPixmap;
    double scale;

public:

    ImageViewer(const QImage &_image);

protected:

    void keyPressEvent(QKeyEvent *evt) override;

signals:
    void mouseMovedSignal(QPoint pos, QColor color);
};


#endif // IMAGEVIEWER_H
