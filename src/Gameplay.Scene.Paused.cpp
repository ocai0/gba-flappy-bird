#include "Scenes/Gameplay/Gameplay.Scene.Paused.hpp"

_Gameplay::Paused::Paused(Scene::Gameplay* _parentState) {
    this->parentState = _parentState;
}

void _Gameplay::Paused::load() {
    this->parentState->player->hide();
    this->parentState->score->hide();
    
    for(PipeWall* pipeWall: this->parentState->pipes) {
        pipeWall->topPipe->hide();
        pipeWall->bottomPipe->hide();
    }

    this->pausedText = new UI::Text::Paused(-15, 2);
}

void _Gameplay::Paused::update() {
    if(bn::keypad::start_pressed()) {
        this->parentState->stateMachine->set(new _Gameplay::InGame(this->parentState));
    }
}

void _Gameplay::Paused::render() {}

void _Gameplay::Paused::leave() {
    delete this->pausedText;
    this->parentState->player->show();
    this->parentState->score->show();
    for(PipeWall* pipeWall: this->parentState->pipes) {
        pipeWall->topPipe->show();
        pipeWall->bottomPipe->show();
    }
}

