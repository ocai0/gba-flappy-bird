#ifndef ACTOR_H_
#define ACTOR_H_
    #include "bn_string.h"
    class Actor {
        protected:
            bn::string<32> instanceName;
        public:
            Actor();
            bn::string<32> getInstanceName();
    };
#endif