#include "Actors/FlappyBird.hpp"
#include "bn_log.h"

constexpr int FRAME_COUNT_PER_SECOND = 60;

FlappyBird::FlappyBird(bn::fixed _x, bn::fixed _y) {
    this->setSprite(bn::sprite_items::common_bird.create_sprite(0, 0));
    this->animation = bn::create_sprite_animate_action_forever(*this->sprite, 6, bn::sprite_items::common_bird.tiles_item(), 0, 1, 2, 1);
    this->setX(_x);
    this->setY(_y);
    this->rotationAngle = 90;
    this->sprite->set_rotation_angle(this->rotationAngle);
    this->currentState = Bird::IS_ALIVE;
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

void FlappyBird::idle() {
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

void FlappyBird::update() {
    switch(this->currentState) {
        default:
        case Bird::IS_ALIVE:
            this->routineAlive();
            break;
        case Bird::HIT_A_PIPE:
            this->routineFallFromAHit();
            break;
    }
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

bool FlappyBird::collidesWith(bn::fixed x, bn::fixed y, int width, int height, Obstacle* other) {
    return x < other->x + other->width 
        && x + width > other->x 
        && y < other->y + other->height 
        && y + height > other->y;
}

void FlappyBird::watchObstacles(bn::array<Obstacle*, 10> _obstacleList) {
    this->obstacleList = _obstacleList;
}
FlappyBird* FlappyBird::setCamera(bn::optional<bn::camera_ptr> _camera) {
    if(this->sprite.has_value()) this->sprite->set_camera(_camera.value());
    if(this->hitbox.has_value()) this->hitbox->setCamera(_camera);
    return this;
}

void FlappyBird::routineAlive() {
    this->animation->update();
    if(this->hitbox.has_value()) this->hitbox->update();
    if(bn::keypad::a_pressed()) {
        this->deltaY = -10;
    }
    if(this->deltaY < 0 && bn::keypad::a_released()) {
        this->deltaY = 0;
    }

    if(bn::keypad::left_held()) this->setX(this->x - 1);
    if(bn::keypad::right_held()) this->setX(this->x + 1);

    this->_timeToUpdate = (this->_timeToUpdate + 1) % FRAME_COUNT_PER_SECOND / 2;
    if(this->_timeToUpdate != 0) return;

    this->deltaY += this->weight;
    bn::fixed _normalizedDeltaY = this->deltaY;
    if(this->deltaY < -5) _normalizedDeltaY = -5;
    if(this->deltaY > 2.5) _normalizedDeltaY = 2.5;
    this->setY(this->y + _normalizedDeltaY);

    for(Obstacle* obstacle : this->obstacleList) {
        if(obstacle == nullptr) continue;
        if(this->collidesWith(obstacle)) {
            bn::string<32> instanceName = obstacle->getInstanceName();
            if(instanceName == ((bn::string<32>) "PIPE")) {
                this->currentState = Bird::HIT_A_PIPE;
            }
        }
    }
    this->calculateRotation();
}
void FlappyBird::routineFallFromAHit() {
    if(!this->fallFromAHit) {
        this->fallFromAHit = new Vars::routineFallFromAHit();
        this->deltaY = -3.5;
        this->fallFromAHit->floorNotHit = true;
    }

    if(this->fallFromAHit->floorNotHit) {
        this->deltaY += .3;
        for(Obstacle* obstacle : this->obstacleList) {
            if(obstacle == nullptr) continue;
            bn::string<32> instanceName = obstacle->getInstanceName();
            if(instanceName != (bn::string<32>) "FLOOR") continue;

            if(this->collidesWith(this->x, this->y + this->deltaY, this->width, this->height, obstacle)) {
                this->deltaY = 0;
                this->fallFromAHit->floorNotHit = false;
            }
        }
        this->setY(this->y + this->deltaY);
    }
    else {}
    if(this->hitbox.has_value()) this->hitbox->update();
}