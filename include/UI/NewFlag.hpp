#ifndef UI_NEW_FLAG
#define UI_NEW_FLAG
    #include "bn_core.h"
    #include "bn_optional.h"
    #include "bn_sprite_ptr.h"
    #include "bn_sprite_items_ui_new_flag.h"

    namespace UI {
        class NewFlag {
            public:
                bn::optional<bn::sprite_ptr> sprite;
                bn::fixed x;
                bn::fixed y;
                NewFlag(bn::fixed, bn::fixed);
                void load();
                ~NewFlag();
                void setX(bn::fixed);
                void setY(bn::fixed);
                void setPriority(int);
        };
    }
#endif