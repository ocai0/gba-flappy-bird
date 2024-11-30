#ifndef SCORE_H_
#define SCORE_H_
    
    #include "bn_sprite_text_generator.h"
    #include "bn_sprite_ptr.h"
    #include "bn_string.h"
    #include "bn_unique_ptr.h"

    #include "Fonts/Score.font.hpp"
    #include "Fonts/Small.font.hpp"

    enum class FontType {SMALL, BIG};

    class Score {
        int value = 0;
        int x = 0;
        int y = 0;
        bn::unique_ptr<bn::sprite_text_generator> ptr_text_generator;
        bn::vector<bn::sprite_ptr, 32> text_sprites;
        bn::string<4> text;
        public:
            Score(int, int, FontType);
            Score(int, int, int, FontType);
            void setX(int);
            void setY(int);
            void setPriority(int);
            void setValue(int);
            int getValue();
            int getX();
            int getY();
            void update();
            void setBlendingEnabled(bool _enable);
            void setVisible(bool);
            void setAlignment(bn::sprite_text_generator::alignment_type);

    };

#endif