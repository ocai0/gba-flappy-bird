#include "UI/Footer.Text.hpp"


UI::Text::Footer::Footer(bn::fixed _x, bn::fixed _y) {
    this->spr1 = bn::sprite_items::ui_gears_footer.create_sprite(_x, _y);
    this->spr2 = bn::sprite_items::ui_gears_footer.create_sprite(_x + 32, _y);
    this->spr2->set_tiles(bn::sprite_items::ui_gears_footer.tiles_item().create_tiles(1));
}

UI::Text::Footer* UI::Text::Footer::setX(bn::fixed _x) {
    this->x = _x;
    this->spr1->set_x(this->x);
    this->spr2->set_x(this->x + 32);
    return this;
}

UI::Text::Footer* UI::Text::Footer::setY(bn::fixed _y) {
    this->y = _y;
    this->spr1->set_y(this->y);
    this->spr2->set_y(this->y);
    return this;
}

UI::Text::Footer* UI::Text::Footer::setRenderPriority(int _priority) {
    this->spr1->set_bg_priority(_priority);
    this->spr1->set_z_order(_priority);
    this->spr2->set_bg_priority(_priority);
    this->spr2->set_z_order(_priority);
    return this;
}

void UI::Text::Footer::render() {

}

UI::Text::Footer::~Footer() {
    this->spr1.reset();
    this->spr2.reset();
}