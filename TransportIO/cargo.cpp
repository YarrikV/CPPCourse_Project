#include "cargo.h"
#include "vehicle.h"

Cargo::Cargo(Cargo_type * t, Vehicle * carrier_vehicle, Feature * origin_production)
{
    carrier = carrier_vehicle;
    pickup_time = carrier->getWorld()->getAge();
    type = t;
    origin = origin_production;
    origin_position = carrier_vehicle->location;
}
