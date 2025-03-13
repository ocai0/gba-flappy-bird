#ifndef GAMEPLAY_SCENE_H_
#define GAMEPLAY_SCENE_H_

    #include "bn_core.h"
    #include "bn_optional.h"
    #include "bn_array.h"
    #include "bn_random.h"
    #include "bn_display.h"
    #include "bn_window.h"
    #include "bn_camera_ptr.h"
    #include "bn_blending.h"

    #include "Background.hpp"
    #include "Score.hpp"
    #include "Commons/AbstractState.hpp"
    #include "Commons/StateMachine.hpp"
    #include "Structs/PipeWall.hpp"
    #include "Actors/FlappyBird.hpp"
    #include "Actors/Obstacle.hpp"
    #include "Actors/Pipe.hpp"
    #include "Actors/PunchPipe.hpp"
    #include "Actors/CactusPipe.hpp"
    #include "Actors/AncientPipe.hpp"
    #include "Actors/Floor.hpp"
    #include "Scenes/Gameplay/Gameplay.Scene.GetReady.hpp"

    namespace Scene {
        class Gameplay : public AbstractState {
            public:
                const int GAP_SIZE_BTW_PIPES = 80;
                const int GAP_SIZE = 80;
                int obstacleLastItemIndex = -1;
                int pipeLastItemIndex = -1;
                
                Floor* floor = nullptr;
                Score* score = nullptr;
                FlappyBird* player = nullptr;
                Background* background = nullptr;
                MainMenuVars* mainMenuVars = nullptr;
                StateMachine* stateMachine = nullptr;
                StateMachine* sceneManager = nullptr;

                bn::random* randomGenerator = nullptr;
                bn::array<PipeWall*, 6> pipes;
                bn::array<Obstacle*, 15> obstacles;
                bn::optional<bn::regular_bg_ptr> getReadyBg;
                bn::camera_ptr camera;
                Gameplay(StateMachine*);
                void load();
                void update();
                void render();
                void leave();

                void enableBlendingOnAllActors();
                void disableBlendingOnAllActors();
        };
    }
#endif