#ifndef GAME_H
#define GAME_H

#include "feature.h"
#include "parser.h"

#include <QGraphicsView>
#include <QWidget>
#include <QWheelEvent>
class World;
class Player;
class UI;

class Game : public QGraphicsView
{
private:
    World * world;
    Player * player;
    UI * ui;

public:
    Game(QWidget * parent = nullptr);

    // screen settings
    QGraphicsScene * scene;
    QGraphicsView * view;

    // game settings
    const int worldSize = 20;
    int SceneScale = 60;

    // list of parsed features, which will be generated during runtime
    std::vector<Cargo_type *> cargo_types;
    std::vector<Production_type *> production_types;
    std::vector<Vehicle_type *> vehicle_types;
    std::vector<Logistics_type *> logistics_types;

    void run();
    void start_dynamics();
    void initializeStructures();

    World * getWorld() {return world;};
    UI * getUI() {return ui;};
    Production_type * getProdType_byName(std::string prodName);
};

#endif // GAME_H
