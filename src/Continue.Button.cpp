#include "UI/Continue.Button.hpp"

UI::Button::Continue::Continue(bn::fixed _x, bn::fixed _y) {
    this->spr1 = bn::sprite_items::ui_continue.create_sprite(_x, _y);
    this->spr2 = bn::sprite_items::ui_continue.create_sprite(_x + 32, _y);
    this->spr2->set_tiles(bn::sprite_items::ui_continue.tiles_item().create_tiles(1));
}

UI::Button::Continue* UI::Button::Continue::select() {
    this->spr1->set_tiles(bn::sprite_items::ui_continue.tiles_item().create_tiles(0));
    this->spr2->set_tiles(bn::sprite_items::ui_continue.tiles_item().create_tiles(1));
    return this;
}

UI::Button::Continue* UI::Button::Continue::unselect() {
    this->spr1->set_tiles(bn::sprite_items::ui_continue.tiles_item().create_tiles(2));
    this->spr2->set_tiles(bn::sprite_items::ui_continue.tiles_item().create_tiles(3));
    return this;
}

UI::Button::Continue* UI::Button::Continue::setX(bn::fixed _x) {
    this->x = _x;
    this->spr1->set_x(this->x);
    this->spr2->set_x(this->x + 32);
    return this;
}

UI::Button::Continue* UI::Button::Continue::setY(bn::fixed _y) {
    this->y = _y;
    this->spr1->set_y(this->y);
    this->spr2->set_y(this->y);
    return this;
}

void UI::Button::Continue::render() {

}
