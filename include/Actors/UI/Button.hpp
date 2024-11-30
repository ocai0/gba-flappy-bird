#ifndef UI_BUTTON_H_
#define UI_BUTTON_H_

    #include "bn_sprite_ptr.h"
    #include "bn_sprite_tiles_ptr.h"
    #include "bn_sprite_items_ui_big_btn.h"

    namespace ui {
        enum class ButtonType { PLAY, SCORE };
        class Button {
            int x;
            int y;
            bn::optional<bn::sprite_ptr> sprite;
            public:
                Button(int, int, ButtonType);
                void setX(int);
                void setY(int);
                void update();
                int getX();
                int getY();
        };
    }

#endif