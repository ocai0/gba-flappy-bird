#include "Scenes/Gameplay/Gameplay.Scene.Paused.hpp"

_Gameplay::Paused::Paused(Scene::Gameplay* _parentState) {
    this->parentState = _parentState;
}

void _Gameplay::Paused::load() {}

void _Gameplay::Paused::update() {
    if(bn::keypad::start_pressed()) {
        this->parentState->stateMachine->set(new _Gameplay::InGame(this->parentState));
    }
}

void _Gameplay::Paused::render() {}

void _Gameplay::Paused::leave() {}

