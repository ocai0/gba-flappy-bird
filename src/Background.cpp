#include "Entities/Background.hpp"

constexpr bn::regular_bg_item bgDay(bn::regular_bg_items::bg_day.tiles_item(), bn::bg_palette_items::palette_bg, bn::regular_bg_items::bg_day.map_item());
constexpr bn::regular_bg_item bgNight(bn::regular_bg_items::bg_night.tiles_item(), bn::bg_palette_items::palette_bg, bn::regular_bg_items::bg_night.map_item());

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
                this->current = bgDay.create_bg_optional(0, 0);
                break;
            }
        case NIGHT:
            {
                this->current = bgNight.create_bg_optional(0, 0);
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


void Background::setBlendingEnabled(bool _enabled) {
    return this->current.get()->set_blending_enabled(_enabled);
}