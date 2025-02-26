#ifndef GEARS_LOGO_SCENE_H_
#define GEARS_LOGO_SCENE_H_
    #include "bn_core.h"

    #include "Commons/AbstractState.hpp"
    #include "Commons/StateMachine.hpp"
    #include "Scenes/Gameplay.Scene.hpp"

    #include "bn_regular_bg_items_bg_gears_logo.h"
    #include "bn_bg_palette_items_bg_gears_logo_alt.h"

    namespace Scene {
        class GearsLogo : public AbstractState {
            bn::optional<bn::regular_bg_ptr> bg;
            StateMachine* sceneManager;
            bn::fixed transparencyValue = 10;
            bool goToMainMenu = false;
            public:
                GearsLogo(StateMachine*);
                void load();
                void update();
                void render();
                void leave();
        };
    }
#endif