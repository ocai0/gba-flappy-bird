#ifndef SCORE_BOARD_H_
#define SCORE_BOARD_H_

    #include "bn_regular_bg_ptr.h"
    #include "bn_unique_ptr.h"
    #include "bn_sprite_tiles_ptr.h"
    #include "bn_sprite_ptr.h"
    #include "bn_blending_actions.h"
    #include "bn_algorithm.h"
    #include "Math.hpp"
    #include "bn_regular_bg_items_bg_score_board.h"

    #include "bn_sprite_palette_items_palette_ui.h"
    #include "bn_sprite_items_ui_gameover.h"

    
    namespace ui {
        class GameOver {
            int startX;
            int startY;
            int x;
            int y;
            int endX;
            int endY;
            const static int WIDTH = 32;
            const static int HEIGHT = 32;
            const static int WIDTH_HALF = 16;
            const static int HEIGHT_HALF = 16;
            bn::sprite_ptr left;
            bn::sprite_ptr center;
            bn::sprite_ptr right;
            bn::fixed fadeIntensity;
            public:
                GameOver(int, int, int, int);
                void setX(int);
                void setY(int);
                int getX();
                int getY();
                void update();       
        };
    }

    // FLAG_STATUS::CREATED means the effect was not started yet
    // FLAG_STATUS::UP means the effect was already created/started and it will now update
    enum class FLAG_STATUS { CREATED, UP, DOWN };

    class ScoreBoard {
        int x;
        int y;
        bn::fixed fadeIntensity;
        FLAG_STATUS _gameOverTitle;
        bn::unique_ptr<bn::regular_bg_ptr> ptrBoardBg;
        bn::unique_ptr<ui::GameOver> ptrGameOver;

        public:
            void resetAllFlags();
            ScoreBoard();
            // ~ScoreBoard();
            void setX(int);
            void setY(int);
            int getX();
            int getY();
            void showGameOverText(int, int, int, int);
            // void showBoard();
            // void showButtons();
            void update();
    };

#endif