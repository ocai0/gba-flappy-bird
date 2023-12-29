#include "Flappy.hpp"
#include "bn_log.h"

Flappy::Flappy(int _x, int _y) {
    this->setXY(_x, _y);
}

void Flappy::setX(int _x) {
    this->x = _x;
    this->flappy_sprite.set_x(this->x);
}
void Flappy::setY(int _y) {
    this->y = _y;
    this->flappy_sprite.set_y(this->y);
}
void Flappy::setXY(int _x, int _y) {
    this->x = _x;
    this->y = _y;
    this->flappy_sprite.set_y(this->y);
    this->flappy_sprite.set_x(this->x);
}
int Flappy::getX() {
    return this->x;
}
int Flappy::getY() {
    return this->y;
}
void Flappy::update() {
    this->animation.update();
}
BoundingBox Flappy::getBoundingBox() {
    return this->_bbox;
}