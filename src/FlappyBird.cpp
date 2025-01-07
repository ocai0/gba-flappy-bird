#include "Actors/FlappyBird.hpp"
#include "bn_log.h"

constexpr int FRAMES_PER_SECONDS = 55;

FlappyBird::FlappyBird(bn::fixed _x, bn::fixed _y) {
    this->setSprite(bn::sprite_items::common_bird.create_sprite(0, 0));
    this->animation = bn::create_sprite_animate_action_forever(*this->sprite, 6, bn::sprite_items::common_bird.tiles_item(), 0, 1, 2, 1);
    this->setX(_x);
    this->setY(_y);
    this->sprite->set_rotation_angle(90);
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
        this->deltaY = -5;
    }
    // this->_timeToUpdate = (this->_timeToUpdate + 1) % (FRAMES_PER_SECONDS * 4);
    // BN_LOG("this->_timeToUpdate: ", this->_timeToUpdate);
    // if(this->_timeToUpdate == 0) return;

    this->deltaY += this->weight;
    if(this->deltaY > 3.8) this->deltaY = 3.8;
    this->setY(this->y + this->deltaY);
    if(this->y > 64) this->setY(64);
}

FlappyBird* FlappyBird::showHitbox() {
    this->hitbox = (DebugBox(this->x, this->y, this->width, this->height));
    return this;
}
FlappyBird* FlappyBird::hideHitbox() {
    this->hitbox.reset();
    return this;
}