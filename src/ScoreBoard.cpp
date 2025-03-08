#include "UI/ScoreBoard.hpp"
#include "bn_log.h"

UI::ScoreBoard::ScoreBoard() {
    this->stateMachine = new StateMachine();
    this->sprite = bn::regular_bg_items::bg_score_board.create_bg_optional(this->x, this->y);
    this->sprite->set_priority(1);
    int scoreXPos = 44;
    this->currentScore = new Score(scoreXPos, -11);
    this->highScore = new Score(scoreXPos, 10);
    this->currentScore->hide();
    this->highScore->hide();
}

void UI::ScoreBoard::load() {
    this->stateMachine->set(new _ScoreBoard::Appear(this));
    this->currentScore->useSmallFont()
        ->setPriority(1)
        ->alignToTheRight();
    this->highScore->useSmallFont()
        ->setPriority(1)
        ->alignToTheRight();
}

void UI::ScoreBoard::setX(bn::fixed _x) {
    this->x = _x;
    if(this->sprite.has_value()) this->sprite->set_x(this->x);
}

void UI::ScoreBoard::setY(bn::fixed _y) {
    this->y = _y;
    if(this->sprite.has_value()) {
        this->sprite->set_y(this->y);

    }
}

void UI::ScoreBoard::update() {
    this->stateMachine->update();
    if(this->currentScore != nullptr) this->currentScore->update();
    if(this->highScore != nullptr) this->highScore->update();
}

void UI::ScoreBoard::render() {
    this->stateMachine->render();
}