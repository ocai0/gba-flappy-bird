#ifndef SCORE_BOARD_H_
#define SCORE_BOARD_H_

    #include "bn_optional.h"
    #include "bn_regular_bg_ptr.h"

    #include "Commons/StateMachine.hpp"
    #include "Score.hpp"
    #include "UI/ScoreBoard/ScoreBoard.State.Appear.hpp"

    #include "bn_regular_bg_items_bg_score_board.h"

    namespace UI {
        class ScoreBoard {
            public:
                bn::optional<bn::regular_bg_ptr> sprite;
                Score* currentScore;
                Score* highScore;
                StateMachine* stateMachine;
                bn::fixed x = 0;
                bn::fixed y = 370;
                bn::fixed deltaX = 0;
                bn::fixed deltaY = 0;
                ScoreBoard();
                ~ScoreBoard();
                void setX(bn::fixed);
                void setY(bn::fixed);
                void load();
                void update();
                void render();
                void showNewHighScoreFlag();
        };
    }
#endif