#include "UI/NewFlag.hpp"

UI::NewFlag::NewFlag(bn::fixed _x, bn::fixed _y) {
    this->sprite = bn::sprite_items::ui_new_flag.create_sprite(_x, _y);
    this->setX(_x);
    this->setY(_y);
}

void UI::NewFlag::load() {

}
void UI::NewFlag::setX(bn::fixed _x) {
    this->x = _x;
    if(this->sprite.has_value()) this->sprite->set_x(this->x);
}
void UI::NewFlag::setY(bn::fixed _y) {
    this->y = _y;
    if(this->sprite.has_value()) this->sprite->set_y(this->y);
}

UI::NewFlag::~NewFlag() {
    this->sprite.reset();
    bn::core::update();
}

void UI::NewFlag::setPriority(int priority) {
    if(this->sprite.has_value() == false)  return;
    this->sprite->set_bg_priority(priority);
    this->sprite->set_z_order(priority);
}