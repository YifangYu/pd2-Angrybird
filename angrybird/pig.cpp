#include "pig.h"
#include <QDebug>

Pig::Pig(b2World *g_world,int x,int y)
{
    //set two world the same
    pigworld = g_world;

    //create b2body
    b2BodyDef bodydef;
    bodydef.type=b2_dynamicBody;
    bodydef.position.Set(x+36.5,576-y-35);
    pigbody = pigworld->CreateBody(&bodydef);
    pigbody->SetAngularDamping(0.5);
    b2CircleShape bodyshape;
    bodyshape.m_radius = 36.5f;
    b2FixtureDef fixdef;
    fixdef.shape = &bodyshape;
    fixdef.density = 50.0;
    fixdef.friction = 0.5;
    fixdef.restitution = 0.5;

    pigbody->CreateFixture(&fixdef);


    this->setPixmap(QPixmap(":/image/image/pig.gif"));
    this->setPos(x,y);
    this->setTransformOriginPoint(36.5,35);

    //set timer
    QTimer *pigtime;
    pigtime = new QTimer(this);
    connect(pigtime,SIGNAL(timeout()),this,SLOT(pigmove()));
    pigtime->start(12.5);

    //add userdata
    UserData *mydata = new UserData;
    mydata->ID_NAME = QString("Pig");
    pigbody->SetUserData(mydata);
    UserData * udStruct = (UserData *)pigbody->GetUserData();

}

Pig::pigmove()
{
    this->setPos(pigbody->GetPosition().x-36.5,568-pigbody->GetPosition().y-35);
    this->setRotation(pigbody->GetAngle()*180/3.1415926);
}
