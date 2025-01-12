#ifndef CACTUS_PIPE_H_
#define CACTUS_PIPE_H_
    #include "Actors/Pipe.hpp"
    
    #include "bn_sprite_items_cactus_pipe.h"

    class CactusPipe : public Pipe {
        public:
            CactusPipe(bn::fixed, bn::fixed);
    };
#endif