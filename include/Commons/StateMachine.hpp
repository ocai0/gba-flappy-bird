#ifndef STATE_MACHINE_H_
#define STATE_MACHINE_H_
    #include "Commons/AbstractState.hpp"
    class AbstractState;
    
    class StateMachine {
        AbstractState* currentState = nullptr;
        AbstractState* nextState = nullptr;
        bool forceStateReset = false;
        public:
            void set(AbstractState* newState);
            void set(AbstractState* newState, bool forceReset);
            void update();
            void render();
            AbstractState* get();
            bn::string<32> getStateName();
    };
#endif