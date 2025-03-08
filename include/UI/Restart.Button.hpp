#ifndef UI_BUTTON_RESTART_H_
#define UI_BUTTON_RESTART_H_

    #include "bn_optional.h"
    #include "bn_sprite_ptr.h"
    #include "bn_sprite_builder.h"

    #include "bn_sprite_items_ui_restart.h"

    namespace UI {
        namespace Button {
            class Restart {
                bn::optional<bn::sprite_ptr> spr1;
                bn::optional<bn::sprite_ptr> spr2;
                public:
                    bn::fixed x;
                    bn::fixed y;
                    Restart(bn::fixed, bn::fixed);
                    Restart* select();
                    Restart* unselect();
                    Restart* setX(bn::fixed);
                    Restart* setY(bn::fixed);
                    void render();
            };
        }
    }
#endif