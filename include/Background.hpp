#ifndef BACKGORUND_H_
#define BACKGORUND_H_
    #include "bn_optional.h"
    #include "bn_regular_bg_ptr.h"

    class Background {
        bn::fixed xSpeed = .2;
        bn::optional<bn::regular_bg_ptr> sprite;
        public:
            void setImage(bn::regular_bg_ptr);
            void update();
    };
#endif