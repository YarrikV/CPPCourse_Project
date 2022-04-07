#ifndef FEATURE_H
#define FEATURE_H

#include "structures.h"

#include <QVector>
#include <QPointF>
#include <QGraphicsPolygonItem>
#include <QGraphicsPixmapItem>

#include <algorithm>
class World;

class Feature : public QGraphicsPixmapItem
{
public:
    World* world;
    QVector<QPoint> locations; // tiles on which the feature stand

    // constructor
    Feature(World*, Feature_type*, QPoint);
    Feature() = default;

    // if location is valid
    bool isValidLocation(Feature_type*);
};

class ProductionFeature : public Feature
{
private:
    // Input
    QVector<int> required_cargo_in_stock;

    // Output
    bool production_enabled; // checked when cargo in stock is changed
    QVector<int> output_cargo_in_stock;
    float production_rate; // production speed

    // check if production can be enabled
    void check_production_requirements();

public:
    Production_type* type;

    ProductionFeature(World*, Production_type*, QPoint);
    // Factory type determines most initial values

    // action on long timer
    void ProductionAction();

    // input handling
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    QVector<int> get_required_cargo_in_stock() {return required_cargo_in_stock;}
    QVector<int> get_output_cargo_in_stock() {return output_cargo_in_stock;}

    void updateUI();
};

class LogisticsFeature : public Feature
{
public:
    Logistics_type type;
    LogisticsFeature(World*, Logistics_type*, QPoint);
};

class DecorationFeature : public Feature
{
public:
    Decoration_type type;
    DecorationFeature(World*, Decoration_type*, QPoint);
};



#endif // FEATURE_H
