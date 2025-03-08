#ifndef SCORE_BOARD_STATE_SCORE_ANIMATION_H_
#define SCORE_BOARD_STATE_SCORE_ANIMATION_H_

    #include "bn_optional.h"
    #include "UI/ScoreBoard.hpp"
    #include "SramData.hpp"
    #include "UI/NewFlag.hpp"
    #include "UI/Medal.hpp"
    #include "Commons/AbstractState.hpp"

    namespace UI {
        class ScoreBoard;
    }

    namespace _ScoreBoard {
        constexpr int NEW_FLAG_SPRITE_SIZE_HALVED = 8;
        constexpr int PADDING_VALUE = 4;

        class ScoreAnimation : public AbstractState {
            int tempCurrentScore = 0;
            int tempHighScore = 0;
            bool highScoreWasChecked = false;
            SramData* sram;
            public:
                UI::ScoreBoard* scoreboard;
                UI::NewFlag* newFlag;
                UI::Medal* medal;
                ScoreAnimation(UI::ScoreBoard*);
                void load();
                void update();
                void render();
                void leave();
                void verifyAndSaveHighScore();
                void renderMedal();
        };
    }
#endif