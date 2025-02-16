#include "Scenes/Gameplay/Gameplay.Scene.InGame.hpp"

bn::fixed getReadyTransparencyValue = 1;

_Gameplay::InGame::InGame(Scene::Gameplay* _parentState) {
    this->parentState = _parentState;
}

void _Gameplay::InGame::load() {
    this->parentState->score->update();
}

void _Gameplay::InGame::update() {
    if(this->parentState->getReadyBg.has_value()) {
        getReadyTransparencyValue -= .05;
        if(getReadyTransparencyValue < 0) getReadyTransparencyValue = 0;
        bn::blending::set_transparency_alpha(getReadyTransparencyValue);
        if(getReadyTransparencyValue == 0) this->parentState->getReadyBg.reset();
    }
    this->parentState->player->update();
    if(bn::keypad::start_pressed()) {
        this->parentState->stateMachine->set(new _Gameplay::Paused(this->parentState));
    }
    if(bn::keypad::l_held()) {
        this->parentState->camera->set_y(this->parentState->camera->y() - 1);
    }
    if(bn::keypad::r_held()) {
        this->parentState->camera->set_y(this->parentState->camera->y() + 1);
    }
    this->parentState->floor->update();
    this->parentState->background->update();
}

void _Gameplay::InGame::render() {
    this->parentState->player->render();
}

void _Gameplay::InGame::leave() {

}

