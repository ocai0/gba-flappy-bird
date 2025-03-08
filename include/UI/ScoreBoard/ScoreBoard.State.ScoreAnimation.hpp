#ifndef SCORE_BOARD_STATE_SCORE_ANIMATION_H_
#define SCORE_BOARD_STATE_SCORE_ANIMATION_H_

    #include "bn_optional.h"
    #include "UI/ScoreBoard.hpp"
    #include "Commons/AbstractState.hpp"

    namespace UI {
        class ScoreBoard;
    }

    namespace _ScoreBoard {
        class ScoreAnimation : public AbstractState {
            int tempCurrentScore = 0;
            int tempHighScore = 0;
            public:
                UI::ScoreBoard* scoreboard;
                ScoreAnimation(UI::ScoreBoard*);
                void load();
                void update();
                void render();
                void leave();
                void showNewHighScoreFlag();
        };
    }
#endif