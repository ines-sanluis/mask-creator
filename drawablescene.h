#ifndef DRAWABLESCENE_H
#define DRAWABLESCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

class DrawableScene : public QGraphicsScene
{
public:
    explicit DrawableScene(QObject *parent = nullptr, int width = 200, int height = 200);
    void setBrushSize(int selectedSize);
    void setBrushColor(QColor color);
    void saveDrawing(QString path);
private:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void drawLineTo(const QPointF &endPoint);
    QString getImagePath();

    bool m_modified;
    bool m_scribbling;
    int brushSize;
    QColor m_penColor;
    QPointF m_lastPoint;
    QPixmap *m_image;
    QGraphicsPixmapItem *m_item;
};

#endif // DRAWABLESCENE_H
