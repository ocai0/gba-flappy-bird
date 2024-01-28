#ifndef SCORE_BOARD_H_
#define SCORE_BOARD_H_

    #include "bn_regular_bg_ptr.h"
    #include "bn_regular_bg_items_bg_score_board.h"

    class ScoreBoard {
        int x;
        int y;
        bn::regular_bg_ptr bg;
        public:
            ScoreBoard(int, int);
            void setX(int);
            void setY(int);
            int getX();
            int getY();
            void update();
    };

#endif