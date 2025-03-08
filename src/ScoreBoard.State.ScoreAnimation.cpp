#include "UI/ScoreBoard/ScoreBoard.State.ScoreAnimation.hpp"
#include "bn_log.h"
#include "bn_keypad.h"


void position(bn::sprite_ptr item) {
    if(bn::keypad::left_pressed()) {
        item.set_x(item.x() - 1);
        BN_LOG("x: ", item.x());
    }
    if(bn::keypad::right_pressed()) {
        item.set_x(item.x() + 1);
        BN_LOG("x: ", item.x());
    }
    if(bn::keypad::up_pressed()) {
        item.set_y(item.y() - 1);
        BN_LOG("y: ", item.y());
    }
    if(bn::keypad::down_pressed()) {
        item.set_y(item.y() + 1);
        BN_LOG("y: ", item.y());
    }
}

_ScoreBoard::ScoreAnimation::ScoreAnimation(UI::ScoreBoard* _scoreboard) {
    this->setName("ScoreAnimation.Start");
    this->scoreboard = _scoreboard;
    this->sram = &SramData::getInstance();
}

void _ScoreBoard::ScoreAnimation::load() {
    this->tempCurrentScore = this->scoreboard->currentScore->getValue();
    this->scoreboard->currentScore->setValue(0);
    this->scoreboard->currentScore->show();
    int highScore = this->sram->getHighScore();
    this->scoreboard->highScore->setValue(highScore);
    this->scoreboard->highScore->show();
}

void _ScoreBoard::ScoreAnimation::update() {
    if(this->scoreboard->currentScore->getValue() != this->tempCurrentScore) this->scoreboard->currentScore->setValue(this->scoreboard->currentScore->getValue() + 1);
    else {
        if(this->highScoreWasChecked == false) {this->verifyAndSaveHighScore();}
        else this->setName("ScoreAnimation.End");
    }
}

void _ScoreBoard::ScoreAnimation::render() {
    if(this->scoreboard == nullptr) return;
    if(this->newFlag != nullptr) position(this->newFlag->sprite.value());
}

void _ScoreBoard::ScoreAnimation::leave() {}

void _ScoreBoard::ScoreAnimation::verifyAndSaveHighScore() {
    this->highScoreWasChecked = true;
    int _currentScore = this->scoreboard->currentScore->getValue();
    int _highScore = this->scoreboard->highScore->getValue();
    if(_currentScore > _highScore) {
        // change highScore value
        this->scoreboard->highScore->setValue(_currentScore);
        // show hew flag
        int spacingBtwThem = 8;
        int qtdOfCharacters = this->scoreboard->highScore->getSpriteCount();
        this->newFlag = new UI::NewFlag(37 - (qtdOfCharacters + spacingBtwThem), 15);
        this->newFlag->setPriority(1);
        // save in sram
        this->sram->setHighScore(_currentScore);
        this->sram->write();
    }
    // this->renderMedal();
}

void _ScoreBoard::ScoreAnimation::renderMedal() {

}
