#include "Actors/FlappyBird/FlappyBird.State.Play.hpp"

constexpr int FRAME_COUNT_PER_SECOND = 60;

_FlappyBird::PlayState::PlayState(FlappyBird* _actor) {
    this->actor = _actor;
}

void _FlappyBird::PlayState::load() {}

void _FlappyBird::PlayState::update() {
    if(bn::keypad::a_pressed()) {
        bn::sound_items::sfx_wing.play();
        this->actor->deltaY = -10;
    }
    if(this->actor->deltaY < 0 && bn::keypad::a_released()) {
        this->actor->deltaY = 0;
    }

    if(bn::keypad::left_held()) this->actor->setX(this->actor->x - 1);
    if(bn::keypad::right_held()) this->actor->setX(this->actor->x + 1);

    this->actor->_timeToUpdate = (this->actor->_timeToUpdate + 1) % FRAME_COUNT_PER_SECOND / 2;
    if(this->actor->_timeToUpdate != 0) return;

    this->actor->deltaY += this->actor->weight;
    if(this->actor->deltaY < -5) this->actor->deltaY = -5;
    if(this->actor->deltaY > 2.5) this->actor->deltaY = 2.5;

    for(Obstacle* obstacle : this->actor->obstacleList) {
        if(obstacle == nullptr) continue;
        if(this->actor->collidesWith(obstacle)) {
            bn::string<32> instanceName = obstacle->getInstanceName();
            if(instanceName == ((bn::string<32>) "PIPE")) {
                // this->actor->currentState = Bird::HIT_A_PIPE;
            }
        }
    }
    this->actor->calculateRotation();
    this->render();
}

void _FlappyBird::PlayState::render() {
    this->actor->setX(this->actor->x + this->actor->deltaX);
    this->actor->setY(this->actor->y + this->actor->deltaY);
    this->actor->animation->update();
    if(this->actor->hitbox.has_value()) this->actor->hitbox->update();
}

void _FlappyBird::PlayState::leave() {}