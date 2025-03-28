#ifndef GAMEPLAY_GAME_OVER_H_
#define GAMEPLAY_GAME_OVER_H_
    #include "bn_optional.h"
    #include "bn_keypad.h"
    #include "bn_memory.h"
    #include "Commons/AbstractState.hpp"
    #include "Scenes/Gameplay.Scene.hpp"
    #include "UI/ScoreBoard.hpp"
    #include "UI/GameOver.Text.hpp"
    #include "UI/MainMenu.Button.hpp"
    #include "UI/Restart.Button.hpp"
    #include "Scenes/Gameplay/Gameplay.Scene.GetReady.hpp"

    namespace Scene { class Gameplay; }
    namespace _Gameplay {

        enum UserOptions { RESTART_GAME, MAIN_MENU };
        const bn::string<32> STR_DEAD_STATE("DeadState");
        const bn::string<32> STR_SCORE_ANIMATION_START("ScoreAnimation.Start");
        const bn::string<32> STR_SCORE_ANIMATION_END("ScoreAnimation.End");

        class GameOver: public AbstractState {
            bool fadeComplete = false;
            bn::fixed fadeIntensity = .1;
            const bn::fixed step = .08;
            int fadeMultiplierSign = 1;
            bool newHighSocre = false;
            UI::ScoreBoard* scoreboard;
            UI::Text::GameOver* gameOverText;
            UI::Button::MainMenu* mainMenuBtn;
            UI::Button::Restart* restartBtn;
            UserOptions option;
            public:
                Scene::Gameplay* gameplayScene;
                GameOver(Scene::Gameplay*);
                void load();
                void update();
                void render();
                void leave();
                void initializeScoreBoard();
                void clearResources();
                void clearOutsideResources();
        };
    }
#endif