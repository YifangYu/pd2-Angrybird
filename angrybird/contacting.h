#ifndef CONTACTING_H
#define CONTACTING_H
#include "Box2D/Box2D.h"
#include "userdata.h"

class Contacting : public b2ContactListener
{
public:
    void BeginContact(b2Contact *contact);
    void EndContact(b2Contact *contact);
    void PreSolve(b2Contact * contact, const b2Manifold * oldManifold);
    void PostSolve(b2Contact * contact, const b2ContactImpulse * Impulse);
};

#endif // CONTACTING_H
