#include "blocklong.h"

Blocklong::Blocklong(b2World *g_world, int x, int y)
{
    //set two world the same
    blockworld = g_world;

    //create b2body
    b2BodyDef bodydef;
    bodydef.type=b2_dynamicBody;
    bodydef.position.Set(x+84.5,576-y-11);
    blockbody = blockworld->CreateBody(&bodydef);
    blockbody->SetAngularDamping(0.5);

    b2PolygonShape bodyshape;
    bodyshape.SetAsBox(84.5,11);
    b2FixtureDef fixdef;
    fixdef.shape = &bodyshape;
    fixdef.density = 5.0;
    fixdef.friction = 0.5;
    fixdef.restitution = 0.02;
    blockbody->CreateFixture(&fixdef);


    this->setPixmap(QPixmap(":/image/image/gl1.png"));
    this->setPos(x,y);
    this->setTransformOriginPoint(84.5,11);

    //set timer
    QTimer *blocktime;
    blocktime = new QTimer(this);
    connect(blocktime,SIGNAL(timeout()),this,SLOT(blockmove()));
    blocktime->start(12.5);
}

Blocklong::blockmove()
{
    this->setPos(blockbody->GetPosition().x-84.5,568-blockbody->GetPosition().y-11);
    this->setRotation(blockbody->GetAngle()*180/3.1415926);
}
