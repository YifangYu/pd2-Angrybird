#include "rowbird.h"
#include <QDebug>
#include <QPixmap>
#include <QTimer>
#include <game.h>

extern Game * game;

RowBird::RowBird(b2World *g_world)
{
    //set two world the same
    birdworld = g_world;

    //create b2body
    b2BodyDef bodydef;
    bodydef.type=b2_dynamicBody;
    bodydef.position.Set(200,200);
    birdbody = birdworld->CreateBody(&bodydef);
    birdbody->SetAngularDamping(0.5);
    b2CircleShape bodyshape;
    bodyshape.m_radius = 25.0f;
    b2FixtureDef fixdef;
    fixdef.shape = &bodyshape;
    fixdef.density = 10.0;
    fixdef.friction = 0.5;
    fixdef.restitution = 0.5;

    birdbody->CreateFixture(&fixdef);

    this->setPixmap(QPixmap(":/image/image/red.png"));
    this->setPos(birdbody->GetPosition().x-25,568-birdbody->GetPosition().y-25);
    this->setTransformOriginPoint(25,25);
    birdbody->SetActive(false);

    //add userdata
    UserData *mydata = new UserData;
    mydata->ID_NAME = QString("Bird");
    birdbody->SetUserData(mydata);

}

void RowBird::shoot()
{
    birdbody->SetActive(true);
    birdbody->SetLinearVelocity(b2Vec2(30.0,30.0));
    QTimer *birdtime;
    birdtime = new QTimer(this);
    connect(birdtime,SIGNAL(timeout()),this,SLOT(birdmove()));
    birdtime->start(12.5);
}

void RowBird::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->shoot();
}

void RowBird::destory()
{

}

RowBird::birdmove()
{
    //set view center
    game->centerOn(this);
    game->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    this->setPos(birdbody->GetPosition().x-25,568-birdbody->GetPosition().y-25);
    this->setRotation(birdbody->GetAngle()*180/3.1415926);
}
