#include "myScene.h"
#include <QGraphicsItem>
#include <QtCore>

myScene::myScene(QObject *parent) : QGraphicsScene(parent), isGMT(false)
{
    QImage clock("qt.png");
    QGraphicsPixmapItem *clockSceneItem = new QGraphicsPixmapItem(QPixmap::fromImage(clock));
    addItem(clockSceneItem);
}

void myScene::GMT()
{
    isGMT = !isGMT;
}

void myScene::timerEvent()
{
}
