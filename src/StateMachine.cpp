#include "Commons/StateMachine.hpp"
#include "bn_log.h"


void StateMachine::set(bn::optional<AbstractState> newState) {
    this->set(newState, false);
}

void StateMachine::set(bn::optional<AbstractState> newState, bool forceReset) {
    if(this->log) BN_LOG("StateMachine::Set start");
    this->nextState = newState;
    this->forceStateReset = forceReset;
    if(this->log) BN_LOG("StateMachine::Set end");
}

void StateMachine::update() {
    if(this->nextState.has_value() || this->forceStateReset) {
        if(this->currentState.has_value()) {
            this->currentState->leave();
            this->currentState.reset();
        }
        this->nextState->load();
        this->currentState = this->nextState;

        this->forceStateReset = false;
    } else {
        if(this->currentState) this->currentState->tick();
    }
}

void StateMachine::render() {
    if(this->currentState.has_value()) this->currentState->render();
}

bn::string<32> StateMachine::getStateName() {
    return this->currentState->getName();
}

bn::optional<AbstractState> StateMachine::get() {
    return this->currentState;
}

StateMachine::~StateMachine() {
    delete this->currentState;
    this->currentState = nullptr;
    
    delete this->nextState;
    this->nextState = nullptr;
}