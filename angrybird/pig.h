#ifndef PIG_H
#define PIG_H
#include <Box2D/Box2D.h>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMouseEvent>
#include <QTimer>
#include <userdata.h>

class Pig : public QObject, public QGraphicsPixmapItem
{
public:
    Pig(b2World *g_world, int x, int y);
    b2Body *pigbody;
    b2World *pigworld;

public slots:
    pigmove();
};

#endif // PIG_H
