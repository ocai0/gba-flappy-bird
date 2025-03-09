#ifndef STRUCT_PIPE_WALL_H_
#define STRUCT_PIPE_WALL_H_

    #include "Actors/Pipe.hpp"

    typedef struct {
        bn::fixed x;
        bn::fixed y;
        Pipe* topPipe;
        Pipe* bottomPipe;
        bool scored = false;
    } PipeWall;

#endif