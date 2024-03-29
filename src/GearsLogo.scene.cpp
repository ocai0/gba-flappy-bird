#include "Scenes/GearsLogo.scene.hpp"
#include "bn_log.h"

using namespace Scenes;

GearsLogo::GearsLogo() : bg(bn::regular_bg_items::bg_gears_logo.create_bg(0, 0)) {
    this->bg.set_blending_enabled(true);
    this->bg.set_x(0);
    this->bg.set_y(0);
}

bn::optional<SceneType> GearsLogo::update() {
    int _clock = 0;
    FadeScreenEffect fadeScreenEffect(bn::blending::fade_color_type::BLACK, .1);
    fadeScreenEffect.fadeOut();
    fadeScreenEffect.start();
    while(fadeScreenEffect.isAlive()) {
        if(_clock > 50) fadeScreenEffect.update();
        _clock++;
        bn::core::update();
    }
    this->bg.set_visible(false);
    delete &fadeScreenEffect;
    bn::core::update();
    return SceneType::MAIN_MENU;
}

