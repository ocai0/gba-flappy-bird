#ifndef GEARS_LOGO_SCENE_H_
#define GEARS_LOGO_SCENE_H_
    #include "bn_core.h"
    #include "bn_bg_palette_ptr.h"

    #include "Commons/AbstractState.hpp"
    #include "Commons/StateMachine.hpp"
    #include "Scenes/Gameplay.Scene.hpp"

    #include "bn_regular_bg_items_bg_gears_logo.h"
    #include "bn_bg_palette_items_bg_gears_logo_alt.h"

    namespace Scene {
        class GearsLogo : public AbstractState {
            bn::optional<bn::regular_bg_ptr> bg;
            bn::optional<bn::bg_palette_ptr> bg_palette;
            StateMachine* sceneManager;
            bn::fixed fadeValue = -4;
            bool fadeOutComplete = false;
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