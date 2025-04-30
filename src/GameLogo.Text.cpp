#include "UI/GameLogo.Text.hpp"

UI::Text::GameLogo::GameLogo(bn::fixed _x, bn::fixed _y) {
    this->x = _x;
    this->y = _y;

    this->logo1 = bn::sprite_items::ui_flappy_bird_logo.create_sprite(this->x, this->y);

    this->logo2 = bn::sprite_items::ui_flappy_bird_logo.create_sprite(this->x + 32, this->y);
    this->logo2->set_tiles(bn::sprite_items::ui_flappy_bird_logo.tiles_item().create_tiles(1));
    
    this->logo3 = bn::sprite_items::ui_flappy_bird_logo.create_sprite(this->x + 64, this->y);
    this->logo3->set_tiles(bn::sprite_items::ui_flappy_bird_logo.tiles_item().create_tiles(2));

    
    this->advance1 = bn::sprite_items::ui_advance_logo.create_sprite(this->x + 18, this->y + 14);

    this->advance2 = bn::sprite_items::ui_advance_logo.create_sprite(this->x + 18 + 32, this->y + 14);
    this->advance2->set_tiles(bn::sprite_items::ui_advance_logo.tiles_item().create_tiles(1));
}

UI::Text::GameLogo* UI::Text::GameLogo::setX(bn::fixed _x) {
    return this;
}

UI::Text::GameLogo* UI::Text::GameLogo::setY(bn::fixed _y) {
    return this;
}

UI::Text::GameLogo* UI::Text::GameLogo::show() {
    return this;
}

UI::Text::GameLogo* UI::Text::GameLogo::hide() {
    return this;
}

UI::Text::GameLogo::~GameLogo() {
    this->logo1.reset();
    this->logo2.reset();
    this->logo3.reset();
}
