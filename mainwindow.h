#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "drawablescene.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
private:
    QGraphicsView *m_view;
    DrawableScene *m_scene;
};
#endif // MAINWINDOW_H
