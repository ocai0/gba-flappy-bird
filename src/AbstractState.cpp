#include "AbstractState.hpp"

void AbstractState::tick() {
    this->update();
    // if(this->machine != nullptr) this->machine->update();

    this->render();
    // if(this->machine != nullptr) this->machine->render();
}