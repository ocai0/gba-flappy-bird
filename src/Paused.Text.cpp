#include "UI/Paused.Text.hpp"

UI::Text::Paused::Paused(bn::fixed _x, bn::fixed _y) {
    this->spr1 = bn::sprite_items::ui_paused.create_sprite(0, 0);
    this->spr2 = bn::sprite_items::ui_paused.create_sprite(0 + 32, 0);
    this->spr2->set_tiles(bn::sprite_items::ui_paused.tiles_item().create_tiles(1));
    this->setX(_x);
    this->setY(_y);
}

UI::Text::Paused* UI::Text::Paused::setX(bn::fixed _x) {
    this->x = _x;
    this->spr1->set_x(this->x);
    this->spr2->set_x(this->x + 32);
    return this;
}

UI::Text::Paused* UI::Text::Paused::setY(bn::fixed _y) {
    this->y = _y;
    this->spr1->set_y(this->y);
    this->spr2->set_y(this->y);
    return this;
}

UI::Text::Paused* UI::Text::Paused::show() {
    return this;
}

UI::Text::Paused* UI::Text::Paused::hide() {
    return this;
}

UI::Text::Paused::~Paused() {
    this->spr1->~sprite_ptr();
    this->spr2->~sprite_ptr();
    bn::core::update();
}
