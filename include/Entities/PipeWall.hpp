#ifndef PIPE_WALL_H_
#define PIPE_WALL_H_

    #include "bn_sprite_ptr.h"
    #include "bn_optional.h"
    #include "bn_sprite_items_pipe.h"
    #include "bn_sprite_items_pipe_body.h"
    #include "Entities/DebugBox.hpp"

    class PipeWall {
        bn::fixed x;
        bn::fixed y;
        int gapSize;
        int color;
        bool scored;
        bn::optional<bn::sprite_ptr> top_pipe;
        bn::optional<bn::sprite_ptr> top_pipe_body;
        bn::optional<bn::sprite_ptr> bottom_pipe;
        bn::optional<bn::sprite_ptr> bottom_pipe_body;
        DebugBox debugBox;
        public:
            static const int PIPE_WIDTH = 32;
            static const int PIPE_HEIGHT = 64;
            static const int PIPE_WIDTH_HALF = 16;
            static const int PIPE_HEIGHT_HALF = 32;
            PipeWall(bn::fixed x, bn::fixed y, int color, int gapSize);
            void createPipes();
            bn::fixed getX();
            void setX(bn::fixed);
            bn::fixed getY();
            void setY(bn::fixed);
            int getGapSize();
            void setGapSize(int);
            void setScoredFlag(bool);
            bool getScoredFlag();
            void setVisible(bool);
    };

#endif