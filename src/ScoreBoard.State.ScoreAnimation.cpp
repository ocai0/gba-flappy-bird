#include "UI/ScoreBoard/ScoreBoard.State.ScoreAnimation.hpp"


_ScoreBoard::ScoreAnimation::ScoreAnimation(UI::ScoreBoard* _scoreboard) {
    this->setName("ScoreAnimation.Start");
    this->scoreboard = _scoreboard;
}

void _ScoreBoard::ScoreAnimation::load() {
    this->tempCurrentScore = this->scoreboard->currentScore->getValue();
    this->scoreboard->currentScore->setValue(0);
}

void _ScoreBoard::ScoreAnimation::update() {
    // if(this->time % 60 != 0) return;
    if(this->scoreboard->currentScore->getValue() != this->tempCurrentScore) this->scoreboard->currentScore->setValue(this->scoreboard->currentScore->getValue() + 1);
}

void _ScoreBoard::ScoreAnimation::render() {
    if(this->scoreboard == nullptr) return;
}

void _ScoreBoard::ScoreAnimation::leave() {}


void _ScoreBoard::ScoreAnimation::showNewHighScoreFlag() {

}