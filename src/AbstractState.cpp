#include "Commons/AbstractState.hpp"

void AbstractState::tick() {
    this->update();
    this->time++;
}

bn::string<32> AbstractState::getName() {
    return this->name;
}

void AbstractState::setName(bn::string<32> _name) {
    this->name = _name;
}