#include "UI/MainMenu.Button.hpp"

UI::Button::MainMenu::MainMenu(bn::fixed _x, bn::fixed _y) {
    this->spr1 = bn::sprite_items::ui_main_menu.create_sprite(_x, _y);
    this->spr2 = bn::sprite_items::ui_main_menu.create_sprite(_x + 32, _y);
    this->spr2->set_tiles(bn::sprite_items::ui_main_menu.tiles_item().create_tiles(1));
}

UI::Button::MainMenu* UI::Button::MainMenu::select() {
    this->spr1->set_tiles(bn::sprite_items::ui_main_menu.tiles_item().create_tiles(0));
    this->spr2->set_tiles(bn::sprite_items::ui_main_menu.tiles_item().create_tiles(1));
    return this;
}

UI::Button::MainMenu* UI::Button::MainMenu::unselect() {
    this->spr1->set_tiles(bn::sprite_items::ui_main_menu.tiles_item().create_tiles(2));
    this->spr2->set_tiles(bn::sprite_items::ui_main_menu.tiles_item().create_tiles(3));
    return this;
}

UI::Button::MainMenu* UI::Button::MainMenu::setX(bn::fixed _x) {
    this->x = _x;
    this->spr1->set_x(this->x);
    this->spr2->set_x(this->x + 32);
    return this;
}

UI::Button::MainMenu* UI::Button::MainMenu::setY(bn::fixed _y) {
    this->y = _y;
    this->spr1->set_y(this->y);
    this->spr2->set_y(this->y);
    return this;
}

void UI::Button::MainMenu::render() {

}
