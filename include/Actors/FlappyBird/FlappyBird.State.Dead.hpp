#ifndef FLAPPY_BIRD_STATE_DEAD_H_
#define FLAPPY_BIRD_STATE_DEAD_H_
    #include "Commons/AbstractState.hpp"
    #include "Actors/FlappyBird.hpp"
    class FlappyBird;
    namespace _FlappyBird {
        class DeadState: public AbstractState {
            bn::string<32> name = "DeadState";
            public:
                FlappyBird* actor;
                DeadState(FlappyBird* actor);
                void load();
                void update();
                void render();
                void leave();
        };
    }
#endif