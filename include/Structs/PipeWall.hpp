#ifndef STRUCT_PIPE_WALL_H_
#define STRUCT_PIPE_WALL_H_

    #include "bn_unique_ptr.h"
    #include "Actors/Pipe.hpp"

    typedef struct {
        bn::fixed x;
        bn::fixed y;
        bn::unique_ptr<Pipe> topPipe;
        bn::unique_ptr<Pipe> bottomPipe;
        bool scored = false;
    } PipeWall;

#endif