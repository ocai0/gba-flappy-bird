#ifndef BACKGORUND_H_
#define BACKGORUND_H_
    #include "bn_optional.h"
    #include "bn_camera_ptr.h"
    #include "bn_regular_bg_ptr.h"

    class Background {
        bn::fixed xSpeed = .2;
        bn::optional<bn::regular_bg_ptr> sprite;
        bn::optional<bn::camera_ptr> camera;
        public:
            ~Background();
            Background* setImage(bn::regular_bg_ptr);
            void update();
            Background* setCamera(bn::optional<bn::camera_ptr>);
            Background* enableBlending();
            Background* disableBlending();
            Background* setRenderPriority(int);
    };
#endif