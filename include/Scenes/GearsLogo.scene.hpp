#ifndef GEARS_LOGO_SCENE_H_
#define GEARS_LOGO_SCENE_H_

    #include "bn_core.h"
    #include "bn_optional.h"
    #include "bn_keypad.h"
    
    #include "Base/Scene.hpp"
    #include "Base/SceneType.enum.hpp"
    #include "Entities/Flappy.hpp"
    #include "Entities/PipeWall.hpp"

    #include "bn_sprite_items_box.h"

    
    namespace Scenes {

        class GearsLogo : public Scene {
            bn::sprite_ptr box_spr = bn::sprite_items::box.create_sprite(8, 8);

            DebugBox _box;
            Flappy flappy;
            PipeWall pipe;
            public:
                GearsLogo();
                bn::optional<SceneType> update();
        };

    }

#endif