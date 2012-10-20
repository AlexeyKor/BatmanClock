#include "myScene.h"
#include <QGraphicsItem>
#include <QtCore>

myScene::myScene(QObject *parent) : QGraphicsScene(parent), GMT(0)
{
    QImage clock("clock.png")
            , hour("hourHand.png")
            , minute("minuteHand.png");

    QGraphicsPixmapItem *clockFace = new QGraphicsPixmapItem(QPixmap::fromImage(clock))
            , *hourHand = new QGraphicsPixmapItem(QPixmap::fromImage(hour))
            , *minuteHand = new QGraphicsPixmapItem(QPixmap::fromImage(minute));

    clockFace->setScale(0.3);
    addItem(clockFace);
    hourHand->setScale(0.3);
    hourHand->setOffset(597,270);
    addItem(hourHand);
    minuteHand->setTransformOriginPoint(0,0);
    minuteHand->setScale(0.3);
    minuteHand->rotate(75);
    minuteHand->setOffset(605,150);
    addItem(minuteHand);
}

void myScene::changeGMT()
{
    GMT = abs(GMT - 30);
}
