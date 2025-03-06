#include "UI/ScoreBoard/ScoreBoard.State.Appear.hpp"
#include "bn_keypad.h"
#include "bn_log.h"

_ScoreBoard::Appear::Appear(UI::ScoreBoard* _scoreboard) {
    this->scoreboard = _scoreboard;
}

void _ScoreBoard::Appear::load() {
    this->scoreboard->deltaY = -6;
    this->y = this->initalPosY;
}

void _ScoreBoard::Appear::update() {
    this->y = this->y + this->scoreboard->deltaY;
    if(this->y < this->finalPosY) this->y = this->finalPosY;
}

void _ScoreBoard::Appear::render() {
    if(this->scoreboard == nullptr) return; 
    if(bn::keypad::a_held()) {
        BN_LOG("this->scoreboard: ", this->scoreboard);
    }
    this->scoreboard->setY(this->y);
}

void _ScoreBoard::Appear::leave() {}
