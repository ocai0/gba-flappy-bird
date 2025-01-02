#ifndef GAMEPLAY_SCENE_H_
#define GAMEPLAY_SCENE_H_
    #include "bn_core.h"
    #include "bn_optional.h"
    #include "bn_vector.h"
    #include "bn_random.h"

    #include "Scene.hpp"
    #include "MainMenuVars.hpp"

    enum SubState {
        GET_READY_STATE,
        IN_GAME_STATE,
        PAUSED_STATE,
        BONUS_STATE,
        GAME_OVER_STATE,
        YOU_WIN_STATE
    };

    namespace Scenes {
        class Gameplay : public Scene {
            SubState* currentState;
            MainMenuVars* mainMenuVars;
            Scene* nextScene;
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