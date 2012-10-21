#ifndef MYSCENE_H
#define MYSCENE_H

#include <QGraphicsScene>
#include <QTime>

class myScene : public QGraphicsScene
{
    Q_OBJECT

public:
    myScene(QObject *parent = 0);

public slots:
    void changeGMT();
    void changeTime();

private:
    int GMT;
    QGraphicsPixmapItem *hourHand, *minuteHand;
};

#endif // MYSCENE_H
