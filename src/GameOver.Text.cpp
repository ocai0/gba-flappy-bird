#include "UI/GameOver.Text.hpp"


UI::Text::GameOver::GameOver(bn::fixed _x, bn::fixed _y) {
    this->spr1 = bn::sprite_items::ui_game_over.create_sprite(0, 0);
    this->spr2 = bn::sprite_items::ui_game_over.create_sprite(0 + 32, 0);
    this->spr2->set_tiles(bn::sprite_items::ui_game_over.tiles_item().create_tiles(1));
    this->spr3 = bn::sprite_items::ui_game_over.create_sprite(0 + 64, 0);
    this->spr3->set_tiles(bn::sprite_items::ui_game_over.tiles_item().create_tiles(2));
    this->setX(_x);
    this->setY(_y);
}

UI::Text::GameOver* UI::Text::GameOver::setX(bn::fixed _x) {
    this->x = _x;
    this->spr1->set_x(this->x);
    this->spr2->set_x(this->x + 32);
    this->spr3->set_x(this->x + 64);
    return this;
}

UI::Text::GameOver* UI::Text::GameOver::setY(bn::fixed _y) {
    this->y = _y;
    this->spr1->set_y(this->y);
    this->spr2->set_y(this->y);
    this->spr3->set_y(this->y);
    return this;
}

UI::Text::GameOver* UI::Text::GameOver::show() {
    return this;
}

UI::Text::GameOver* UI::Text::GameOver::hide() {
    return this;
}

UI::Text::GameOver::~GameOver() {
    this->spr1->~sprite_ptr();
    this->spr2->~sprite_ptr();
    this->spr3->~sprite_ptr();
    bn::core::update();
}
