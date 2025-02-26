#include "Scenes/GearsLogo.Scene.hpp"
#include "bn_log.h"

Scene::GearsLogo::GearsLogo(StateMachine* _sceneManager) {
    this->sceneManager = _sceneManager;
}

void Scene::GearsLogo::load() {
    this->bg = bn::regular_bg_items::bg_gears_logo.create_bg(0, 0);
    this->bg->set_blending_enabled(true);
}

void Scene::GearsLogo::update() {
    if(bn::keypad::a_pressed()) {
        this->goToMainMenu = true;
    }

    if(this->bg.has_value()) {
        this->transparencyValue -= .1;
        if(this->transparencyValue < 0) this->transparencyValue = 0;
        bn::blending::set_transparency_alpha(bn::min(this->transparencyValue, bn::fixed(1)));
        if(this->transparencyValue == 0) {
            this->goToMainMenu = true;
            this->bg.reset();
            bn::blending::set_transparency_alpha(1);
        }
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
}
