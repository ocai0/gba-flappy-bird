#ifndef GAMEPLAY_SCENE_H_
#define GAMEPLAY_SCENE_H_
    
    #include "bn_core.h"
    #include "bn_keypad.h"

    #include "SceneEnum.hpp"
    #include "SceneStatus.hpp"
    #include "Flappy.hpp"
    
    typedef struct {
        int deltaX;
        int deltaY;
        int gravity;
        int direction; // 1 means down, -1 means up
        int VERTICAL_JUMP_SPEED;
        int SUB_PIXEL_ZONE;
        int MAX_FALL_SPEED;
    } FlappyData;

    class Gameplay {
        SceneEnum* _currentScene;
        Flappy flappy;
        FlappyData flappyData;
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