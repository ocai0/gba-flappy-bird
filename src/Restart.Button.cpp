#include "UI/Restart.Button.hpp"

UI::Button::Restart::Restart(bn::fixed _x, bn::fixed _y) {
    this->spr1 = bn::sprite_items::ui_restart.create_sprite(_x, _y);
    this->spr2 = bn::sprite_items::ui_restart.create_sprite(_x + 32, _y);
    this->spr2->set_tiles(bn::sprite_items::ui_restart.tiles_item().create_tiles(1));
}

UI::Button::Restart* UI::Button::Restart::select() {
    this->spr1->set_tiles(bn::sprite_items::ui_restart.tiles_item().create_tiles(0));
    this->spr2->set_tiles(bn::sprite_items::ui_restart.tiles_item().create_tiles(1));
    return this;
}

UI::Button::Restart* UI::Button::Restart::unselect() {
    this->spr1->set_tiles(bn::sprite_items::ui_restart.tiles_item().create_tiles(2));
    this->spr2->set_tiles(bn::sprite_items::ui_restart.tiles_item().create_tiles(3));
    return this;
}

UI::Button::Restart* UI::Button::Restart::setX(bn::fixed _x) {
    this->x = _x;
    this->spr1->set_x(this->x);
    this->spr2->set_x(this->x + 32);
    return this;
}

UI::Button::Restart* UI::Button::Restart::setY(bn::fixed _y) {
    this->y = _y;
    this->spr1->set_y(this->y);
    this->spr2->set_y(this->y);
    return this;
}

void UI::Button::Restart::render() {

}
