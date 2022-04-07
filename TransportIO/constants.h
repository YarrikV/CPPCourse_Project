#ifndef CONSTANTS_H
#define CONSTANTS_H

// SCREEN VARIABLES
const int WINDOW_WIDTH = 720;
const int WINDOW_HEIGHT = 720;

// IMAGE VARIABLES
const float IMAGE_RESOLUTION__PIXELS_PER_TILE = 200.0;


// PRODUCTION VARIABLES
const float PRODUCTION_CHANCE_AT_TICK = 0.30;
const float PRODUCTION_UPGRADE_CHANCE = 0.95;
const float PRODUCTION_UPGRADE_AMOUNT = 0.15; // production *= (1+amount) if upgraded

// TIMER VARIABLES
const int TIMER_LONG_DURATION = 20000; // in ms // debugging, 20 000 normally
const int TIMER_SHORT_DURATION = 20; // in ms

// DRIVING VARIABLES
const float MAX_SPEED = 8; // amount of tiles passed in one s
const float ACCELERATION = .05; // amount of tiles increased/decreased in one s
const float FRICTION_COEFFICIENT = 0.15; // how fast a vehicle slows down
const float MINIMAL_DECELERATION = .1; // cutoff after which vehicle stop (when speed is less than this)

// PLAYER VARIABLES
const float PLAYER_INTERACTION_RANGE = 1.2; // in amount of tiles

#endif // CONSTANTS_H
