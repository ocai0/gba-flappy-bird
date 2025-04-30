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
    #include "Scenes/Gameplay/GameOver/GameOver.Scene.WaitForPlayerDeath.hpp"

    namespace Scene { class Gameplay; }
    namespace _Gameplay {
        
        class GameOver: public AbstractState {
            public:
                bool newHighSocre = false;
                UI::ScoreBoard* scoreboard;
                StateMachine* stateMachine;
                UI::Text::GameOver* gameOverText;
                UI::Button::MainMenu* mainMenuBtn;
                UI::Button::Restart* restartBtn;
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