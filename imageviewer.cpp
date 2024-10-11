#include "imageviewer.h"

#include <QtWidgets>

ImageViewer::ImageViewer(const QImage &_image):image(_image),scale(1.0) { //initializing image member to value of image passed to constructor by reference, initializing scale member
    setScene(&scene);
    giPixmap = scene.addPixmap(QPixmap::fromImage(image));

    setBackgroundBrush(Qt::lightGray);
    setSceneRect(QRectF(QPointF(0,0), image.size()));
    setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);

}

void ImageViewer::keyPressEvent(QKeyEvent *evt) {
    if (evt->key()==Qt::Key_Plus || evt->key()==Qt::Key_Minus) {
        scale *= (evt->key()==Qt::Key_Plus) ? 2.0 : 0.5;
        giPixmap->setScale(scale);
        setSceneRect(QRectF(QPointF(0,0), image.size()*scale));
    } else
        QGraphicsView::keyPressEvent(evt);
}


