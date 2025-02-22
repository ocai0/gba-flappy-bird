#ifndef GAMEPLAY_GAME_OVER_H_
#define GAMEPLAY_GAME_OVER_H_
    #include "Commons/AbstractState.hpp"
    #include "Scenes/Gameplay.Scene.hpp"

    namespace Scene { class Gameplay; }
    namespace _Gameplay {
        class GameOver: public AbstractState {
            bool fadeComplete = false;
            bn::fixed fadeIntensity = .1;
            const bn::fixed step = .08;
            int fadeMultiplierSign = 1;
            public:
                Scene::Gameplay* parentState;
                GameOver(Scene::Gameplay*);
                void load();
                void update();
                void render();
                void leave();
        };
    }
#endif