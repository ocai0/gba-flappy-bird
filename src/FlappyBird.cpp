#include "Actors/FlappyBird.hpp"
#include "bn_log.h"

FlappyBird::FlappyBird(bn::fixed _x, bn::fixed _y) {
    this->setSprite(bn::sprite_items::common_bird.create_sprite(0, 0));
    this->animation = bn::create_sprite_animate_action_forever(*this->sprite, 6, bn::sprite_items::common_bird.tiles_item(), 0, 1, 2, 1);
    this->setX(_x);
    this->setY(_y);
    this->rotationAngle = 90;
    this->sprite->set_rotation_angle(this->rotationAngle);
    this->stateMachine = new StateMachine();
    this->stateMachine->set(new _FlappyBird::IdleState(this));
}

FlappyBird* FlappyBird::setWeight(bn::fixed _weight) {
    this->weight = _weight;
    return this;
}

FlappyBird* FlappyBird::setSprite(bn::sprite_ptr _sprite) {
    this->sprite = _sprite;
    return this;
}

void FlappyBird::setX(bn::fixed _x) {
    this->x = _x;
    if(this->sprite.has_value()) this->sprite->set_x(this->x + this->offsetX);
    if(this->hitbox.has_value()) this->hitbox->setX(this->x);
}

void FlappyBird::setY(bn::fixed _y) {
    this->y = _y;
    if(this->sprite.has_value()) this->sprite->set_y(this->y + this->offsetY);
    if(this->hitbox.has_value()) this->hitbox->setY(this->y);
}

void FlappyBird::update() {
    this->stateMachine->update();
}

FlappyBird* FlappyBird::showHitbox() {
    this->hitbox = DebugBox(this->x, this->y, this->width, this->height);
    return this;
}
FlappyBird* FlappyBird::hideHitbox() {
    this->hitbox.reset();
    return this;
}

void FlappyBird::calculateRotation() {
    if(bn::keypad::up_pressed()) this->rotationAngle-=1;
    if(bn::keypad::down_pressed()) this->rotationAngle+=1;
    this->sprite->set_rotation_angle(bn::clamp(this->rotationAngle.integer(), 0, 180));
}

bool FlappyBird::collidesWith(Obstacle* other) {
    return this->x < other->x + other->width 
        && this->x + this->width > other->x 
        && this->y < other->y + other->height 
        && this->y + this->height > other->y;
}

bool FlappyBird::collidesWith(bn::fixed _x, bn::fixed _y, int _width, int _height, Obstacle* _other) {
    return _x < _other->x + _other->width 
        && _x + _width > _other->x 
        && _y < _other->y + _other->height 
        && _y + _height > _other->y;
}

void FlappyBird::watchObstacles(bn::array<Obstacle*, 10> _obstacleList) {
    this->obstacleList = _obstacleList;
}
FlappyBird* FlappyBird::setCamera(bn::optional<bn::camera_ptr> _camera) {
    if(this->sprite.has_value()) this->sprite->set_camera(_camera.value());
    if(this->hitbox.has_value()) this->hitbox->setCamera(_camera);
    return this;
}

void FlappyBird::routineFallFromAHit() {
    if(!this->fallFromAHit) {
        bn::sound_items::sfx_hit.play();
        this->fallFromAHit = new Vars::routineFallFromAHit();
        this->deltaY = -3.5;
        this->fallFromAHit->floorNotHit = true;
    }

    if(this->fallFromAHit->floorNotHit) {
        this->deltaY += .3;
        if(this->deltaY > -1 && !this->fallFromAHit->dieSoundPlayed) {
            bn::sound_items::sfx_die.play();
            this->fallFromAHit->dieSoundPlayed = true;
        }
        for(Obstacle* obstacle : this->obstacleList) {
            if(obstacle == nullptr) continue;
            bn::string<32> _instanceName = obstacle->getInstanceName();
            if(_instanceName != (bn::string<32>) "FLOOR") continue;

            if(this->collidesWith(this->x, this->y + this->deltaY - 2, this->width, this->height, obstacle)) {
                this->deltaY = 0;
                this->fallFromAHit->floorNotHit = false;
            }
        }
        this->setY(this->y + this->deltaY);
    }
    else {
        // this->currentState = Bird::IS_DEAD;
    }
    if(this->hitbox.has_value()) this->hitbox->update();
}