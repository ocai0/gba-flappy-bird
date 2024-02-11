#include "Entities/Button.hpp"

using namespace ui;

Button::Button(int _x, int _y, ButtonType buttonType): x(_x), y(_y) {
    this->sprite = bn::sprite_items::ui_big_btn.create_sprite_optional(_x, _y);
    this->sprite.get()->set_bg_priority(0);
    switch(buttonType) {
        case ButtonType::PLAY:
            {
                this->sprite.get()->set_tiles(bn::sprite_items::ui_big_btn.tiles_item().create_tiles(0));
                break;
            }
        case ButtonType::SCORE:
            {
                this->sprite.get()->set_tiles(bn::sprite_items::ui_big_btn.tiles_item().create_tiles(1));
                break;
            }
    }
}

void Button::setX(int _x) {
    this->x = _x;
}

void Button::setY(int _y) {
    this->y = _y;
}

int Button::getX() {
    return this->x;
}

int Button::getY() {
    return this->y;
}

void Button::update() {
    this->sprite.get()->set_x(this->x);
    this->sprite.get()->set_y(this->y);
}