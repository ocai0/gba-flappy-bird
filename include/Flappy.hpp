#ifndef FLAPPY_H_
#define FLAPPY_H_

    #include "CollisionBox.hpp"

    #include "bn_sprite_ptr.h"
    #include "bn_sprite_tiles_ptr.h"
    #include "bn_sprite_items_flappy.h"
    #include "bn_sprite_animate_actions.h"

    const int MAX_FRAMES_IN_ANIM = 4;
    const int QTY_OF_ANIMATIONS = 2;
    class Flappy {
        public:
            Flappy(int, int);
            void setX(int);
            void setY(int);
            void setXY(int, int);
            int getX();
            int getY();
            void update();
            CollisionBox getCollisionBox();
        private:
            int x;
            int y;
            int subX;
            int subY;
            bn::sprite_ptr flappy_sprite = bn::sprite_items::flappy.create_sprite(0, 0);
            bn::sprite_animate_action<4> animation = bn::create_sprite_animate_action_forever(this->flappy_sprite, 6, bn::sprite_items::flappy.tiles_item(), 0, 1, 2, 1);
            CollisionBox _bbox;
    };

#endif