#include "maskcreator.h"
#include "ui_maskcreator.h"
#include <QApplication>
#include <QStyle>
#include <QDebug>

MaskCreator::MaskCreator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MaskCreator)
{
    ui->setupUi(this);
    QString imagePath = getImagePath();
    QPixmap image(imagePath);
    int w = getImageWidth(image);
    int h = getImageHeight(image);
    initDrawableScene(w, h);
    initGraphicsView(imagePath, w, h);
}

MaskCreator::~MaskCreator()
{
    delete ui;
}

QString MaskCreator::getImagePath(){
    //QString imagePath = "C:/Users/sanluis/Documents/cARTELLA/msdk.png";
    return "C:/_DEV/Datasets/SPL/SSS_20190702_091059_MMS1/SSS_20190702_091059_MMS1/SRV_20190702_091704/images/jpegs/Cam-1-imgIdx-1.jpg";
}

int MaskCreator::getScrollBarWidth(){
     return qApp->style()->pixelMetric(QStyle::PM_ScrollBarExtent);
}

int MaskCreator::getImageHeight(QPixmap image){
    return image.size().height();
}

int MaskCreator::getImageWidth(QPixmap image){
    return image.size().width();
}
void MaskCreator::initDrawableScene(int w, int h){
    m_scene = new DrawableScene(this, w, h);
    m_scene->setSceneRect(0, 0, w, h);
}
void MaskCreator::initGraphicsView(QString imagePath, int w, int h){
    ui->graphicsView->setAlignment(Qt::AlignLeft | Qt::AlignTop); // align to top left corner
    ui->graphicsView->setScene(m_scene);
    ui->graphicsView->setStyleSheet("background: url("+imagePath+")");
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    int scrollbarWidth = getScrollBarWidth();
    ui->graphicsView->setMaximumSize(w + scrollbarWidth, h + scrollbarWidth);
    ui->graphicsView->ensureVisible ( m_scene->sceneRect() );
}
void MaskCreator::on_brushSize_slider_sliderReleased()
{
    //Call appropriate method to set brush size
    m_scene->setBrushSize(ui->brushSize_slider->value());
}

void MaskCreator::on_brushSize_slider_sliderMoved(int position)
{
    ui->brushSize_label->setText(QString::number(position));
}

void MaskCreator::on_brushSize_slider_valueChanged(int value)
{
    ui->brushSize_label->setText(QString::number(value));
    m_scene->setBrushSize(value);

}

void MaskCreator::on_btnSave_clicked()
{
    m_scene->saveDrawing("C:/Users/sanluis/Documents/cARTELLA/test.png");
}


void MaskCreator::on_btnEraser_clicked()
{
       m_scene->setBrushColor(Qt::white);
}

void MaskCreator::on_btnPencil_clicked()
{
    m_scene->setBrushColor(Qt::black);
}
