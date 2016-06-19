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
#include<blocklong.h>
#include<QBrush>
#include<QPushButton>
#include<QImage>

class Game : public QGraphicsView
{
    Q_OBJECT
public:
    Game();
    QGraphicsScene *scene;
    b2World *world;
    QTimer *worldtime;
    b2Body *b2ground;
    Contacting *contactlist;
    QPushButton *btn_start;
    QPushButton *btn_exit;

    void activeworld();    
    void createthings();    

public slots:
    worldtick();



};

#endif // GAME_H
