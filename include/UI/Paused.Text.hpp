#ifndef UI_TEXT_PAUSED_H_
#define UI_TEXT_PAUSED_H_
    #include "bn_core.h"
    #include "bn_optional.h"
    #include "bn_sprite_ptr.h"
    #include "bn_sprite_builder.h"
    #include "bn_sprite_items_ui_paused.h"

    namespace UI {
        namespace Text {
            class Paused {
                bn::optional<bn::sprite_ptr> spr1;
                bn::optional<bn::sprite_ptr> spr2;
                public:
                    bn::fixed x;
                    bn::fixed y;
                    Paused(bn::fixed, bn::fixed);
                    ~Paused();
                    Paused* setX(bn::fixed);
                    Paused* setY(bn::fixed);
                    Paused* show();
                    Paused* hide();
            };
        }
    }


#endif