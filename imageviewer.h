#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <QGraphicsView>

class ImageViewer : public QGraphicsView
{
    Q_OBJECT

    QGraphicsScene scene;
    QImage image; //make local copy of reference
    QGraphicsPixmapItem *giPixmap;
    double scale;

public:

    ImageViewer(const QImage &_image); //pass image as const reference

protected:

    void keyPressEvent(QKeyEvent *evt) override;

signals:
    void mouseMovedSignal(QPoint pos, QColor color);
};


#endif // IMAGEVIEWER_H
