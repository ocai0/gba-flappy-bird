#include "Scenes/Gameplay/Gameplay.Scene.InGame.hpp"
#include "bn_log.h"


bn::fixed getReadyTransparencyValue = 1;

_Gameplay::InGame::InGame(Scene::Gameplay* _gameplayScene) {
    this->gameplayScene = _gameplayScene;
    this->setName("_Gameplay::InGame");
}

void _Gameplay::InGame::load() {
    this->gameplayScene->score->show();
}

void _Gameplay::InGame::update() {
    if(this->gameplayScene->getReadyBg.has_value()) {
        getReadyTransparencyValue -= .05;
        if(getReadyTransparencyValue < 0) getReadyTransparencyValue = 0;
        bn::blending::set_transparency_alpha(getReadyTransparencyValue);
        if(getReadyTransparencyValue == 0) {
            this->gameplayScene->getReadyBg.reset();
            bn::blending::set_transparency_alpha(1);
        }
    }
    this->gameplayScene->player->update();
    for(int index=this->gameplayScene->pipeLastItemIndex; index >= 0 ; index--) {
        PipeWall* pipeWall = this->gameplayScene->pipes.at(index);
        pipeWall->x -= bn::fixed(.5);
        if(!pipeWall->scored && this->gameplayScene->player->x > pipeWall->x) {
            bn::sound_items::sfx_point.play();
            int currentScore = this->gameplayScene->score->getValue();
            this->gameplayScene->score->setValue(currentScore + 1);
            pipeWall->scored = true;
        }
        if(pipeWall->x <= -bn::display::width() / 2 - pipeWall->topPipe->getWidth()) {
            int _neighborPipeIndex = index - 1;
            if(_neighborPipeIndex < 0) _neighborPipeIndex = this->gameplayScene->pipeLastItemIndex;
            PipeWall* _neighborPipe = this->gameplayScene->pipes.at(_neighborPipeIndex);
            this->gameplayScene->randomGenerator->update();
            pipeWall->y = this->gameplayScene->randomGenerator->get_int(-124, -48);
            pipeWall->x = _neighborPipe->x + _neighborPipe->topPipe->getWidth() + this->gameplayScene->GAP_SIZE_BTW_PIPES;
            pipeWall->scored = false;
        }
    }

    if(bn::keypad::start_pressed()) {
        this->gameplayScene->stateMachine->set(new _Gameplay::Paused(this->gameplayScene));
    }
    if(bn::keypad::l_held()) {
        this->gameplayScene->camera.set_y(this->gameplayScene->camera.y() - 1);
    }
    if(bn::keypad::r_held()) {
        this->gameplayScene->camera.set_y(this->gameplayScene->camera.y() + 1);
    }
    this->gameplayScene->floor->update();
    this->gameplayScene->background->update();
    if(this->gameplayScene->player->getStateName() == (bn::string<32>) "FallState") {
        this->gameplayScene->stateMachine->set(new _Gameplay::GameOver(this->gameplayScene));
    }
    if(this->gameplayScene->player->getStateName() == (bn::string<32>) "DeadState") {
        bn::sound_items::sfx_hit.play();
        this->gameplayScene->stateMachine->set(new _Gameplay::GameOver(this->gameplayScene));
    }
}

void _Gameplay::InGame::render() {
    this->gameplayScene->player->render();
    for(PipeWall* pipeWall : this->gameplayScene->pipes) {
        if(pipeWall == nullptr) continue;
        pipeWall->topPipe->setX(pipeWall->x);
        pipeWall->bottomPipe->setX(pipeWall->x);

        pipeWall->topPipe->setY(pipeWall->y);
        pipeWall->bottomPipe->setY(pipeWall->y + pipeWall->topPipe->getHeight() + this->gameplayScene->GAP_SIZE);
    }
}

void _Gameplay::InGame::leave() {
    this->gameplayScene = nullptr;
}

