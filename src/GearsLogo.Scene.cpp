#include "Scenes/GearsLogo.Scene.hpp"

namespace _GearsLogo {
    const bn::bg_palette_item& black_bg_palette = bn::regular_bg_items::bg_gears_logo.palette_item();
    const bn::bg_palette_item& blue_bg_palette = bn::bg_palette_items::bg_gears_logo_alt;
}

Scene::GearsLogo::GearsLogo(StateMachine* _sceneManager) {
    this->sceneManager = _sceneManager;
    bn::blending::set_fade_color(bn::blending::fade_color_type::BLACK);
    bn::blending::set_fade_alpha(0);
}

void Scene::GearsLogo::load() {
    this->bg = bn::regular_bg_items::bg_gears_logo.create_bg(0, 0);
    this->bg->set_blending_enabled(true);
    this->bg_palette = this->bg->palette();
    this->bg_palette->set_colors(_GearsLogo::black_bg_palette);
}

void Scene::GearsLogo::update() {
    if(bn::keypad::a_pressed()) {
        if(this->bg_palette->colors() == _GearsLogo::black_bg_palette.colors_ref()) this->bg_palette->set_colors(_GearsLogo::blue_bg_palette);
        else this->bg_palette->set_colors(_GearsLogo::black_bg_palette);
    }
    this->fadeValue = this->fadeValue + bn::fixed(.06);
    bn::blending::set_fade_alpha(bn::clamp(this->fadeValue, bn::fixed(0), bn::fixed(1)));
    if(this->fadeValue > 1.5) {
        this->fadeOutComplete = true;
        this->goToMainMenu = true;
    }
    
    if(this->goToMainMenu) {
        MainMenuVars userOptions;
        userOptions.birdType = Enum::BirdType::ROBOT_BIRD;
        userOptions.backgroundType = Enum::BackgroundType::CITY;
        userOptions.pipeType = Enum::BackgroundType::CITY;

        AbstractState* scene = new Scene::Gameplay(userOptions);
        this->sceneManager->set(scene);
    }
}

void Scene::GearsLogo::render() {
}

void Scene::GearsLogo::leave() {
    this->bg.reset();
    bn::blending::set_fade_alpha(0);
}
