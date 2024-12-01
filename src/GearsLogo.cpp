#include "Scenes/GearsLogo.hpp"
#include "bn_log.h"

void Scenes::GearsLogo::load() {
    this->bg = bn::regular_bg_items::bg_gears_logo.create_bg(0, 0);
    this->bg->set_blending_enabled(true);
    this->bg->set_x(0);
    this->bg->set_y(0);
}

Scene* Scenes::GearsLogo::update() {
    int _clock = 0;
    FadeScreenEffect fadeScreenEffect(bn::blending::fade_color_type::BLACK, .1);
    const bn::bg_palette_item& palette_item = bn::regular_bg_items::bg_gears_logo.palette_item();
    const bn::bg_palette_item& palette_item_alt = bn::bg_palette_items::bg_gears_logo_alt;
    bn::bg_palette_ptr bg_palette = this->bg->palette();
    bg_palette.set_colors(palette_item);

    fadeScreenEffect.fadeOut();
    fadeScreenEffect.start();
    while(fadeScreenEffect.isAlive()) {
        if(_clock > 80) fadeScreenEffect.update();
        if(bn::keypad::a_pressed()) {
            if(bg_palette.colors() == palette_item.colors_ref()) bg_palette.set_colors(palette_item_alt);
            else bg_palette.set_colors(palette_item);
            _clock = 0;
        }
        _clock++;
        bn::core::update();
    }
    this->bg->set_visible(false);
    bn::core::update();
    return new Scenes::MainMenu;
}

void Scenes::GearsLogo::leave() {
    bg.~optional();
}

