#ifndef BLOCKLONG_H
#define BLOCKLONG_H
#include <Box2D/Box2D.h>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMouseEvent>
#include <QDebug>
#include <QPixmap>
#include <QTimer>

class Blocklong: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Blocklong(b2World *g_world, int x, int y);
    b2Body *blockbody;
    b2World *blockworld;

public slots:
    blockmove();

};

#endif // BLOCKLONG_H
