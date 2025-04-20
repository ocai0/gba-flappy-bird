#ifndef STATE_MACHINE_H_
#define STATE_MACHINE_H_
    #include "bn_optional.h"
    #include "Commons/AbstractState.hpp"
    class AbstractState;
    
    class StateMachine {
        bn::optional<AbstractState> currentState;
        bn::optional<AbstractState> nextState;
        bool forceStateReset = false;
        public:
            unsigned int tick = 0;
            bool log = false;
            ~StateMachine();
            void set(bn::optional<AbstractState> newState);
            void set(bn::optional<AbstractState> newState, bool forceReset);
            void update();
            void render();
            bn::optional<AbstractState> get();
            bn::string<32> getStateName();
    };
#endif