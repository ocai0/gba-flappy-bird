#include "Commons/StateMachine.hpp"
#include "bn_log.h"


void StateMachine::set(AbstractState* newState) {
    this->set(newState, false);
}

void StateMachine::set(AbstractState* newState, bool forceReset) {
    if(this->log) BN_LOG("StateMachine::Set start");
    this->nextState = newState;
    this->forceStateReset = forceReset;
    if(this->log) BN_LOG("StateMachine::Set end");
}

void StateMachine::update() {
    if(this->nextState != nullptr || this->forceStateReset) {
        if(this->currentState != nullptr) {
            this->currentState->leave();
            delete this->currentState;
        }
        this->nextState->load();
        this->currentState = this->nextState;

        this->nextState = nullptr;
        this->forceStateReset = false;
    } else {
        if(this->currentState) this->currentState->tick();
    }
}

void StateMachine::render() {
    if(this->currentState != nullptr) this->currentState->render();
}

bn::string<32> StateMachine::getStateName() {
    return this->currentState->getName();
}

AbstractState* StateMachine::get() {
    return this->currentState;
}

StateMachine::~StateMachine() {
    delete this->currentState;
    this->currentState = nullptr;
    
    delete this->nextState;
    this->nextState = nullptr;
}