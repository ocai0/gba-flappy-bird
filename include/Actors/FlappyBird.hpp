#ifndef FLAPPY_BIRD_H_
#define FLAPPY_BIRD_H_
    #include "bn_core.h"
    #include "bn_optional.h"
    #include "bn_keypad.h"
    #include "bn_sprite_ptr.h"
    #include "bn_sprite_animate_actions.h"
    #include "Actors/Actor.hpp"
    #include "Actors/DebugBox.hpp"

    #include "bn_sprite_items_common_bird.h"

    class FlappyBird : public Actor {
        bn::fixed x;
        bn::fixed y;
        int offsetY = 4;
        int offsetX = 4;
        int width = 10;
        int height = 8;
        bn::fixed deltaX;
        bn::fixed deltaY;
        int deltaYSign = -1;
        bn::fixed weight;
        int _timeToUpdate;
        bn::optional<DebugBox> hitbox;
        bn::optional<bn::sprite_ptr> sprite;
        bn::optional<bn::sprite_animate_action<4>> animation;
        public:
            FlappyBird(bn::fixed, bn::fixed);
            FlappyBird* setSprite(bn::sprite_ptr);
            FlappyBird* setWeight(bn::fixed);
            void setX(bn::fixed);
            void setY(bn::fixed);
            void idle();
            void update();
            FlappyBird* showHitbox();
            FlappyBird* hideHitbox();
    };
#endif