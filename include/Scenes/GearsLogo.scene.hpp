#ifndef GEARS_LOGO_SCENE_H_
#define GEARS_LOGO_SCENE_H_

    #include "bn_core.h"
    #include "bn_optional.h"
    #include "bn_keypad.h"

    #include "bn_regular_bg_ptr.h"
    #include "bn_regular_bg_items_bg_gears_logo.h"

    #include "Base/Scene.hpp"
    #include "Base/SceneType.enum.hpp"
    #include "Effects/FadeScreenEffect.hpp"
    #include "Entities/Flappy.hpp"
    #include "Entities/PipeWall.hpp"
    
    namespace Scenes {

        class GearsLogo : public Scene {
            bn::regular_bg_ptr bg;
            public:
                GearsLogo();
                bn::optional<SceneType> update();
        };

    }

#endif