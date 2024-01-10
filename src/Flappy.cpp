#include "Entities/Flappy.hpp"
#include "bn_log.h"

// The Flappy sprite renders at the middle of the hitbox area, and the offset values moves its final position

Flappy::Flappy(int _x, int _y, int _width, int _height, int _offsetX, int _offsetY): width(_width), height(_height), offsetX(_offsetX), offsetY(_offsetY), debugBox(_x, _y, _width, _height) {
    this->setX(_x);
    this->setY(_y);
    this->setAliveFlag(true);
}

int Flappy::getX() {
    return this->x;
}
void Flappy::setX(int _x) {
    this->delta.x = _x;
}

int Flappy::getY() {
    return this->y;
}
void Flappy::setY(int _y) {
    this->delta.y = _y;
}

int Flappy::getRotation() {
    return this->rotation;
}
void Flappy::setRotation(int _angle) {
    this->delta.rotation = clamp(_angle, 0, 360);
    BN_LOG("this->delta.rotation: ", this->delta.rotation);
}

int Flappy::getWidth() {
    return this->width;
}
void Flappy::setWidth(int _width) {
    this->width = _width;
}

int Flappy::getHeight() {
    return this->height;
}
void Flappy::setHeight(int _height) {
    this->height = _height;
}

bool Flappy::isAlive() {
    return this->alive ;
}
void Flappy::setAliveFlag(bool _alive) {
    this->alive = _alive;
}

bool Flappy::isColliding() {
    return this->colliding;
}
void Flappy::setCollidingFlag(bool _colliding) {
    this->colliding = _colliding;
}


void Flappy::setSkin(Skin _skinType) {
    switch(_skinType) {
        case Skin::YELLOW:
        default:
            this->flappy_sprite.set_palette(bn::sprite_items::flappy.palette_item());
            break;
        case Skin::BLUE:
            // this->flappy_sprite.set_palette(bn::sprite_items::flappy_blue.palette());
            break;
    }
}
void Flappy::update() {
    this->x = this->delta.x;
    this->y = this->delta.y;
    this->rotation = this->delta.rotation;

    int width_half = (this->width >> 2);
    int height_half = (this->height >> 2);

    this->flappy_sprite.set_x(this->x + width_half + this->offsetX);
    this->flappy_sprite.set_y(this->y + height_half + this->offsetY);
    this->flappy_sprite.set_rotation_angle(this->delta.rotation);

    this->debugBox.setX(this->x);
    this->debugBox.setY(this->y);
    this->debugBox.update();
    this->animation.update();
}
void Flappy::calculateValues() {
    // handleVerticalMovement
    // HandleHorizontalMovement
}
void Flappy::playDeathAnimation() {}

void Flappy::setVisible(bool visible) {
    this->flappy_sprite.set_visible(visible);
    this->debugBox.setVisible(visible);
}