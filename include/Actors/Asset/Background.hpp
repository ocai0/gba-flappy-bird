#ifndef BACKGROUND_H_
#define BACKGROUND_H_

    #include "bn_regular_bg_ptr.h"
    #include "bn_bg_palette_item.h"
    #include "bn_bg_palette_ptr.h"
    #include "bn_optional.h"
    #include "bn_bg_palette_items_palette_bg.h"
    #include "bn_regular_bg_items_bg_day.h"
    #include "bn_regular_bg_items_bg_night.h"

    enum BackgroundIndex { DAY = 0, NIGHT = 1 };

    class Background {
        bn::bg_palette_ptr bg_palette = bn::bg_palette_items::palette_bg.create_palette();
        bn::optional<bn::regular_bg_ptr> current;
        bn::fixed x;
        bn::fixed y;
        public:
            Background();
            Background(int, int);
            Background(int, int, BackgroundIndex);
            bn::fixed getX();
            bn::fixed getY();
            void setX(bn::fixed);
            void setY(bn::fixed);
            void update();
            void setBackground(BackgroundIndex);
            void setBlendingEnabled(bool);
    };

#endif