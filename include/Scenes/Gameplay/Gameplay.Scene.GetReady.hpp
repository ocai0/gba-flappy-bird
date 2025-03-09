#ifndef GAMEPLAY_GET_READY_H_
#define GAMEPLAY_GET_READY_H_
    
    #include "MainMenuVars.hpp"
    #include "Structs/PipeWall.hpp"
    #include "Commons/AbstractState.hpp"
    #include "Scenes/Gameplay.Scene.hpp"
    #include "Scenes/Gameplay/Gameplay.Scene.InGame.hpp"

    #include "bn_regular_bg_items_bg_get_ready.h"
    #include "bn_regular_bg_items_bg_floor.h"
    #include "bn_regular_bg_items_bg_day.h"
    #include "bn_sprite_palette_items_red_pipe.h"
    #include "bn_sprite_palette_items_blue_pipe.h"

    namespace Scene { class Gameplay; }
    namespace _Gameplay {
        class GetReady: public AbstractState {
            public:
                Scene::Gameplay* gameplayScene;
                GetReady(Scene::Gameplay*);
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

        };
    }
#endif