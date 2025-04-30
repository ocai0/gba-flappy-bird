#ifndef UI_TEXT_GAMELOGO_H_
#define UI_TEXT_GAMELOGO_H_
    #include "bn_core.h"
    #include "bn_optional.h"
    #include "bn_sprite_ptr.h"
    #include "bn_sprite_builder.h"
    #include "bn_sprite_items_ui_flappy_bird_logo.h"
    #include "bn_sprite_items_ui_advance_logo.h"

    namespace UI {
        namespace Text {
            class GameLogo {
                bn::optional<bn::sprite_ptr> logo1;
                bn::optional<bn::sprite_ptr> logo2;
                bn::optional<bn::sprite_ptr> logo3;

                bn::optional<bn::sprite_ptr> advance1;
                bn::optional<bn::sprite_ptr> advance2;
                public:
                    bn::fixed x;
                    bn::fixed y;
                    GameLogo(bn::fixed, bn::fixed);
                    ~GameLogo();
                    GameLogo* setX(bn::fixed);
                    GameLogo* setY(bn::fixed);
                    GameLogo* show();
                    GameLogo* hide();
            };
        }
    }
#endif