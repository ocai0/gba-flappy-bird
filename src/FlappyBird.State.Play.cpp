#include "Actors/FlappyBird/FlappyBird.State.Play.hpp"

constexpr int FRAME_COUNT_PER_SECOND = 60;
constexpr bn::fixed MAX_GRAVITY_VALUE = 3.7;
constexpr bn::fixed VERTICAL_FORCE = -6.5;
constexpr bn::fixed MAX_VERTICAL_FORCE = -7;

_FlappyBird::PlayState::PlayState(FlappyBird* _actor) {
    this->actor = _actor;
}

void _FlappyBird::PlayState::load() {}

void _FlappyBird::PlayState::update() {
    if(bn::keypad::a_pressed()) {
        bn::sound_items::sfx_wing.play();
        this->actor->deltaY = VERTICAL_FORCE;
    }
    if(this->actor->deltaY < 0 && bn::keypad::a_released()) {
        this->actor->deltaY = 0;
    }

    if(bn::keypad::left_held()) this->actor->setX(this->actor->x - 1);
    if(bn::keypad::right_held()) this->actor->setX(this->actor->x + 1);

    this->deltaTime = (this->deltaTime + 1) % FRAME_COUNT_PER_SECOND / 2;
    if(this->deltaTime != 0) return;

    this->actor->deltaY += this->actor->weight;
    if(this->actor->deltaY < MAX_VERTICAL_FORCE) this->actor->deltaY = MAX_VERTICAL_FORCE;
    if(this->actor->deltaY > MAX_GRAVITY_VALUE) this->actor->deltaY = MAX_GRAVITY_VALUE;

    for(Obstacle* obstacle : this->actor->obstacleList) {
        if(obstacle == nullptr) continue;
        if(this->actor->collidesWith(obstacle)) {
            bn::string<32> instanceName = obstacle->getInstanceName();
            if(instanceName == ((bn::string<32>) "PIPE")) {
                this->actor->stateMachine->set(new _FlappyBird::FallState(this->actor));
            }
        }
    }
    this->actor->calculateRotation();
}

void _FlappyBird::PlayState::render() {
    this->actor->setX(this->actor->x + this->actor->deltaX);
    this->actor->setY(this->actor->y + this->actor->deltaY);
    this->actor->animation->update();
    if(this->actor->hitbox.has_value()) this->actor->hitbox->update();
}

void _FlappyBird::PlayState::leave() {}