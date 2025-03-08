#ifndef UI_TEXT_GAMEOVER_H_
#define UI_TEXT_GAMEOVER_H_
    #include "bn_core.h"
    #include "bn_optional.h"
    #include "bn_sprite_ptr.h"
    #include "bn_sprite_builder.h"
    #include "bn_sprite_items_ui_game_over.h"

    namespace UI {
        namespace Text {
            class GameOver {
                bn::optional<bn::sprite_ptr> spr1;
                bn::optional<bn::sprite_ptr> spr2;
                bn::optional<bn::sprite_ptr> spr3;
                public:
                    bn::fixed x;
                    bn::fixed y;
                    GameOver(bn::fixed, bn::fixed);
                    ~GameOver();
                    GameOver* setX(bn::fixed);
                    GameOver* setY(bn::fixed);
                    GameOver* show();
                    GameOver* hide();
            };
        }
    }


#endif