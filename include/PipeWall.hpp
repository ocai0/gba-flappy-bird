#ifndef PIPE_WALL_H_
#define PIPE_WALL_H_

    #include "bn_sprite_ptr.h"
    #include "bn_optional.h"
    #include "bn_sprite_items_pipe.h"

    class PipeWall {
        volatile int x;
        volatile int y;
        int gapSize;
        int color;
        bn::optional<bn::sprite_ptr> top_pipe;
        bn::optional<bn::sprite_ptr> bottom_pipe;
        public:
            static const int PIPE_WIDTH = 32;
            static const int PIPE_HEIGHT = 32;
            static const int PIPE_WIDTH_HALF = 16;
            static const int PIPE_HEIGHT_HALF = 16;
            PipeWall(int x, int y, int color, int gapSize);
            void setX(int);
            void setY(int);
            void createPipes();
            int getX();
            int getGapSize();
            int getY();
    };

#endif