#ifndef MYSCENE_H
#define MYSCENE_H

#include <QGraphicsScene>

class myScene : public QGraphicsScene
{
    Q_OBJECT

public:
    myScene(QObject *parent = 0);

public slots:
    void GMT();

protected:
    void timerEvent();

private:
    bool isGMT;
};

#endif // MYSCENE_H
