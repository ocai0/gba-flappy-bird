#ifndef PUNCH_PIPE_H_
#define PUNCH_PIPE_H_
    #include "Actors/Pipe.hpp"
    
    #include "bn_sprite_items_punch_pipe.h"

    class PunchPipe : public Pipe {
        public:
            PunchPipe(bn::fixed, bn::fixed);
    };
#endif