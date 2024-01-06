#ifndef GEARS_LOGO_SCENE_H_
#define GEARS_LOGO_SCENE_H_

    #include "bn_optional.h"
    
    #include "Base/Scene.hpp"
    #include "Base/SceneType.enum.hpp"
    
    namespace Scenes {

        class GearsLogo : public Scene {
            public:
                GearsLogo();
                void load();
                bn::optional<SceneType> update();
                void leave();
        };

    }

#endif