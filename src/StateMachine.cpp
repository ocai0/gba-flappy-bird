#include "StateMachine.hpp"

void StateMachine::set(AbstractState* newState) {
    this->set(newState, false);
}
void StateMachine::set(AbstractState* newState, bool forceReset) {
    this->nextState = newState;
    this->forceStateReset = forceReset;
}
void StateMachine::update() {
    if(this->nextState != nullptr || this->forceStateReset) {
        ((AbstractState*) this->currentState)->leave();
        ((AbstractState*) this->nextState)->load();
        this->currentState = this->nextState;

        this->nextState = nullptr;
        this->forceStateReset = false;
    } else ((AbstractState*) this->currentState)->tick();
}

void StateMachine::render() {
    ((AbstractState*) this->currentState)->render();
}