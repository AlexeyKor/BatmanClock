#include "myScene.h"
#include <QGraphicsItem>
#include <QtCore>

myScene::myScene(QObject *parent) : QGraphicsScene(parent), isGMT(false)
{
    //addEllipse(QRectF(-200.0, -200.0, 200.0, 200.0));
    //addRect(QRectF(-200.0, -200.0, 200.0, 200.0));
    QImage* qimage = new QImage("22761.jpg");
        QGraphicsPixmapItem pixmapItem(QPixmap::fromImage(*qimage));
        addItem(&pixmapItem);
}

void myScene::GMT()
{
    isGMT = !isGMT;
}

void myScene::timerEvent()
{
}
