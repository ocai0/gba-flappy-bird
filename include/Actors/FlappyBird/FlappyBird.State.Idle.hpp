#ifndef FLAPPY_BIRD_STATE_IDLE_H_
#define FLAPPY_BIRD_STATE_IDLE_H_
    #include "AbstractState.hpp"
    namespace _FlappyBird {
        class IdleState {
            IdleState(FlappyBird* actor);
            void load();
            void update();
            void render();
        };
    }
#endif