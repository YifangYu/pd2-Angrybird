#include "contacting.h"
#include <QDebug>
void Contacting::BeginContact(b2Contact *contact)
{
    b2Fixture * fa = contact->GetFixtureA();
    b2Fixture * fb = contact->GetFixtureB();

    UserData * fa_userdata = (UserData*)fa->GetBody()->GetUserData();
    UserData * fb_userdata = (UserData*)fb->GetBody()->GetUserData();
    if(fa->GetDensity() == 0 || fb->GetDensity() == 0)
    {
        return;
    }

//    if(fa_userdata->ID_NAME == QString("1"))
//    {
//        if(fb_userdata->ID_NAME == QString("2"))
//        {
//            //qDebug() << "hit";
//        }
//            //qDebug() << 123;
//    }

//    if(fb_userdata->ID_NAME == QString("2"))
//    {
//        if(fa_userdata->ID_NAME == QString("1"))
//            qDebug() << 123;
//    }
}

void Contacting::EndContact(b2Contact *contact)
{

}

void Contacting::PreSolve(b2Contact *contact, const b2Manifold *oldManifold)
{

}

void Contacting::PostSolve(b2Contact *contact, const b2ContactImpulse *Impulse)
{

}
