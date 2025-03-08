#include "UI/ScoreBoard/ScoreBoard.State.Appear.hpp"
#include "bn_keypad.h"


_ScoreBoard::Appear::Appear(UI::ScoreBoard* _scoreboard) {
    this->setName("Appear");
    this->scoreboard = _scoreboard;
}

void _ScoreBoard::Appear::load() {
    this->scoreboard->deltaY = -6;
    this->y = this->initalPosY;
}

void _ScoreBoard::Appear::update() {
    this->y = this->y + this->scoreboard->deltaY;
    if(this->y < this->finalPosY) {
        this->y = this->finalPosY;
        this->scoreboard->stateMachine->set(new _ScoreBoard::ScoreAnimation(this->scoreboard));
    }
}

void _ScoreBoard::Appear::render() {
    if(this->scoreboard == nullptr) return; 
    this->scoreboard->setY(this->y);
}

void _ScoreBoard::Appear::leave() {}
