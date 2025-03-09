#ifndef UI_BUTTON_CONTINUE_H_
#define UI_BUTTON_CONTINUE_H_

    #include "bn_optional.h"
    #include "bn_sprite_ptr.h"
    #include "bn_sprite_builder.h"

    #include "bn_sprite_items_ui_continue.h"

    namespace UI {
        namespace Button {
            class Continue {
                bn::optional<bn::sprite_ptr> spr1;
                bn::optional<bn::sprite_ptr> spr2;
                public:
                    bn::fixed x;
                    bn::fixed y;
                    Continue(bn::fixed, bn::fixed);
                    Continue* select();
                    Continue* unselect();
                    Continue* setX(bn::fixed);
                    Continue* setY(bn::fixed);
                    void render();
            };
        }
    }
#endif