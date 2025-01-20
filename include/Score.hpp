#ifndef SCORE_H_
#define SCORE_H_
    
    #include "bn_sprite_text_generator.h"
    #include "bn_sprite_ptr.h"
    #include "bn_string.h"
    #include "bn_optional.h"

    #include "Fonts/BigScore.hpp"

    class Score {
        int value;
        bn::fixed x;
        bn::fixed y;
        bn::optional<bn::sprite_text_generator> textGenerator;
        bn::vector<bn::sprite_ptr, 32> sprites;
        bn::string<4> text;

        public:
            Score(bn::fixed, bn::fixed);
            int getValue();
            Score* setValue(int);
            Score* setX(bn::fixed);
            Score* setY(bn::fixed);
            Score* useBigFont();
            Score* fadeIn();
            Score* fadeOut();
            void update();
            void setPriority(int);
    };
#endif