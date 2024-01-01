#include "Flappy.hpp"

Flappy::Flappy(int _x, int _y) {
    this->setXY(_x, _y);
    this->setAliveFlag(true);
}

void Flappy::setX(int _x) {
    this->x = _x;
    this->flappy_sprite.set_x(this->x);
}
void Flappy::setY(int _y) {
    this->y = _y;
    this->flappy_sprite.set_y(this->y);
}
void Flappy::setRotation(int _angle) {
    this->rotation = _angle;
    
    if(this->rotation > 360) this->rotation = 360;
    if(this->rotation < 0) this->rotation = 0;

    this->flappy_sprite.set_rotation_angle(this->rotation);
}
int Flappy::getRotation() {
    return this->rotation;
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
CollisionBox Flappy::getCollisionBox() {
    return this->_bbox;
}

int Flappy::getWidth() {
    return this->WIDTH;
}
int Flappy::getHeight() {
    return this->HEIGHT;
}

bool Flappy::isAlive() {
    return this->alive ;
}
void Flappy::setAliveFlag(bool _alive) {
    this->alive = _alive;
}