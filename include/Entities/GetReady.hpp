#ifndef GET_READY_H_
#define GET_READY_H_

    #include "bn_core.h"
    #include "bn_regular_bg_ptr.h"
    #include "bn_optional.h"
    #include "bn_blending_actions.h"
    #include "bn_blending_transparency_attributes.h"
    #include "bn_regular_bg_attributes.h"
    #include "bn_regular_bg_items_bg_get_ready.h"

    class GetReady {
        bn::regular_bg_ptr bg;
        bn::fixed value;
        bool done;
        bool fadeInEnabled;
        bool fadeOutEnabled;
        public:
            GetReady();
            bool isDone();
            void fadeIn();
            void fadeOut();
            void update();
    };

#endif