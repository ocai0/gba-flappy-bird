#ifndef GAMEPLAY_SCENE_H_
#define GAMEPLAY_SCENE_H_
    
    #include "bn_core.h"
    #include "bn_vector.h"
    #include "bn_random.h"
    #include "bn_display.h"
    #include "bn_keypad.h"

    #include "Base/Scene.hpp"
    #include "Math.hpp"

    #include "Entities/Flappy.hpp"
    #include "Entities/PipeWall.hpp"
    #include "Entities/Score.hpp"
    
    typedef struct {
        bn::fixed deltaX;
        bn::fixed deltaY;
        bn::fixed gravity;
        bn::fixed MAX_GRAVITY;
        int rotationDelta;
        int direction; // 1 means down, -1 means up
        bn::fixed VERTICAL_JUMP_SPEED;
    } FlappyData;

    namespace Scenes {

        class Gameplay : public Scene {
            Flappy flappy;
            bn::fixed pipeSpeed;
            bn::fixed MAX_PIPE_SPEED;
            Score score;
            FlappyData flappyData;
            bn::vector<bn::optional<PipeWall>, 5> pipes;
            bn::random random;
            void showGameOverScreen();
            void reset();
            public:
                Gameplay();
                bn::optional<SceneType> update();
        };
    }
#endif