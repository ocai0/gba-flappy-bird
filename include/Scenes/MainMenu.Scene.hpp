#ifndef MAIN_MENU_SCENE_H_
#define MAIN_MENU_SCENE_H_
    #include "bn_core.h"
    
    #include "Actors/Floor.hpp"
    #include "UI/GameLogo.Text.hpp"
    #include "Commons/AbstractState.hpp"
    #include "Actors/FlappyBird.hpp"
    #include "Scenes/Gameplay.Scene.hpp"
    #include "Background.hpp"

    #include "bn_regular_bg_items_bg_day.h"
    #include "bn_regular_bg_items_bg_floor.h"

    namespace Scene {
        class MainMenu : public AbstractState {
            public:
                bn::unique_ptr<Floor> floor;
                bn::unique_ptr<FlappyBird> player;
                bn::optional<Background> background;
                bn::optional<UI::Text::GameLogo> gameLogo;
                StateMachine* sceneManager;

                MainMenu(StateMachine*);
                void load();
                void update();
                void render();
                void leave();
        };
    }

#endif