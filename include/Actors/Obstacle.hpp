#ifndef OBSTACLE_H_
#define OBSTACLE_H_
    #include "bn_core.h"
    #include "Actors/Actor.hpp"

    class Obstacle : public Actor {
        public:
            bn::fixed x;
            bn::fixed y;
            bn::fixed width;
            bn::fixed height;
            virtual void enableBlending();
            virtual void disableBlending();
            virtual ~Obstacle() = default;
    };
#endif