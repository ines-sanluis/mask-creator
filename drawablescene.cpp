#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include "drawablescene.h"
#include <QFile>
#include <QRect>

DrawableScene::DrawableScene(QObject *parent, int width, int height)
    : QGraphicsScene(parent),
      m_modified(false),
      m_scribbling(false),
      brushSize(15),
      m_penColor(Qt::black)
{
    m_image = new QPixmap(width, height);
    m_image->fill(Qt::transparent);
    m_item = addPixmap(*m_image);
}

void DrawableScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && m_scribbling) {
        drawLineTo(event->scenePos());
        event->accept();
    }
    else QGraphicsScene::mouseMoveEvent(event);
}

void DrawableScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_lastPoint = event->scenePos();
        m_scribbling = true;
        event->accept();
    }
    else QGraphicsScene::mousePressEvent(event);
}

void DrawableScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && m_scribbling) {
        drawLineTo(event->scenePos());
        m_scribbling = false;
        event->accept();
    }
    else QGraphicsScene::mouseReleaseEvent(event);
}

void DrawableScene::drawLineTo(const QPointF &endPoint)
{
    QPainter painter(m_image);
     painter.setPen(QPen(m_penColor, brushSize, Qt::SolidLine, Qt::SquareCap,Qt::RoundJoin));
    if(m_penColor == Qt::black){

        QPainterPath path;
        path.moveTo(endPoint);
        path.lineTo(m_lastPoint);
        painter.drawPath(path);;
       // painter.drawLine(m_lastPoint, endPoint);
    }
    else{
       painter.setPen(Qt::NoPen);
       painter.setBrush(Qt::NoBrush);
       QPainterPath path;
       path.moveTo(endPoint);
       path.lineTo(m_lastPoint);
       painter.drawPath(path);;
    }

   // painter.drawLine(m_lastPoint, endPoint);
    m_modified = true;
    m_lastPoint = endPoint;
    m_item->setPixmap(*m_image);
}


void DrawableScene::setBrushSize(int selectedSize) {
    brushSize = selectedSize;
}
void DrawableScene::setBrushColor(QColor color) {
    m_penColor = color;
}

void DrawableScene::saveDrawing(QString path){
    QFile file(path);
    file.open(QIODevice::WriteOnly);
    m_image->save(&file, "PNG");
}
