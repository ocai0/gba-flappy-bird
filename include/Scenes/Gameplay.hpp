#ifndef GAMEPLAY_SCENE_H_
#define GAMEPLAY_SCENE_H_
    #include "bn_core.h"
    #include "bn_optional.h"
    #include "bn_array.h"
    #include "bn_random.h"

    #include "Scene.hpp"
    #include "MainMenuVars.hpp"
    #include "Background.hpp"
    #include "Actors/FlappyBird.hpp"
    #include "Actors/Obstacle.hpp"
    #include "Actors/Pipe.hpp"
    #include "Actors/PunchPipe.hpp"
    #include "Actors/CactusPipe.hpp"
    #include "Actors/AncientPipe.hpp"
    #include "Actors/Floor.hpp"

    #include "bn_regular_bg_items_bg_floor.h"
    #include "bn_regular_bg_items_bg_day.h"
    #include "bn_sprite_palette_items_red_pipe.h"
    #include "bn_sprite_palette_items_blue_pipe.h"

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

    namespace Scenes {
        class Gameplay : public Scene {
            SubState currentState;
            MainMenuVars* mainMenuVars;
            Scene* nextScene;
            FlappyBird* player;
            Floor* floor;
            Background* background;
            bn::array<PipeWall*, 6> pipes;
            bn::array<Obstacle*, 10> obstacles;
            void init(MainMenuVars&);
            public:
                Gameplay();
                Gameplay(MainMenuVars&);
                void load();
                Scene* update();
                void leave();

                void setGetReadyState();
                void setGameState();
                void setBonusState();
                Scene* setPauseState();
                Scene* setGameOverState();
                Scene* setYouWinState();

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