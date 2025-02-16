#ifndef FLAPPY_BIRD_STATE_IDLE_H_
#define FLAPPY_BIRD_STATE_IDLE_H_
    #include "Commons/AbstractState.hpp"
    #include "Actors/FlappyBird.hpp"
    #include "Actors/FlappyBird/FlappyBird.State.Play.hpp"
    class FlappyBird;
    namespace _FlappyBird {
        class IdleState: public AbstractState {
            public:
                FlappyBird* actor;
                IdleState(FlappyBird* actor);
                void load();
                void update();
                void render();
                void leave();
        };
    }
#endif