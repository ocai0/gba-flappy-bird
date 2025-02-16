#include "Actors/FlappyBird/FlappyBird.State.Idle.hpp"
#include "bn_log.h"

_FlappyBird::IdleState::IdleState(FlappyBird* _actor) {
    this->actor = _actor;
}

void _FlappyBird::IdleState::load() {}

void _FlappyBird::IdleState::update() {
    if(this->actor->y < -4) {
        this->actor->deltaYSign = 1;
    }
    if(this->actor->y > 4) {
        this->actor->deltaYSign = -1;
    }
    this->actor->deltaY = .1 * this->actor->deltaYSign;
    this->actor->setY(this->actor->y + this->actor->deltaY);

    if(bn::keypad::a_pressed()) {
        this->actor->stateMachine->set(new _FlappyBird::PlayState(this->actor));
    }

    this->render();
}

void _FlappyBird::IdleState::render() {
    this->actor->setX(this->actor->x + this->actor->deltaX);
    this->actor->setY(this->actor->y + this->actor->deltaY);
    this->actor->animation->update();
    if(this->actor->hitbox.has_value()) this->actor->hitbox->update();
}

void _FlappyBird::IdleState::leave() {
    BN_LOG("LEAVE IDLESTATE");
}