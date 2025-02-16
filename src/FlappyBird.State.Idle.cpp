#include "Actors/FlappyBird/FlappyBird.State.Idle"

_FlappyBird::IdleState::IdleState(FlappyBird* _actor) {
    this->actor = _actor;
}

void _FlappyBird::IdleState::load() {}

void _FlappyBird::IdleState::update() {
    this->animation->update();
    if(this->hitbox.has_value()) this->hitbox->update();

    if(this->y < -4) {
        this->deltaYSign = 1;
    }
    if(this->y > 4) {
        this->deltaYSign = -1;
    }
    this->deltaY = .1 * this->deltaYSign;
    this->setY(this->y + this->deltaY);
}

void _FlappyBird::IdleState::render() {}
