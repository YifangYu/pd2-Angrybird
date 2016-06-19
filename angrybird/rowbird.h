#ifndef ROWBIRD_H
#define ROWBIRD_H
#include <Box2D/Box2D.h>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMouseEvent>
#include <userdata.h>

class RowBird : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    RowBird(b2World *g_world);
    b2Body *birdbody;
    b2World *birdworld;
    void shoot();
    void mousePressEvent(QGraphicsSceneMouseEvent * event);

public slots:
    birdmove();

};

#endif // ROWBIRD_H
