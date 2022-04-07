#include "tile.h"
#include "player.h"
#include "ui.h"
#include <cmath>


// CONSTRUCTORS

Feature::Feature(World* w, Feature_type* t, QPoint topleft_location)
{
    // set world
    world = w;

    // set locations
    QPoint pos;
    for (int dx=0; dx < t->dimensions.x(); dx++) {
        for (int dy=0; dy < t->dimensions.y(); dy++) {
            pos = topleft_location + QPoint(dx, dy);
            locations.push_back(pos);
        }
    }

    // set graphic
    setPixmap((t->graphic).scaledToWidth(std::round(t->dimensions.x() * world->getGame()->SceneScale)));

    // set position of graphic
    setPos(topleft_location*world->getGame()->SceneScale);
}

ProductionFeature::ProductionFeature(World* w, Production_type* t, QPoint location) : Feature(w, t->type, location)
{
    // set type
    type = t;

    // set production rate
    production_rate = 1;

    // set stocks empty
    for (auto _=0; _<type->required_cargo_types.size(); _++) {
        required_cargo_in_stock.push_back(0);
    }

    for (auto _=0; _<type->output_cargo_types.size(); _++) {
        output_cargo_in_stock.push_back(0);
    }

    // check if production enabled from the get-go
    check_production_requirements();
}

LogisticsFeature::LogisticsFeature(World* w, Logistics_type* t, QPoint location) : Feature(w, t->type, location)
{

}

DecorationFeature::DecorationFeature(World* w, Decoration_type* t, QPoint location) : Feature(w, t->type, location)
{

}

// OTHER FUNCTIONS

bool Feature::isValidLocation(Feature_type* type)
{
    // check if all locations are of the valid_surfaces
    for (auto location : locations) {
        // if one of the tiles of the feature is not of a valid surface,
        // then the location is not valid
        if (  std::find(type->valid_surfaces.begin(), type->valid_surfaces.end(),
                        world->tiles[location.x()][location.y()]->biome) != type->valid_surfaces.end()) {

            return false;
        }

        // check if no other feature is on this tile
        if (world->tiles[location.x()][location.y()]->prod_features.size() > 0) {
            return false;
        }
    }
    return true;
}


void ProductionFeature::ProductionAction()
{
    if (!production_enabled) {return;}

    // PRODUCTION
    float random_float = (float)std::rand() / RAND_MAX;
    if (random_float <= PRODUCTION_CHANCE_AT_TICK) {

        // get the max amount of cargo in stock that can be used
        int base_cargo_used = (int)std::floor(production_rate);
        for (unsigned int i=0; i < type->required_cargo_types.size();i++) {
            // minimum value of (cargo used, cargo of type t in stock * (stock req for 1 output (=ratio))
            base_cargo_used = std::min(base_cargo_used, required_cargo_in_stock[i] * type->required_cargo_ratios[i]);
        }

        // remove required items in required_cargo_stock, keep in mind ratios
        for (unsigned int i=0; i<type->required_cargo_types.size(); i++) {
            // you can add an assert to check if amount can be substracted
            int amount_substracted = base_cargo_used * type->required_cargo_ratios[i];
            assert (required_cargo_in_stock[i] >= amount_substracted);
            required_cargo_in_stock[i] -= amount_substracted;
        }

        // add items in output_cargo (rates are all equal to 1 for now)
        for (unsigned int i=0; i<type->output_cargo_types.size(); i++) {
            output_cargo_in_stock[i] += base_cargo_used;
        }
        qDebug() << "production added for" << type->type->name << ". base amount " << base_cargo_used;

        // TODO MOVE THIS TO WHEN CARGO IS DELIVERED!!!
        // up the production rate by 15%
        if ((float)std::rand() / RAND_MAX < PRODUCTION_UPGRADE_CHANCE) {
            production_rate *= 1+PRODUCTION_UPGRADE_AMOUNT;
        }

        // update if production is enabled or not
        check_production_requirements();

        // update UI because values have changed
        updateUI();
    }
}

void ProductionFeature::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        qDebug() << "Position of mouse on " << type->type->name << ": " << event->scenePos();
    }

    // ui sets focus on the feature
    world->getGame()->getUI()->f = this;
    world->getGame()->getUI()->DisplayFeatureInfo();

    // change focus back on player
    world->player->setFocus();
}

void ProductionFeature::updateUI()
{
    if (world->getGame()->getUI()->f == this) {
        world->getGame()->getUI()->DisplayFeatureInfo();
    }
}

void ProductionFeature::check_production_requirements()
{
    // can produce if all have minimal requirements
    unsigned int i = 0;
    while (i < this->type->required_cargo_types.size()) {
        if (this->required_cargo_in_stock[i] == 0) { //should never be below 0
            production_enabled = false;
            return;
        }
        i++;
    }
    production_enabled = true;
}

