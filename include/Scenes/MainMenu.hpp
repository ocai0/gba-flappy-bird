#ifndef MAIN_MENU_SCENE_H
#define MAIN_MENU_SCENE_H

    #include "bn_core.h"
    #include "bn_keypad.h"
    #include "bn_random.h"
    #include "bn_optional.h"
    #include "bn_regular_bg_ptr.h"
    #include "bn_regular_bg_attributes.h"
    #include "bn_regular_bg_items_bg_main_menu.h"

    #include "Math.hpp"
    #include "Scene.hpp"
    #include "Effects/FadeScreenEffect.hpp"
    #include "Actors/Player/Flappy.hpp"
    #include "Actors/Asset/Background.hpp"
    #include "Actors/Asset/Floor.hpp"


    namespace Scenes {
        class MainMenu : public Scene {
            bn::optional<Flappy> flappy;
            bn::optional<bn::regular_bg_ptr> ui;
            bn::optional<Background> background;
            bn::optional<Floor> floor;
            bn::optional<bn::random> random;
            public:
                void load();
                Scene* update();
                void leave();
        };
    }

#endif