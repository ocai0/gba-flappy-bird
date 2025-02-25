#ifndef GAMEPLAY_SCENE_H_
#define GAMEPLAY_SCENE_H_
    #include "bn_core.h"
    #include "bn_optional.h"
    #include "bn_array.h"
    #include "bn_random.h"

    #include "Commons/AbstractState.hpp"
    #include "Commons/StateMachine.hpp"
    #include "Scenes/Gameplay/Gameplay.Scene.GetReady.hpp"
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

    typedef struct {
        bn::fixed x;
        bn::fixed y;
        Pipe* topPipe;
        Pipe* bottomPipe;
        bool scored = false;
    } PipeWall;

    namespace Scene {
        class Gameplay : public AbstractState {
            public:
                MainMenuVars* mainMenuVars;
                FlappyBird* player;
                Floor* floor;
                const int GAP_SIZE_BTW_PIPES = 80;
                const int GAP_SIZE = 40;
                Background* background;
                bn::array<PipeWall*, 6> pipes;
                int pipeLastItemIndex = -1;
                bn::array<Obstacle*, 15> obstacles;
                int obstacleLastItemIndex = -1;
                bn::optional<bn::regular_bg_ptr> getReadyBg;
                bn::optional<bn::camera_ptr> camera;
                bn::optional<bn::window> window;
                Score* score;
                StateMachine* stateMachine;
                bn::random* randomGenerator;
                void init(MainMenuVars&);
                Gameplay();
                Gameplay(MainMenuVars&);
                void load();
                void update();
                void render();
                void leave();

                void initializePlayer();
                void initializePlayer(Enum::BirdType);
                void initializeBackground();
                void initializeBackground(Enum::BackgroundType);
                void initializePipes();
                void initializePipes(Enum::PipeType);
                void initializeFloor();
                void initializeFloor(Enum::FloorType);
                int pickAPaletteForFlappy();
                int pickAPaletteForFlappy(int);
                int addToObstacleList(Obstacle*);
                int addToPipeList(PipeWall*);
                void enableBlendingOnAllActors();
                void disableBlendingOnAllActors();
        };
    }
#endif