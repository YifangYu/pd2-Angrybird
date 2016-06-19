#ifndef GAME_H
#define GAME_H
#include<QGraphicsView>
#include<QGraphicsScene>
#include<QObject>
#include<Box2D/Box2D.h>
#include<QTimer>
#include<QGraphicsPixmapItem>
#include<QPixmap>
#include<block.h>
#include<pig.h>
#include<contacting.h>

class Game : public QGraphicsView
{
    Q_OBJECT
public:
    Game();
    QGraphicsScene *scene;
    b2World *world;
    QTimer *worldtime;
    void activeworld();
    b2Body *b2ground;
    void createthings();
    Contacting *contactlist;
public slots:
    worldtick();



};

#endif // GAME_H
