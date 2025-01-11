#ifndef FLOOR_H_
#define FLOOR_H_
    #include "bn_optional.h"
    #include "bn_regular_bg_ptr.h"
    #include "Actors/DebugBox.hpp"
    #include "Actors/Obstacle.hpp"

    class Floor : public Obstacle {
        bn::fixed xSpeed;
        DebugBox* hitbox;
        bn::optional<bn::regular_bg_ptr> sprite;
        public:
            Floor();
            void setImage(bn::regular_bg_ptr);
            void update();
    };
#endif