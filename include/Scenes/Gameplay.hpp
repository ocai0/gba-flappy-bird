#ifndef GAMEPLAY_SCENE_H_
#define GAMEPLAY_SCENE_H_
    
    #include "bn_core.h"
    #include "bn_vector.h"
    #include "bn_random.h"
    #include "bn_display.h"
    #include "bn_keypad.h"
    #include "bn_unique_ptr.h"
    #include "bn_sound_items.h"
    #include "bn_sound_handle.h"


    #include "Scene.hpp"
    #include "Effects/FadeScreenEffect.hpp"
    #include "Math.hpp"
    #include "bn_sprite_tiles_ptr.h"
    #include "bn_sprite_items_ui_small_btn.h"
    

    #include "Actors/Player/Flappy.hpp"
    #include "Actors/Obstacle/PipeWall.hpp"
    #include "Actors/UI/Score.hpp"
    #include "Actors/Asset/Background.hpp"
    #include "Actors/Asset/Floor.hpp"
    #include "Actors/UI/GetReady.hpp"
    #include "Actors/UI/Button.hpp"
    #include "Actors/UI/ScoreBoard.hpp"
    
    constexpr int COLOR_WHITE = 1;
    constexpr int SCREEN_WIDTH = bn::display::width();
    constexpr int SCREEN_WIDTH_HALF = SCREEN_WIDTH >> 1;
    constexpr int SCREEN_HEIGHT = bn::display::height();
    constexpr int SCREEN_HEIGHT_HALF = SCREEN_HEIGHT >> 1;
    constexpr int GAP_BTW_PIPES = 40;
    constexpr bn::fixed PIPE_INITIAL_POSITION(SCREEN_WIDTH_HALF + GAP_BTW_PIPES);
    constexpr int PIPE_WALL_WIDTH = 26;
    constexpr int PIPE_WALL_WIDTH_HALF = PIPE_WALL_WIDTH >> 1;
    constexpr int FLOOR_Y = 48;

    enum DeathCause { PIPE, FLOOR };

    typedef struct {
        bn::fixed deltaX;
        bn::fixed deltaY;
        bn::fixed gravity;
        bn::fixed MAX_GRAVITY;
        int rotationDelta;
        DeathCause deathCause;
        int direction; // 1 means down, -1 means up
        bn::fixed VERTICAL_JUMP_SPEED;
    } FlappyData;

    enum SUB_SCENE { GET_READY, GAME, PAUSED, GAME_OVER };

    namespace Scenes {

        class Gameplay : public Scene {
            int currentSubScene;
            bn::fixed backgroundSpeed;
            bn::fixed pipeSpeed;
            bn::fixed MAX_PIPE_SPEED;
            bn::vector<bn::optional<PipeWall>, 5> pipes;

            bn::optional<bn::random> random;
            bn::optional<FlappyData> flappyData;
            bn::optional<Flappy> flappy;
            bn::optional<Background> background;
            bn::optional<Score> score;
            bn::optional<Floor> floor;
            bn::optional<bn::sprite_ptr> pauseButton;
            bn::unique_ptr<GetReady> getReady;
            bn::unique_ptr<ScoreBoard> scoreBoard;
            bn::unique_ptr<ui::Button> ptrPlayButton;

            void getReadyScene();
            void gameScene();
            void pausedScene();
            void gameOverScene();
            void reset();
            public:
                void load();
                Scene* update();
                void leave();
        };
    }
#endif