#ifndef ANCIENT_PIPE_H_
#define ANCIENT_PIPE_H_
    #include "Actors/Pipe.hpp"
    
    #include "bn_sprite_items_ancient_pipe.h"

    class AncientPipe : public Pipe {
        public:
            AncientPipe(bn::fixed, bn::fixed);
    };
#endif