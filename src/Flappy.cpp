#include "Flappy.hpp"

Flappy::Flappy(int _x, int _y) {
    this->x = _x;
    this->y = _y;
}

void Flappy::setX(int _x) {
    this->x = _x;
}
void Flappy::setY(int _y) {
    this->y = _y;
}
void Flappy::setXY(int _x, int _y) {
    this->x = _x;
    this->y = _y;
}
int Flappy::getX() {
    return this->x;
}
int Flappy::getY() {
    return this->y;
}
void Flappy::update() {
    this->flappy_sprite.set_y(this->y);
    this->flappy_sprite.set_x(this->x);
    this->animation.update();
}
BoundingBox Flappy::getBoundingBox() {
    return this->_bbox;
}