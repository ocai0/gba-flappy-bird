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
        int PIPE_WIDTH;
        int PIPE_HEIGHT;
        int PIPE_WIDTH_HALF;
        int PIPE_HEIGHT_HALF;
        bn::optional<bn::sprite_ptr> top_pipe;
        bn::optional<bn::sprite_ptr> bottom_pipe;
        public:
            PipeWall(int x, int y, int color, int gapSize);
            void setX(int);
            void setY(int);
            void createPipes();
            int getX();
            int getY();
    };

#endif