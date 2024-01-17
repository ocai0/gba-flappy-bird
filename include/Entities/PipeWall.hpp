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
        int width;
        int offsetX;
        int gapSize;
        int color;
        bool scored;
        bn::optional<bn::sprite_ptr> top_pipe;
        bn::optional<bn::sprite_ptr> top_pipe_body;
        bn::optional<bn::sprite_ptr> bottom_pipe;
        bn::optional<bn::sprite_ptr> bottom_pipe_body;
        DebugBox debugBox;
        public:
            PipeWall(bn::fixed x, bn::fixed y, int width, int gapSize, int color);
            PipeWall(bn::fixed x, bn::fixed y, int width, int gapSize, int color, int offsetX);
            void createPipes();
            bn::fixed getX();
            void setX(bn::fixed);
            bn::fixed getY();
            void setY(bn::fixed);
            int getWidth();
            int getGapSize();
            void setGapSize(int);
            void setScoredFlag(bool);
            bool getScoredFlag();
            void showSprite(bool);
            void showDebugBox(bool);
    };

#endif