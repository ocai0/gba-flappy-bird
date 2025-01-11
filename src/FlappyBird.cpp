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
    this->animation->update();
    if(this->hitbox.has_value()) this->hitbox->update();
    if(bn::keypad::a_pressed()) {
        this->deltaY = -150;
    }
    if(this->deltaY < 0 && bn::keypad::a_released()) {
        this->deltaY = 0;
    }

    this->_timeToUpdate = (this->_timeToUpdate + 1) % FRAME_COUNT_PER_SECOND / 2;
    if(this->_timeToUpdate != 0) return;

    this->deltaY += this->weight;
    this->setY(this->y + bn::clamp(this->deltaY.integer(), -4, 3));
    if(this->y > 64) this->setY(64);
    //this->calculateRotation();
}

FlappyBird* FlappyBird::showHitbox() {
    this->hitbox = (DebugBox(this->x, this->y, this->width, this->height));
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