#include "game.h"
#include "rowbird.h"
#include <QBrush>
#include <QPixmap>

Game::Game()
{
    //create scene and set the size
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1200,576);
    this->setScene(scene);
    this->setFixedSize(1200,576);

    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //set gravity
    b2Vec2 gravity;
    gravity.Set(0.0,-10.0);
    world = new b2World(gravity);

    //create contact list
    contactlist = new Contacting();
    world->SetContactListener(contactlist);

    //create block , birds ,pigs
    createthings();
    activeworld();

    //set background
    this->setBackgroundBrush(QBrush(QPixmap(":image/bk.png")));

    //set ground
    b2BodyDef b2grounddef;
    b2grounddef.position.Set(0.0f,25.0f);
    b2ground = world->CreateBody(&b2grounddef);
    b2PolygonShape b2groundshape;
    b2groundshape.SetAsBox(1200,25);
    b2ground->CreateFixture(&b2groundshape,0.0f);

    //create ground
    QGraphicsPixmapItem *groundpicture;
    groundpicture = new QGraphicsPixmapItem();
    groundpicture->setPixmap(QPixmap(":/image/image/GROUND.png"));
    groundpicture->setPos(0,568-50);
    scene->addItem(groundpicture);

}

void Game::activeworld()
{
    worldtime = new QTimer();
    connect(worldtime,SIGNAL(timeout()),this,SLOT(worldtick()));
    worldtime->start(3);

}

void Game::createthings()
{
    //create blocks
    Block *block_rod1;
    block_rod1 = new Block(world,600,476);
    scene->addItem(block_rod1);

    Block *block_rod1_2;
    block_rod1_2 = new Block(world,800,476);
    scene->addItem(block_rod1_2);

    Blocklong *blocklong1;
    blocklong1 = new Blocklong(world,600,454);
    scene->addItem(blocklong1);

    //create birds
    RowBird *bird;
    bird = new RowBird(world);
    scene->addItem(bird);

    //create pigs
    Pig *pig;
    pig = new Pig(world,700,448);
    scene->addItem(pig);

}

Game::worldtick()
{
    world->Step(1.0/60.0,6,2);

}



