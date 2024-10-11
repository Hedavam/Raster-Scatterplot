#ifndef COLORHISTOGRAM_H
#define COLORHISTOGRAM_H

#include <QWidget>

//include imageviewer

class QHBoxLayout;
class ImageViewer;
class QVBoxLayout;
class QPixmap;
class QLabel;
class QSlider;
class QComboBox;



class ColorHistogram : public QWidget
{
    Q_OBJECT

public:
    ColorHistogram(const QImage &_image); //we pass a reference to the image, and not the whole value cuz it would be computationally expensive

/* UI Stuff */
private:
    QHBoxLayout *mainLayout;
    ImageViewer *imageViewer;
    QImage image; //need the full thing
    QVBoxLayout *sideLayout;
    QPixmap *colorHistogram;
    QLabel *colorHistogramDisplay;
    QComboBox *freqThresholdSelector;
    QLabel *sliderValDisplay;
    QSlider *colorSlider;
    QComboBox *colorSelector;

/* Logic Stuff */

    /* build frequencies */
    QVector<int> freq;
    void buildFreq(const QImage _image);

    /* for each selected color (keys), build 256 Pixmaps (values based on slider); each pixmap is a 256 x 256 slice of the color cube */
    int selectedColor; /* 0 - red, 1 - green, 2 - blue */
    int sliderVal; /* 0-255 */
    int freqThreshold; /* fixed ranges 1,2,4,8,64,128 */

    QMap<int, QVector<QPixmap>> histSlices;
    void buildHistSlices(int _selectedColor);

public slots:
    void sliderValueChanged(const int value);
    void colorComboBoxToggled(const int index);
    void thresholdComboBoxToggled(const int index);
};

#endif // COLORHISTOGRAM_H
