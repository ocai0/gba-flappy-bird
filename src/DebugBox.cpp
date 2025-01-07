#include "Actors/DebugBox.hpp"
constexpr int SPRITE_SIZE_HALF = 4; // because the sprite are rendered at the middle of the image

DebugBox::DebugBox(bn::fixed _x, bn::fixed _y, int _width, int _height): x(_x), y(_y), width(_width), height(_height) {
    this->top_left = bn::sprite_items::debug.create_sprite(0, 0);
    this->top_right = bn::sprite_items::debug.create_sprite(0, 0);
    this->bottom_left = bn::sprite_items::debug.create_sprite(0, 0);
    this->bottom_right = bn::sprite_items::debug.create_sprite(0, 0);

    this->top_left.get()->set_z_order(-2);
    this->top_right.get()->set_z_order(-2);
    this->bottom_left.get()->set_z_order(-2);
    this->bottom_right.get()->set_z_order(-2);

    this->top_right.get()->set_horizontal_flip(true);
    this->bottom_left.get()->set_vertical_flip(true);
    this->bottom_right.get()->set_vertical_flip(true);
    this->bottom_right.get()->set_horizontal_flip(true);

    this->update();
}
void DebugBox::setX(bn::fixed _x) {
    this->x = _x;
}
void DebugBox::setY(bn::fixed _y) {
    this->y = _y;
}
void DebugBox::update() {
    this->top_left.get()->set_x(this->x + SPRITE_SIZE_HALF);
    this->top_left.get()->set_y(this->y + SPRITE_SIZE_HALF);

    this->top_right.get()->set_x(this->x + this->width - SPRITE_SIZE_HALF);
    this->top_right.get()->set_y(this->y + SPRITE_SIZE_HALF);

    this->bottom_left.get()->set_x(this->x + SPRITE_SIZE_HALF);
    this->bottom_left.get()->set_y(this->y + this->height - SPRITE_SIZE_HALF);

    this->bottom_right.get()->set_x(this->x + this->width - SPRITE_SIZE_HALF);
    this->bottom_right.get()->set_y(this->y + this->height - SPRITE_SIZE_HALF);
}
void DebugBox::setVisible(bool _isVisible) {
    this->isVisible = _isVisible;
    this->top_left.get()->set_visible(this->isVisible);
    this->top_right.get()->set_visible(this->isVisible);
    this->bottom_left.get()->set_visible(this->isVisible);
    this->bottom_right.get()->set_visible(this->isVisible);

}