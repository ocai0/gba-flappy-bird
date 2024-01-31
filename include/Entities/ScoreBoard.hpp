#ifndef SCORE_BOARD_H_
#define SCORE_BOARD_H_

    #include "bn_regular_bg_ptr.h"
    #include "bn_unique_ptr.h"
    #include "bn_sprite_tiles_ptr.h"
    #include "bn_sprite_ptr.h"
    #include "bn_blending_actions.h"
    #include "bn_algorithm.h"
    #include "bn_regular_bg_items_bg_score_board.h"

    #include "bn_sprite_palette_items_palette_ui.h"
    #include "bn_sprite_items_ui_gameover.h"

    
    namespace ui {
        class GameOver {
            int x;
            int y;
            const static int WIDTH = 32;
            const static int HEIGHT = 32;
            const static int WIDTH_HALF = 16;
            const static int HEIGHT_HALF = 16;
            bn::sprite_ptr left;
            bn::sprite_ptr center;
            bn::sprite_ptr right;
            bn::fixed fadeIntensity;
            public:
                GameOver(int, int);
                void setX(int);
                void setY(int);
                int getX();
                int getY();
                void update();       
        };
    }

    class ScoreBoard {
        int x;
        int y;
        bn::regular_bg_ptr bg;
        bn::fixed fadeIntensity;
        bn::unique_ptr<ui::GameOver> ui_gameover;

        public:
            ScoreBoard();
            // ~ScoreBoard();
            void setX(int);
            void setY(int);
            int getX();
            int getY();
            void showGameOver();
            // void showBoard();
            // void showButtons();
            void update();
    };

#endif