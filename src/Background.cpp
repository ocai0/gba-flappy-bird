#include "Entities/Background.hpp"

Background::Background() {
    this->setX(0);
    this->setY(0);
    this->update();
}
Background::Background(int _x, int _y) {
    this->setX(_x);
    this->setY(_y);
    this->update();
}
Background::Background(int _x, int _y, BackgroundIndex _backgroundIndex) {
    this->setX(_x);
    this->setY(_y);
    this->setBackground(_backgroundIndex);
    this->update();
}

void Background::setBackground(BackgroundIndex _backgroundIndex) {
    this->current.reset();
    switch(_backgroundIndex) {
        default:
        case DAY:
            {
                this->current = bn::regular_bg_items::bg_day.create_bg_optional(0, 0);
                break;
            }
        case NIGHT:
            {
                this->current = bn::regular_bg_items::bg_night.create_bg_optional(0, 0);
                break;
            }
    }
    this->update();
}

bn::fixed Background::getX() {
    return this->x;
}
bn::fixed Background::getY() {
    return this->y;
}
void Background::setX(bn::fixed _x) {
    this->x = _x;
}
void Background::setY(bn::fixed _y) {
    this->y = _y;
}

void Background::update() {
    this->current.get()->set_x(this->x);
    this->current.get()->set_y(this->y);
}
