#include "Scenes/Gameplay/Gameplay.Scene.InGame.hpp"
#include "bn_log.h"

bn::fixed getReadyTransparencyValue = 1;

_Gameplay::InGame::InGame(Scene::Gameplay* _parentState) {
    this->parentState = _parentState;
}

void _Gameplay::InGame::load() {
    this->parentState->score->update();
    this->parentState->score->show();
}

void _Gameplay::InGame::update() {
    if(this->parentState->getReadyBg.has_value()) {
        getReadyTransparencyValue -= .05;
        if(getReadyTransparencyValue < 0) getReadyTransparencyValue = 0;
        bn::blending::set_transparency_alpha(getReadyTransparencyValue);
        if(getReadyTransparencyValue == 0) {
            this->parentState->getReadyBg.reset();
            bn::blending::set_transparency_alpha(1);
        }
    }
    this->parentState->player->update();
    for(int index=this->parentState->pipeLastItemIndex; index >= 0 ; index--) {
        PipeWall* pipeWall = this->parentState->pipes.at(index);
        pipeWall->x -= bn::fixed(.5);
        if(!pipeWall->scored && this->parentState->player->x > pipeWall->x) {
            bn::sound_items::sfx_point.play();
            int currentScore = this->parentState->score->getValue();
            this->parentState->score->setValue(currentScore + 1);
            pipeWall->scored = true;
        }
        if(pipeWall->x <= -bn::display::width() / 2 - pipeWall->topPipe->getWidth()) {
            int _neighborPipeIndex = index - 1;
            if(_neighborPipeIndex < 0) _neighborPipeIndex = this->parentState->pipeLastItemIndex;
            PipeWall* _neighborPipe = this->parentState->pipes.at(_neighborPipeIndex);
            this->parentState->randomGenerator->update();
            pipeWall->y = this->parentState->randomGenerator->get_int(-124, -48);
            pipeWall->x = _neighborPipe->x + _neighborPipe->topPipe->getWidth() + this->parentState->GAP_SIZE_BTW_PIPES;
            pipeWall->scored = false;
        }
    }

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
    if(this->parentState->player->getStateName() == (bn::string<32>) "FallState") {
        this->parentState->stateMachine->set(new _Gameplay::GameOver(this->parentState));
    }
    if(this->parentState->player->getStateName() == (bn::string<32>) "DeadState") {
        bn::sound_items::sfx_hit.play();
        this->parentState->stateMachine->set(new _Gameplay::GameOver(this->parentState));
    }
}

void _Gameplay::InGame::render() {
    this->parentState->player->render();
    for(PipeWall* pipeWall : this->parentState->pipes) {
        if(pipeWall == nullptr) continue;
        pipeWall->topPipe->setX(pipeWall->x);
        pipeWall->bottomPipe->setX(pipeWall->x);

        pipeWall->topPipe->setY(pipeWall->y);
        pipeWall->bottomPipe->setY(pipeWall->y + pipeWall->topPipe->getHeight() + this->parentState->GAP_SIZE);
    }
    this->parentState->score->update();
}

void _Gameplay::InGame::leave() {

}

