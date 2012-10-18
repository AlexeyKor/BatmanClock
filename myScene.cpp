#include "myScene.h"
#include <QGraphicsItem>
#include <QtCore>

myScene::myScene(QObject *parent) : QGraphicsScene(parent), isGMT(false)
{
    addEllipse(QRectF(-100.0, -100.0, 100.0, 100.0));
}

void myScene::GMT()
{
    isGMT = !isGMT;
}

void myScene::timerEvent()
{
}
