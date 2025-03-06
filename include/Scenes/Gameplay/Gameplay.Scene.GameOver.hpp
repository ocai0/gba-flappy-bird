#ifndef GAMEPLAY_GAME_OVER_H_
#define GAMEPLAY_GAME_OVER_H_
    #include "bn_optional.h"
    #include "SramData.hpp"
    #include "Commons/AbstractState.hpp"
    #include "Scenes/Gameplay.Scene.hpp"
    #include "UI/ScoreBoard.hpp"

    namespace Scene { class Gameplay; }
    namespace _Gameplay {
        class GameOver: public AbstractState {
            bool fadeComplete = false;
            bn::fixed fadeIntensity = .1;
            const bn::fixed step = .08;
            int fadeMultiplierSign = 1;
            SramData* sram;
            bool newHighSocre = false;
            bn::optional<UI::ScoreBoard> scoreboard;
            public:
                Scene::Gameplay* parentState;
                GameOver(Scene::Gameplay*);
                void load();
                void update();
                void render();
                void leave();
                void initializeScoreBoard();
        };
    }
#endif