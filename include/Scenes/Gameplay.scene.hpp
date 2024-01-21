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
    
    constexpr int COLOR_WHITE = 1;
    constexpr int SCREEN_WIDTH = bn::display::width();
    constexpr int SCREEN_WIDTH_HALF = SCREEN_WIDTH >> 1;
    constexpr int SCREEN_HEIGHT = bn::display::height();
    constexpr int SCREEN_HEIGHT_HALF = SCREEN_HEIGHT >> 1;
    constexpr int GAP_BTW_PIPES = 40;
    constexpr bn::fixed PIPE_INITIAL_POSITION(SCREEN_WIDTH_HALF + GAP_BTW_PIPES);
    constexpr int PIPE_WALL_WIDTH = 26;
    constexpr int PIPE_WALL_WIDTH_HALF = PIPE_WALL_WIDTH >> 1;



    typedef struct {
        bn::fixed deltaX;
        bn::fixed deltaY;
        bn::fixed gravity;
        bn::fixed MAX_GRAVITY;
        int rotationDelta;
        int direction; // 1 means down, -1 means up
        bn::fixed VERTICAL_JUMP_SPEED;
    } FlappyData;

    enum SUB_SCENE { GET_READY, GAME, PAUSED, GAME_OVER };

    namespace Scenes {

        class Gameplay : public Scene {
            Flappy flappy;
            int currentSubScene;
            bn::fixed pipeSpeed;
            bn::fixed MAX_PIPE_SPEED;
            Score score;
            FlappyData flappyData;
            bn::vector<bn::optional<PipeWall>, 5> pipes;
            bn::random random;
            void getReadyScene();
            void gameScene();
            void pausedScene();
            void gameOverScene();
            void reset();
            public:
                Gameplay();
                bn::optional<SceneType> update();
        };
    }
#endif