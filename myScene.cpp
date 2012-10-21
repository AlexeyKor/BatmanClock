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

    QTime time = QTime::currentTime();

    hourHand = hour;
    minuteHand = minute;

    clockFace->setScale(0.3);
    addItem(clockFace);

    hourHand->setScale(0.3);
    hourHand->setTransformOriginPoint(53, 397);
    hourHand->setPos(142, -200);
    hourHand->setRotation(30.0 * ((time.hour() + time.minute() / 60.0)) - GMT);
    addItem(hourHand);

    minuteHand->setTransformOriginPoint(43, 521);
    minuteHand->setScale(0.3);
    minuteHand->setPos(151, -326);
    minuteHand->setRotation(6.0 * (time.minute() + time.second() / 60.0));
    addItem(minuteHand);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(changeTime()));
         timer->start(1000);
}

void myScene::changeGMT()
{
    GMT = abs(GMT - 90);
    //minuteHand->setRotation(GMT);
}

void myScene::changeTime()
{
    QTime time = QTime::currentTime();

    hourHand->setRotation(30.0 * ((time.hour() + time.minute() / 60.0)) - GMT);
    minuteHand->setRotation(6.0 * (time.minute() + time.second() / 60.0));
}
