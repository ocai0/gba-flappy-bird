#ifndef PIPE_WALL_H_
#define PIPE_WALL_H_

    #include "bn_sprite_ptr.h"
    #include "bn_optional.h"
    #include "bn_sprite_items_pipe.h"
    #include "Entities/DebugBox.hpp"

    class PipeWall {
        volatile int x;
        volatile int y;
        int gapSize;
        int color;
        bool scored;
        bn::optional<bn::sprite_ptr> top_pipe;
        bn::optional<bn::sprite_ptr> bottom_pipe;
        DebugBox debugBox;
        public:
            static const int PIPE_WIDTH = 0;
            static const int PIPE_HEIGHT = 0;
            static const int PIPE_WIDTH_HALF = 0;
            static const int PIPE_HEIGHT_HALF = 0;
            PipeWall(int x, int y, int color, int gapSize);
            void setX(int);
            void setY(int);
            void createPipes();
            int getX();
            int getGapSize();
            int getY();
            void setScoredFlag(bool);
            bool getScoredFlag();
            void setVisible(bool);
    };

#endif