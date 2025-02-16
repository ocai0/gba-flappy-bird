#ifndef FLAPPY_BIRD_STATE_FALL_H_
#define FLAPPY_BIRD_STATE_FALL_H_
    #include "Commons/AbstractState.hpp"
    #include "Actors/FlappyBird.hpp"
    class FlappyBird;
    namespace _FlappyBird {
        class FallState: public AbstractState {
            public:
                bool floorNotHit;
                bool dieSoundPlayed = false;
                FlappyBird* actor;
                FallState(FlappyBird* actor);
                void load();
                void update();
                void render();
                void leave();
        };
    }
#endif