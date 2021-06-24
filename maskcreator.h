#ifndef MASKCREATOR_H
#define MASKCREATOR_H

#include <QMainWindow>
#include "drawablescene.h"

namespace Ui {
class MaskCreator;
}

class MaskCreator : public QMainWindow
{
    Q_OBJECT

public:
    explicit MaskCreator(QWidget *parent = nullptr);
    ~MaskCreator();
private slots:
    QString getImagePath();
    int getScrollBarWidth();
    int getImageHeight(QPixmap image);
    int getImageWidth(QPixmap image);
    void initDrawableScene(int w, int h);
    void initGraphicsView(QString imagePath, int w, int h);
    void on_brushSize_slider_sliderReleased();
    void on_brushSize_slider_sliderMoved(int position);
    void on_brushSize_slider_valueChanged(int value);

    void on_btnSave_clicked();

    void on_btnEraser_clicked();

    void on_btnPencil_clicked();

private:
    Ui::MaskCreator *ui;
    DrawableScene *m_scene;
};

#endif // MASKCREATOR_H
