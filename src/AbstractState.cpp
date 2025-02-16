#include "AbstractState.hpp"

void AbstractState::tick() {
    this->update();
    if(this->machine != nullptr) this->machine->update();

    this->render();
    if(this->machine != nullptr) this->machine->render();
    this->time++;
}

bn::string<32> AbstractState::getName() {
    return this->name;
}