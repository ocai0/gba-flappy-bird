#ifndef DEBUG_BOX_H_
#define DEBUG_BOX_H_

    #include "bn_optional.h"
    #include "bn_camera_ptr.h"
    #include "bn_sprite_ptr.h"
    #include "bn_sprite_items_debug.h"

    class DebugBox {
        bn::optional<bn::sprite_ptr> top_left;
        bn::optional<bn::sprite_ptr> top_right;
        bn::optional<bn::sprite_ptr> bottom_left;
        bn::optional<bn::sprite_ptr> bottom_right;
        bool isVisible;
        bn::fixed x;
        bn::fixed y;
        int width;
        int height;
        public:
            DebugBox(bn::fixed, bn::fixed, int, int);
            void setX(bn::fixed);
            void setY(bn::fixed);
            void update();
            void setVisible(bool);
            void setCamera(bn::optional<bn::camera_ptr>);
    };

#endif