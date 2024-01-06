#ifndef GAMEPLAY_SCENE_H_
#define GAMEPLAY_SCENE_H_
    
    #include "bn_core.h"
    #include "bn_vector.h"
    #include "bn_random.h"
    #include "bn_keypad.h"

    #include "Base/Scene.hpp"

    #include "Entities/Flappy.hpp"
    #include "Entities/PipeWall.hpp"
    #include "Entities/Score.hpp"
    #include "bn_sprite_items_debug.h"

    typedef struct {
        bn::optional<bn::sprite_ptr> top_left;
        bn::optional<bn::sprite_ptr> top_right;
        bn::optional<bn::sprite_ptr> bottom_left;
        bn::optional<bn::sprite_ptr> bottom_right;
    } DebugPoint;
    
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
            void load();
            bn::optional<SceneType> update();
            void leave();
            void paused();
            void setup();
            void showGameOverScreen();
            public:
                DebugPoint debugPoint;
                Gameplay();
                void updateDebugPoints(int, int, int, int);
                void manage();
        };
    }
#endif