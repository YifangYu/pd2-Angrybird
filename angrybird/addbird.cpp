#include "addbird.h"
#include <cstdlib>
#include "game.h"
#define NUM_Bird 4     //#define NUM_Bird 4

#define Red 0
#define Black 1
#define Yellow 2
#define Blue 3

extern Game * game;

RowBird *AddBird()
{
    int bird_type;
    bird_type = rand()%NUM_Bird;
    RowBird * ptr;

    switch (bird_type) {

     case Red:
         ptr = new BirdRed(game->world);
         break;

     case Black:
         ptr = new BirdBlack(game->world);
         break;

     case Blue:
         ptr = new BirdBlue(game->world);
         break;
     case Yellow:
         ptr = new BirdYellow(game->world);
         break;

    }

    return ptr;
}
