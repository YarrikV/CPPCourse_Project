#ifndef CARGO_H
#define CARGO_H

#include "structures.h"

class Vehicle;
class Feature;

class Cargo
{
private:
    Feature * origin;
    QPointF origin_position; // location of player when player picks up cargo

    double pickup_time; // starts ticking when cargo is picked up
public:
    Cargo(Cargo_type*, Vehicle*, Feature*);
    Vehicle * carrier; // which Vehicle it is part of
    Cargo_type * type;
};

#endif // CARGO_H
