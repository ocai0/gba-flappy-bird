#ifndef SCORE_H_
#define SCORE_H_
    
    #include "bn_sprite_text_generator.h"
    #include "bn_sprite_ptr.h"
    #include "bn_string.h"

    #include "Fonts/Score.font.hpp"

    class Score {
        int value = 0;
        int x = 0;
        int y = 0;
        bn::sprite_text_generator text_generator;
        bn::vector<bn::sprite_ptr, 32> text_sprites;
        bn::string<4> text;
        public:
            Score(int, int);
            Score(int, int, int);
            void setX(int);
            void setY(int);
            void setValue(int);
            int getValue();
            int getX();
            int getY();
            void update();
            void setBlendingEnabled(bool _enable);
            void setVisible(bool);

    };

#endif