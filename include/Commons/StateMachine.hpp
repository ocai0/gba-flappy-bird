#ifndef STATE_MACHINE_H_
#define STATE_MACHINE_H_
    #include "bn_optional.h"
    #include "bn_unique_ptr.h"
    #include "Commons/AbstractState.hpp"
    class AbstractState;
    
    class StateMachine {
        bn::unique_ptr<AbstractState> currentState = nullptr;
        AbstractState* nextState;
        bool forceStateReset = false;
        public:
            unsigned int tick = 0;
            bool log = false;
            ~StateMachine();
            void set(AbstractState* newState);
            void set(AbstractState* newState, bool forceReset);
            void update();
            void render();
            AbstractState* get();
            bn::string<32> getStateName();
    };
#endif