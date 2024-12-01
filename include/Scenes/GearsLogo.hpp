#ifndef GEARS_LOGO_SCENE_H_
#define GEARS_LOGO_SCENE_H_

    #include "bn_core.h"
    #include "bn_optional.h"
    #include "bn_keypad.h"
    #include "bn_regular_bg_ptr.h"
    #include "bn_bg_palette_ptr.h"
    
    #include "bn_regular_bg_items_bg_gears_logo.h"
    #include "bn_bg_palette_items_bg_gears_logo_alt.h"

    #include "Scene.hpp"
    #include "Scenes/MainMenu.hpp"
    #include "Effects/FadeScreenEffect.hpp"
    
    namespace Scenes {

        class GearsLogo : public Scene {
            bn::optional<bn::regular_bg_ptr> bg;
            bool blueBgActive = false;
            public:
                void load();
                Scene* update();
                void leave();
        };

    }

#endif