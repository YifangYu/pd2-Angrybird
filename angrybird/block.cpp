#include "block.h"

Block::Block(b2World *g_world,int x, int y)
{
    //set two world the same
    blockworld = g_world;

    //create b2body
    b2BodyDef bodydef;
    bodydef.type=b2_dynamicBody;
    bodydef.position.Set(x+37.5,576-y-37.5);
    blockbody = blockworld->CreateBody(&bodydef);
    blockbody->SetAngularDamping(0.5);
    b2CircleShape bodyshape;
    bodyshape.m_radius = 37.5f;
    b2FixtureDef fixdef;
    fixdef.shape = &bodyshape;
    fixdef.density = 10.0;
    fixdef.friction = 0.5;
    fixdef.restitution = 0.5;

    blockbody->CreateFixture(&fixdef);


    this->setPixmap(QPixmap(":/image/image/rod1.png"));
    this->setPos(x,y);
    this->setTransformOriginPoint(37.5,37.5);

    //set timer
    QTimer *blocktime;
    blocktime = new QTimer(this);
    connect(blocktime,SIGNAL(timeout()),this,SLOT(blockmove()));
    blocktime->start(12.5);

}

Block::blockmove()
{
    this->setPos(blockbody->GetPosition().x-37.5,568-blockbody->GetPosition().y-37.5);
    this->setRotation(blockbody->GetAngle()*180/3.1415926);
}
