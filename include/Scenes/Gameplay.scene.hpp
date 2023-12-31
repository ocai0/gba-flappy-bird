#ifndef GAMEPLAY_SCENE_H_
#define GAMEPLAY_SCENE_H_
    
    #include "bn_core.h"
    #include "bn_vector.h"
    #include "bn_random.h"
    #include "bn_keypad.h"

    #include "SceneEnum.hpp"
    #include "SceneStatus.hpp"
    #include "Flappy.hpp"
    #include "PipeWall.hpp"
    
    typedef struct {
        int deltaX;
        int deltaY;
        int gravity;
        int rotationDelta;
        int direction; // 1 means down, -1 means up
        int VERTICAL_JUMP_SPEED;
        int MAX_FALL_SPEED;
    } FlappyData;

    class Gameplay {
        SceneEnum* _currentScene;
        Flappy flappy;
        int pipeSpeed;
        int MAX_PIPE_SPEED;
        FlappyData flappyData;
        int SUB_PIXEL_ZONE;
        bn::vector<bn::optional<PipeWall>, 4> pipes;
        bn::random random;
        void load();
        void update();
        void leave();
        void paused();
        public:
            SceneStatus status;
            Gameplay(SceneEnum*);
            void manage();
    };

#endif