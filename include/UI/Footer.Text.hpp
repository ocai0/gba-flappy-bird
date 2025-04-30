#ifndef UI_TEXT_FOOTER_H_
#define UI_TEXT_FOOTER_H_

    #include "bn_optional.h"
    #include "bn_sprite_ptr.h"
    #include "bn_sprite_builder.h"

    #include "bn_sprite_items_ui_gears_footer.h"

    namespace UI {
        namespace Text {
            class Footer {
                bn::optional<bn::sprite_ptr> spr1;
                bn::optional<bn::sprite_ptr> spr2;
                public:
                    bn::fixed x;
                    bn::fixed y;
                    Footer(bn::fixed, bn::fixed);
                    Footer* setX(bn::fixed);
                    Footer* setY(bn::fixed);
                    Footer* setRenderPriority(int);
                    void render();
                    ~Footer();
            };
        }
    }
#endif