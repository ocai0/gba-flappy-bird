#ifndef PIPE_WALL_H_
#define PIPE_WALL_H_

    #include "bn_sprite_ptr.h"
    #include "bn_optional.h"
    #include "bn_sprite_items_pipe.h"
    #include "bn_sprite_items_pipe_body.h"
    #include "Entities/DebugBox.hpp"

    class PipeWall {
        volatile int x;
        volatile int y;
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
            PipeWall(int x, int y, int color, int gapSize);
            void setX(int);
            void setY(int);
            void createPipes();
            int getX();
            int getGapSize();
            void setGapSize(int);
            int getY();
            void setScoredFlag(bool);
            bool getScoredFlag();
            void setVisible(bool);
    };

#endif