#ifndef FLAPPY_BIRD_STATE_PLAY_H_
#define FLAPPY_BIRD_STATE_PLAY_H_
    #include "Commons/AbstractState.hpp"
    #include "Actors/FlappyBird.hpp"
    #include "Actors/FlappyBird/FlappyBird.State.Fall.hpp"

    class FlappyBird;
    namespace _FlappyBird {
        class PlayState: public AbstractState {
            int deltaTime = 0;
            public:
                FlappyBird* actor;
                PlayState(FlappyBird* actor);
                void load();
                void update();
                void render();
                void leave();
        };
    }
#endif