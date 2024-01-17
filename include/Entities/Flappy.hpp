#ifndef FLAPPY_H_
#define FLAPPY_H_

    #include "bn_sprite_ptr.h"
    #include "bn_sprite_tiles_ptr.h"
    #include "bn_sprite_items_flappy.h"
    #include "bn_sprite_animate_actions.h"
    #include "Entities/DebugBox.hpp"
    #include "Math.hpp"


    enum class Skin { YELLOW, BLUE, RED };
    
    // values that are added to the final one and setting directly have visual impacts
    typedef struct {
        bn::fixed x;
        bn::fixed y;
        int rotation;
    } Delta;

    class Flappy {
        bn::fixed x;
        bn::fixed y;
        int rotation;
        bool alive;
        bool colliding;
        int offsetX; //offset to put the x coord to the top left of the sprite
        int offsetY; //offset to put the y coord to the top left of the sprite
        int width;
        int height;
        bn::sprite_ptr flappy_sprite = bn::sprite_items::flappy.create_sprite(0, 0);
        bn::sprite_animate_action<4> animation = bn::create_sprite_animate_action_forever(this->flappy_sprite, 6, bn::sprite_items::flappy.tiles_item(), 0, 1, 2, 1);
        Delta delta;
        DebugBox debugBox;
        
        public:
            Flappy(bn::fixed, bn::fixed, int, int, int, int);

            bn::fixed getX();
            void setX(bn::fixed);

            bn::fixed getY();
            void setY(bn::fixed);
            
            int getRotation();
            void setRotation(int);
            
            int getWidth();
            void setWidth(int);

            int getHeight();
            void setHeight(int);

            bool isAlive();
            void setAliveFlag(bool);

            bool isColliding();
            void setCollidingFlag(bool);

            void setSkin(Skin);
            void showSprite(bool);
            void playDeathAnimation();
            void showDebugBox(bool);
            void update();
    };

#endif