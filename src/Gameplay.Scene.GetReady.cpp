#include "Scenes/Gameplay/Gameplay.Scene.GetReady.hpp"

_Gameplay::GetReady::GetReady(Scene::Gameplay* _parentState) {
    this->parentState = _parentState;
}

void _Gameplay::GetReady::load() {
    this->parentState->player->setX(-80);
    this->parentState->player->setY(0);
}

void _Gameplay::GetReady::update() {
    this->parentState->getReadyBg = bn::regular_bg_items::bg_get_ready.create_bg(0, -10);
    this->parentState->getReadyBg->set_priority(1);
    this->parentState->getReadyBg->set_blending_enabled(true);
    if(!bn::keypad::a_pressed()) {
        this->parentState->player->update();
        this->parentState->floor->update();
        this->parentState->background->update();
    }
    else {
        this->parentState->stateMachine->set(new _Gameplay::InGame(this->parentState));
    }
}

void _Gameplay::GetReady::render() {
    this->parentState->player->render();
    this->parentState->score->hide();
}

void _Gameplay::GetReady::leave() {}

