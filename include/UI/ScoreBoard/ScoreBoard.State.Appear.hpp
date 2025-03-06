#ifndef SCORE_BOARD_STATE_APPEAR_H_
#define SCORE_BOARD_STATE_APPEAR_H_

    #include "bn_optional.h"
    #include "UI/ScoreBoard.hpp"
    #include "Commons/AbstractState.hpp"

    namespace UI {
        class ScoreBoard;
    }

    namespace _ScoreBoard {
        class Appear : public AbstractState {
            int initalPosY = 370;
            int finalPosY = 256;
            bn::fixed y;
            public:
                UI::ScoreBoard* scoreboard;
                Appear(UI::ScoreBoard*);
                void load();
                void update();
                void render();
                void leave();
        };
    }
#endif