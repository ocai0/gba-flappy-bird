#ifndef DEBUG_BOX_H_
#define DEBUG_BOX_H_

    #include "bn_optional.h"
    #include "bn_sprite_ptr.h"
    #include "bn_sprite_items_debug.h"

    class DebugBox {
        bn::optional<bn::sprite_ptr> top_left;
        bn::optional<bn::sprite_ptr> top_right;
        bn::optional<bn::sprite_ptr> bottom_left;
        bn::optional<bn::sprite_ptr> bottom_right;
        bool isVisible;
        int x;
        int y;
        int width;
        int height;
        public:
            DebugBox(int, int, int, int);
            void setX(int);
            void setY(int);
            void update();
            void setVisible(bool);
    };

#endif