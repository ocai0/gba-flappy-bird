#ifndef GAMEPLAY_SCENE_H_
#define GAMEPLAY_SCENE_H_
    #include "bn_core.h"
    #include "bn_optional.h"
    #include "bn_array.h"
    #include "bn_random.h"

    #include "Commons/AbstractState.hpp"
    #include "Commons/StateMachine.hpp"
    #include "MainMenuVars.hpp"
    #include "Background.hpp"
    #include "bn_display.h"
    #include "bn_window.h"
    #include "bn_camera_ptr.h"
    #include "bn_blending.h"
    #include "Actors/FlappyBird.hpp"
    #include "Actors/Obstacle.hpp"
    #include "Actors/Pipe.hpp"
    #include "Actors/PunchPipe.hpp"
    #include "Actors/CactusPipe.hpp"
    #include "Actors/AncientPipe.hpp"
    #include "Actors/Floor.hpp"
    #include "Score.hpp"

    #include "bn_regular_bg_items_bg_get_ready.h"
    #include "bn_regular_bg_items_bg_floor.h"
    #include "bn_regular_bg_items_bg_day.h"
    #include "bn_sprite_palette_items_red_pipe.h"
    #include "bn_sprite_palette_items_blue_pipe.h"

    namespace GameplayScene {
        enum SubState {
            GET_READY_STATE,
            IN_GAME_STATE,
            PAUSED_STATE,
            BONUS_STATE,
            GAME_OVER_STATE,
            YOU_WIN_STATE
        };

        typedef struct {
            bn::fixed x;
            bn::fixed y;
            Pipe* topPipe;
            Pipe* bottomPipe;
        } PipeWall;
    }

    namespace Scene {
        class Gameplay : public AbstractState {
            public:
                GameplayScene::SubState currentState;
                MainMenuVars* mainMenuVars;
                AbstractState* nextScene;
                FlappyBird* player;
                Floor* floor;
                Background* background;
                bn::array<GameplayScene::PipeWall*, 6> pipes;
                bn::array<Obstacle*, 10> obstacles;
                bn::optional<bn::regular_bg_ptr> getReadyBg;
                bn::optional<bn::camera_ptr> camera;
                bn::optional<bn::window> window;
                Score* score;
                StateMachine* stateMachine;
                void init(MainMenuVars&);
                Gameplay();
                Gameplay(MainMenuVars&);
                void load();
                void update();
                void render();
                void leave();

                void setGetReadyState();
                void setGameState();
                void setBonusState();
                AbstractState* setPauseState();
                AbstractState* setGameOverState();
                AbstractState* setYouWinState();

                int selectFlappyBird();
                int selectFlappyBird(int);
                int pickAPaletteForFlappy();
                int pickAPaletteForFlappy(int);
                int selectBackground();
                int selectBackground(int);
                int selectPipes();
                int selectPipes(int);
        };
    }
#endif