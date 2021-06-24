#include <QGraphicsView>
#include <QWheelEvent>
#include "mainwindow.h"
#include <QApplication>
#include <QStyle>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      m_view(new QGraphicsView(this))
{
    /*
    setCentralWidget(m_view);
    //
QPixmap myImg(imagePath);
    QSize sizeOfImage = myImg.size();
    int height = sizeOfImage.height();
    int width = sizeOfImage.width();
    m_scene = new DrawableScene(this, width, height);
    //
    m_scene->setSceneRect(0,0,width, height);
    //m_scene->setPixMapSize(width, height);
    m_view->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    m_view->setScene(m_scene);
    m_view->setStyleSheet("background: url("+imagePath+")");
    m_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    m_view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    //setFixedSize(200, 200);
    m_view->setMaximumSize(width+widthScrollBar,height+widthScrollBar);
    m_view->ensureVisible ( m_scene->sceneRect() );
    //m_view->fitInView( m_scene->sceneRect(), Qt::KeepAspectRatio);
    */
}

