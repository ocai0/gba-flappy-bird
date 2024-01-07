#ifndef GAMEPLAY_SCENE_H_
#define GAMEPLAY_SCENE_H_
    
    #include "bn_core.h"
    #include "bn_vector.h"
    #include "bn_random.h"
    #include "bn_keypad.h"

    #include "Base/Scene.hpp"
    #include "Math.hpp"

    #include "Entities/Flappy.hpp"
    #include "Entities/PipeWall.hpp"
    #include "Entities/Score.hpp"
    #include "bn_sprite_items_debug.h"
    
    typedef struct {
        int deltaX;
        int deltaY;
        int gravity;
        int rotationDelta;
        int direction; // 1 means down, -1 means up
        int VERTICAL_JUMP_SPEED;
        int MAX_FALL_SPEED;
    } FlappyData;

    namespace Scenes {

        class Gameplay : public Scene {
            Flappy flappy;
            int pipeSpeed;
            int MAX_PIPE_SPEED;
            Score score;
            FlappyData flappyData;
            int SUB_PIXEL_ZONE;
            bn::vector<bn::optional<PipeWall>, 4> pipes;
            bn::random random;
            void showGameOverScreen();
            void reset();
            public:
                Gameplay();
                bn::optional<SceneType> update();
        };
    }
#endif