#ifndef FLOOR_H_
#define FLOOR_H_

    #include "bn_regular_bg_ptr.h"
    #include "bn_regular_bg_attributes.h"
    #include "bn_regular_bg_items_bg_floor.h"

    class Floor {
        bn::fixed x;
        bn::fixed y;
        bn::regular_bg_ptr bg;
        public:
            Floor(bn::fixed, bn::fixed);
            void setX(bn::fixed);
            void setY(bn::fixed);
            bn::fixed getX();
            bn::fixed getY();
            void update();
            void setBlendingEnabled(bool);
    };

#endif