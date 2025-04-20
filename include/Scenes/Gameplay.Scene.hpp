#ifndef GAMEPLAY_SCENE_H_
#define GAMEPLAY_SCENE_H_

    #include "bn_core.h"
    #include "bn_optional.h"
    #include "bn_vector.h"
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
                bool log = false;
                const int GAP_SIZE_BTW_PIPES = 80;
                const int GAP_SIZE = 80;
                
                Floor* floor = nullptr;
                Score* score = nullptr;
                FlappyBird* player = nullptr;
                bn::optional<Background> background;
                MainMenuVars* mainMenuVars = nullptr;
                bn::optional<StateMachine> stateMachine;
                bn::optional<StateMachine> sceneManager;

                bn::random* randomGenerator = nullptr;
                bn::vector<PipeWall*, 6> pipes;
                bn::vector<Obstacle*, 15> obstacles;
                bn::optional<bn::regular_bg_ptr> getReadyBg;
                bn::optional<bn::camera_ptr> camera;
                Gameplay(bn::optional<StateMachine>);
                void load();
                void update();
                void render();
                void leave();

                void enableBlendingOnAllActors();
                void disableBlendingOnAllActors();
        };
    }
#endif