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
    #include "bn_sprite_items_ui_new.h"
    #include "bn_sprite_items_ui_medal.h"

    #include "Entities/Score.hpp"


    struct ScoreData {
        int current;
        int max;
    };
    
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
        class NewFlag {
            int x;
            int y;
            bn::sprite_ptr sprite;
            public:
                NewFlag(int, int);
                int getX();
                void setX(int);
                int getY();
                void setY(int);
                void update();
                void setPriority(int);
        };
        class Medal {
            int x;
            int y;
            bn::sprite_ptr sprite;
            public:
                Medal(int, int);
                void setIndex(int);
        };
        class Board {
            int x;
            int y;
            int endY;
            int maxScoreY;
            int scoreY;
            ScoreData scoreData;
            Score maxScore;
            Score score;
            bn::unique_ptr<Medal> ptrMedal;
            bn::unique_ptr<NewFlag> ptrNewFlag;
            bn::regular_bg_ptr bg;
            bool _scoreAnimationComplete;
            public:
                Board(int, ScoreData);
                void update();
                bool scoreAnimationComplete();
        };
    }

    enum class FLAG_STATUS { UP, DOWN };

    class ScoreBoard {
        int x;
        int y;
        ScoreData score;
        bn::fixed fadeIntensity;
        FLAG_STATUS _gameOverTitle;
        FLAG_STATUS _scoreBoard;
        bn::unique_ptr<ui::Board> ptrBoard;
        bn::unique_ptr<ui::GameOver> ptrGameOver;

        public:
            void resetAllFlags();
            ScoreBoard(int, int);
            // ~ScoreBoard();
            void setX(int);
            void setY(int);
            int getX();
            int getY();
            void showGameOverText(int, int, int, int);
            void showBoard(int, int, int, int);
            bool scoreAnimationComplete();
            // void showButtons();
            void update();
    };

#endif