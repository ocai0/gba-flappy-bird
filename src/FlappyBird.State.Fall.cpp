#include "Actors/FlappyBird/FlappyBird.State.Fall.hpp"


_FlappyBird::FallState::FallState(FlappyBird* _actor) {
    this->actor = _actor;
    this->setName("FallState");
}

void _FlappyBird::FallState::load() {
    bn::sound_items::sfx_hit.play();
    this->actor->deltaY = -3.5;
    this->floorNotHit = true;
}

void _FlappyBird::FallState::update() {
    if(this->floorNotHit) {
        this->actor->deltaY += .3;
        if(this->actor->deltaY > -1 && !this->dieSoundPlayed) {
            bn::sound_items::sfx_die.play();
            this->dieSoundPlayed = true;
        }
        for(Obstacle* obstacle : this->actor->obstacleList) {
            if(obstacle == nullptr) continue;
            bn::string<32> _instanceName = obstacle->getInstanceName();
            if(_instanceName != (bn::string<32>) "FLOOR") continue;

            if(this->actor->collidesWith(obstacle)) {
                this->actor->deltaY = 0;
                this->floorNotHit = false;
            }
        }
    }
    else {
        this->actor->stateMachine->set(new _FlappyBird::DeadState(this->actor));
    }
}

void _FlappyBird::FallState::render() {
    this->actor->setX(this->actor->x + this->actor->deltaX);
    this->actor->setY(this->actor->y + this->actor->deltaY);
    if(this->floorNotHit) this->actor->animation->update();
    if(this->actor->hitbox.has_value()) this->actor->hitbox->update();
}

void _FlappyBird::FallState::leave() {}