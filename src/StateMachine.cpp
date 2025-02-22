#include "Commons/StateMachine.hpp"

void StateMachine::set(AbstractState* newState) {
    this->set(newState, false);
}
void StateMachine::set(AbstractState* newState, bool forceReset) {
    this->nextState = newState;
    this->forceStateReset = forceReset;
}
void StateMachine::update() {
    if(this->nextState != nullptr || this->forceStateReset) {
        if(this->currentState) this->currentState->leave();
        (this->nextState)->load();
        this->currentState = this->nextState;

        this->nextState = nullptr;
        this->forceStateReset = false;
    } else {
        if(this->currentState) this->currentState->tick();
    }
}

void StateMachine::render() {
    if(this->currentState) this->currentState->render();
}

bn::string<32> StateMachine::getStateName() {
    return this->currentState->getName();
}

AbstractState* StateMachine::get() {
    return this->currentState;
}