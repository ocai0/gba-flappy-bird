#ifndef STATE_MACHINE_H_
#define STATE_MACHINE_H_
    #include "AbstractState.hpp"
    
    class StateMachine {
        volatile AbstractState* currentState = nullptr;
        volatile AbstractState* nextState = nullptr;
        bool forceStateReset = false;
        public:
            void set(AbstractState* newState);
            void set(AbstractState* newState, bool forceReset);
            void update();
            void render();
    };
#endif