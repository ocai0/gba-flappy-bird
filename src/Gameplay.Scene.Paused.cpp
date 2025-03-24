#include "Scenes/Gameplay/Gameplay.Scene.Paused.hpp"


_Gameplay::Paused::Paused(Scene::Gameplay* _gameplayScene) {
    this->gameplayScene = _gameplayScene;
}

void _Gameplay::Paused::load() {
    this->gameplayScene->player->hide();
    this->gameplayScene->score->hide();
    
    for(PipeWall* pipeWall : this->gameplayScene->pipes) {
        pipeWall->topPipe->hide();
        pipeWall->bottomPipe->hide();
    }

    this->pausedText = new UI::Text::Paused(-15, 2);
}

void _Gameplay::Paused::update() {
    if(bn::keypad::start_pressed()) {
        this->gameplayScene->stateMachine->set(new _Gameplay::InGame(this->gameplayScene));
    }
}

void _Gameplay::Paused::render() {}

void _Gameplay::Paused::leave() {
    delete this->pausedText;
    this->pausedText = nullptr;
    this->gameplayScene->player->show();
    this->gameplayScene->score->show();
    for(PipeWall* pipeWall : this->gameplayScene->pipes) {
        pipeWall->topPipe->show();
        pipeWall->bottomPipe->show();
    }
}

