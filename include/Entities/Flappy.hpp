#ifndef FLAPPY_H_
#define FLAPPY_H_

    #include "bn_sprite_ptr.h"
    #include "bn_sprite_tiles_ptr.h"
    #include "bn_sprite_items_flappy.h"
    #include "bn_sprite_animate_actions.h"

    enum class Skin { YELLOW, BLUE, RED };
    
    // values that are added to the final one and setting directly have visual impacts
    enum Delta {
        bn::fixed x;
        bn::fixed y;
        int rotation;
    };

    class Flappy {
        int x;
        int y;
        int rotation;
        bool alive;
        int offsetX; //offset to put the x coord to the top left of the sprite
        int offsetY; //offset to put the y coord to the top left of the sprite
        int width;
        int height;
        bn::sprite_ptr flappy_sprite = bn::sprite_items::flappy.create_sprite(0, 0);
        bn::sprite_animate_action<4> animation = bn::create_sprite_animate_action_forever(this->flappy_sprite, 6, bn::sprite_items::flappy.tiles_item(), 0, 1, 2, 1);
        Delta delta;
        
        public:
            Flappy(int, int, int, int, int, int);

            int getX();
            void setX(int);

            int getY();
            void setY(int);
            
            int getRotation();
            void setRotation(int);
            
            int getWidth();
            void setWidth(int);

            int getHeight();
            void setHeight(int);

            bool isAlive();
            void setAliveFlag(bool);

            void setSkin(Skin);
            void update();
    };

#endif