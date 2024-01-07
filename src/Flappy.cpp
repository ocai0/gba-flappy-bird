#include "Entities/Flappy.hpp"

Flappy::Flappy(int _x, int _y, int _width, int _height, int _offsetX, int _offsetY): width(_width), height(_height), offsetX(_offsetX), offsetY(_offsetY) {
    this->setX(_x);
    this->setY(_y);
    this->setAliveFlag(true);
}

int Flappy::getX() {
    return this->x;
}
void Flappy::setX(int _x) {
    this->x = _x;
    this->flappy_sprite.set_x(this->x);
}

int Flappy::getY() {
    return this->y;
}
void Flappy::setY(int _y) {
    this->y = _y;
    this->flappy_sprite.set_y(this->y);
}

int Flappy::getRotation() {
    return this->rotation;
}
void Flappy::setRotation(int _angle) {
    this->rotation = _angle;
    
    if(this->rotation > 360) this->rotation = 360;
    if(this->rotation < 0) this->rotation = 0;

    this->flappy_sprite.set_rotation_angle(this->rotation);
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
    return this->collided;
}
void Flappy::setCollisionFlag(bool _collided) {
    this->collided = _collided;
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
    this->setX(this->getX() + this->delta.x);
    this->setY(this->getY() + this->delta.y);
    this->setRotation(this->delta.rotation);

    this->animation.update();
}

void Flappy::calculateValues() {
    // handleVerticalMovement
    // HandleHorizontalMovement
}

void Flappy::playDeathAnimation() {}