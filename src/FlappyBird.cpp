#include "Actors/FlappyBird.hpp"
#include "bn_log.h"

constexpr int FRAMES_PER_SECONDS = 55;

FlappyBird::FlappyBird(bn::fixed _x, bn::fixed _y) {
    this->setSprite(bn::sprite_items::common_bird.create_sprite(0, 0));
    this->animation = bn::create_sprite_animate_action_forever(*this->sprite, 6, bn::sprite_items::common_bird.tiles_item(), 0, 1, 2, 1);
    this->x = _x;
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

void FlappyBird::setY(bn::fixed _y) {
    this->y = _y;
    if(this->sprite.has_value()) this->sprite->set_y(this->y);
}

void FlappyBird::update() {
    
    this->animation->update();
    if(bn::keypad::a_pressed()) {
        this->deltaY = -5;
    }
    if(++this->_timeToUpdate % (FRAMES_PER_SECONDS/4) == 0) return;
    this->deltaY += this->weight;
    BN_LOG("deltaY: ", this->deltaY);
    if(this->deltaY > 3.8) this->deltaY = 3.8;
    this->setY(this->y + this->deltaY);
    if(this->y > 64) this->setY(64);
}