#ifndef GAMEPLAY_PAUSED_H_
#define GAMEPLAY_PAUSED_H_
    #include "Commons/AbstractState.hpp"
    #include "Scenes/Gameplay.Scene.hpp"
    #include "Scenes/Gameplay/Gameplay.Scene.InGame.hpp"

    namespace Scene { class Gameplay; }
    namespace _Gameplay {
        class Paused: public AbstractState {
            public:
                Scene::Gameplay* parentState;
                Paused(Scene::Gameplay*);
                void load();
                void update();
                void render();
                void leave();
        };
    }
#endif