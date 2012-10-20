#include "myScene.h"
#include <QGraphicsItem>
#include <QtCore>

myScene::myScene(QObject *parent) : QGraphicsScene(parent), GMT(0)
{
    QImage clockImage("clock.png")
            , hourImage("hourHand.png")
            , minuteImage("minuteHand.png");

    QGraphicsPixmapItem *clockFace = new QGraphicsPixmapItem(QPixmap::fromImage(clockImage))
            , *hour = new QGraphicsPixmapItem(QPixmap::fromImage(hourImage))
            , *minute = new QGraphicsPixmapItem(QPixmap::fromImage(minuteImage));

    hourHand = hour;
    minuteHand = minute;

    clockFace->setScale(0.3);
    addItem(clockFace);

    hourHand->setScale(0.3);
    hourHand->setTransformOriginPoint(53, 397);
    hourHand->setPos(142, -200);
    addItem(hourHand);

    minuteHand->setTransformOriginPoint(43, 521);
    minuteHand->setScale(0.3);
    minuteHand->setPos(151, -323);
    addItem(minuteHand);
}

void myScene::changeGMT()
{
    GMT = abs(GMT - 30);
    //minuteHand->setRotation(GMT);
}
