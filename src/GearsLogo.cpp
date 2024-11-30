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
    fadeScreenEffect.fadeOut();
    fadeScreenEffect.start();
    while(fadeScreenEffect.isAlive()) {
        if(_clock > 80) fadeScreenEffect.update();
        if(bn::keypad::a_pressed()) {
            if(this->blueBgActive) this->bg = bn::regular_bg_items::bg_gears_logo.create_bg(0, 0);
            else this->bg = bn::regular_bg_items::bg_gears_logo_alt.create_bg(0, 0);
            this->blueBgActive = !this->blueBgActive;
            _clock = 0;
        }
        _clock++;
        bn::core::update();
    }
    this->bg->set_visible(false);
    bn::core::update();
    delete &fadeScreenEffect;
    return new Scenes::GearsLogo;
}

void Scenes::GearsLogo::leave() {
    bg.~optional();
}

