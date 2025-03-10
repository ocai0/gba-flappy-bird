#ifndef GAMEPLAY_IN_GAME_H_
#define GAMEPLAY_IN_GAME_H_
    #include "bn_random.h"
    
    #include "Commons/AbstractState.hpp"
    #include "Scenes/Gameplay.Scene.hpp"
    #include "Scenes/Gameplay/Gameplay.Scene.Paused.hpp"
    #include "Scenes/Gameplay/Gameplay.Scene.GameOver.hpp"

    namespace Scene { class Gameplay; }
    namespace _Gameplay {
        class InGame: public AbstractState {
            public:
                Scene::Gameplay* parentState;
                InGame(Scene::Gameplay*);
                void load();
                void update();
                void render();
                void leave();
        };
    }
#endif