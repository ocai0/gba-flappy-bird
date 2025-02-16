#ifndef GAMEPLAY_GET_READY_H_
#define GAMEPLAY_GET_READY_H_
    #include "Commons/AbstractState.hpp"
    #include "Scenes/Gameplay.Scene.hpp"
    #include "Scenes/Gameplay/Gameplay.Scene.InGame.hpp"

    namespace Scene { class Gameplay; }
    namespace _Gameplay {
        class GetReady: public AbstractState {
            public:
                Scene::Gameplay* parentState;
                GetReady(Scene::Gameplay*);
                void load();
                void update();
                void render();
                void leave();
        };
    }
#endif