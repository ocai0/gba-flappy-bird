#ifndef FLAPPY_BIRD_H_
#define FLAPPY_BIRD_H_
    #include "bn_core.h"
    #include "bn_optional.h"
    #include "bn_keypad.h"
    #include "bn_sprite_ptr.h"
    #include "bn_sprite_animate_actions.h"
    #include "Actors/Actor.hpp"

    #include "bn_sprite_items_common_bird.h"

    class FlappyBird : public Actor {
        bn::fixed x;
        bn::fixed y;
        bn::fixed deltaX;
        bn::fixed deltaY;
        bn::fixed weight;
        int _timeToUpdate;
        bn::optional<bn::sprite_ptr> sprite;
        bn::optional<bn::sprite_animate_action<4>> animation;
        public:
            FlappyBird(bn::fixed, bn::fixed);
            FlappyBird* setSprite(bn::sprite_ptr);
            FlappyBird* setWeight(bn::fixed);
            void setY(bn::fixed);
            void update();
    };
#endif