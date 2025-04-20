#include "UI/ScoreBoard.hpp"
#include "bn_log.h"


UI::ScoreBoard::ScoreBoard() {
    this->stateMachine = new StateMachine();
    this->sprite = bn::regular_bg_items::bg_score_board.create_bg(this->x, this->y);
    this->sprite->set_priority(1);
    int scoreXPos = 44;
    this->currentScore = new Score(scoreXPos, -11);
    this->highScore = new Score(scoreXPos, 10);
}

void UI::ScoreBoard::load() {
    this->stateMachine->set(new _ScoreBoard::Appear(this));
    this->currentScore->useSmallFont()
        ->setPriority(1)
        ->hide()
        ->alignToTheRight();
    this->highScore->useSmallFont()
        ->setPriority(1)
        ->hide()
        ->alignToTheRight();
}

void UI::ScoreBoard::setX(bn::fixed _x) {
    this->x = _x;
    if(this->sprite.has_value()) this->sprite->set_x(this->x);
}

void UI::ScoreBoard::setY(bn::fixed _y) {
    this->y = _y;
    if(this->sprite.has_value()) this->sprite->set_y(this->y);
}

void UI::ScoreBoard::update() {
    this->stateMachine->update();
}

void UI::ScoreBoard::render() {
    this->stateMachine->render();
}

UI::ScoreBoard::~ScoreBoard() {
    delete this->currentScore;
    this->currentScore = nullptr;

    delete this->highScore;
    this->highScore = nullptr;

    

    this->sprite.reset();
}