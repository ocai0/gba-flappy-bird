#ifndef MAIN_MENU_SCENE_H
#define MAIN_MENU_SCENE_H

    #include "bn_core.h"
    #include "bn_keypad.h"
    #include "bn_random.h"
    #include "bn_regular_bg_ptr.h"
    #include "bn_regular_bg_attributes.h"
    #include "bn_regular_bg_items_bg_main_menu.h"

    #include "Scene.hpp"
    #include "Effects/FadeScreenEffect.hpp"
    #include "Math.hpp"
    #include "Actors/Player/Flappy.hpp"
    #include "Actors/Asset/Background.hpp"
    #include "Actors/Asset/Floor.hpp"


    namespace Scenes {
        class MainMenu : public Scene {
            Flappy flappy;
            bn::regular_bg_ptr ui;
            Background background;
            Floor floor;
            bn::random random;
            public:
                MainMenu();
                Scene* update();
                void leave();
        };
    }

#endif