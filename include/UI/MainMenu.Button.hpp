#ifndef UI_BUTTON_MAIN_MENU_H_
#define UI_BUTTON_MAIN_MENU_H_

    #include "bn_optional.h"
    #include "bn_sprite_ptr.h"
    #include "bn_sprite_builder.h"

    #include "bn_sprite_items_ui_main_menu.h"

    namespace UI {
        namespace Button {
            class MainMenu {
                bn::optional<bn::sprite_ptr> spr1;
                bn::optional<bn::sprite_ptr> spr2;
                public:
                    bn::fixed x;
                    bn::fixed y;
                    MainMenu(bn::fixed, bn::fixed);
                    MainMenu* select();
                    MainMenu* unselect();
                    MainMenu* setX(bn::fixed);
                    MainMenu* setY(bn::fixed);
                    void render();
            };
        }
    }
#endif