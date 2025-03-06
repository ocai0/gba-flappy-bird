#include "UI/ScoreBoard.hpp"
#include "bn_log.h"


UI::ScoreBoard::ScoreBoard() {
    this->state = new StateMachine();
    this->sprite = bn::regular_bg_items::bg_score_board.create_bg_optional(this->x, this->y);
    this->sprite->set_priority(1);
    // this->currentScore = new Score(10, 10);
    // this->currentScore->useSmallFont();
    // this->currentScore->setValue(12);
}

void UI::ScoreBoard::load() {
    _ScoreBoard::Appear* _state = new _ScoreBoard::Appear(this);
    this->state->set((AbstractState*) _state);
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
    this->state->update();
}

void UI::ScoreBoard::render() {
    this->state->render();
}

void UI::ScoreBoard::showNewHighScoreFlag() {

}