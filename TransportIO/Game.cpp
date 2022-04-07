#include "Game.h"
#include "ui.h"
#include "world.h"
#include "player.h"


#include <QDebug>
#include <QDir>
#include <QString>
#include <typeinfo>

extern std::string AbsoluteProjectPath;

Game::Game(QWidget * parent): QGraphicsView(parent)
{ // Constructor of Game
    // create scene, where all items are put in
    scene = new QGraphicsScene();

    // set Scene to be able to accomodate the whole world
    scene->setSceneRect(0,0,worldSize*SceneScale, worldSize*SceneScale);

//    // remove Scrollbars
//    scene->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    scene->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // get list of items that can be set in the world
    // Initialize parser
    parser struct_parser = parser();

    // parse Cargo types:
    cargo_types = struct_parser.parseCargos(AbsoluteProjectPath + "/inih/cargo_types.txt");
    qDebug() << "Cargo types parsed... #" << cargo_types.size();
}

void Game::run()
{
    initializeStructures();

    // create the world
    world = new World(this);

    // Initialize player
    player = new Player(world);

    // set view, subspace of scene, which is visible in the window
    view = new QGraphicsView(scene);

    //  fixed size
    view->setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT),

    // remove Scrollbars
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    view->setDragMode(QGraphicsView::NoDrag);
    qDebug() << view->dragMode();

    // center on player
    view->centerOn(player->pos());
    view->show();

    // add UI
    ui = new UI(this, player);


    start_dynamics();
}

void Game::start_dynamics()
{
    // start world timers
    world->productionCycleTimer->start(TIMER_LONG_DURATION);
    world->vehicleMoverTimer->start(TIMER_SHORT_DURATION);
}

void Game::initializeStructures()
{
    // PARSER part 2, because cargo types must already by included in extern Game * game.
    // folder of all the inis
    std::string ini_path = AbsoluteProjectPath + "/inih/";
    parser struct_parser = parser();

    // parse Productions
    production_types = struct_parser.parseProductions(ini_path + "productions.txt");
    qDebug() << "Production types parsed... #" << production_types.size();

    // parse Vehicles
    vehicle_types = struct_parser.parseVehicles(ini_path + "vehicles.txt");
    qDebug() << "Vehicle types parsed... #" << vehicle_types.size();

    // parse Logistics
    logistics_types = struct_parser.parseGeneralFeaturesfromFile<Logistics_type>(ini_path + "logistics.txt");
    qDebug() << "Logistics types parsed... #" << logistics_types.size();
}

Production_type *Game::getProdType_byName(std::string prodName)
{
    for (auto prodType : production_types) {
        if (prodType->type->name.toStdString() == prodName) {return prodType;}
    }
    throw std::runtime_error("Error: Cannot find production type with name " + prodName);
}


