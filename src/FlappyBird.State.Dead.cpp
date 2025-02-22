#include "Actors/FlappyBird/FlappyBird.State.Dead.hpp"

_FlappyBird::DeadState::DeadState(FlappyBird* _actor) {
    this->actor = _actor;
    this->setName("DeadState");
}

void _FlappyBird::DeadState::load() {}

void _FlappyBird::DeadState::update() {}

void _FlappyBird::DeadState::render() {}

void _FlappyBird::DeadState::leave() {}