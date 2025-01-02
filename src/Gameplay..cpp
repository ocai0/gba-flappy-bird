#include "Scenes/Gameplay.hpp"
#include "bn_log.h"

Scenes::Gameplay::Gameplay() {
    MainMenuVars userOptions;
    this->init(userOptions);
}

Scenes::Gameplay::Gameplay(MainMenuVars& userOptions) {
    this->init(userOptions);
}

void Scenes::Gameplay::init(MainMenuVars& options) {}

void Scenes::Gameplay::load() {}

Scene* Scenes::Gameplay::update() {
    while(1) {
        bn::core::update();
    }
}

void Scenes::Gameplay::leave() {}

void Scenes::Gameplay::setGetReadyState() {}

void Scenes::Gameplay::setGameState() {}

void Scenes::Gameplay::setBonusState() {}

Scene* Scenes::Gameplay::setPauseState() {
    return this->nextScene;
}

Scene* Scenes::Gameplay::setGameOverState() {
    return this->nextScene;
}

Scene* Scenes::Gameplay::setYouWinState() {
    return this->nextScene;
}