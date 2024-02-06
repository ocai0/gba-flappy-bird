#include "Entities/ScoreBoard.hpp"
#include "bn_log.h"

#define TRANSPARENT 0 
#define OPAQUE 1 
ScoreBoard::ScoreBoard(int _score, int _maxScore) {
    this->resetAllFlags();
    this->score.max = _maxScore;
    this->score.current = _score;
}

void ScoreBoard::showGameOverText(int _startX, int _startY, int _endX, int _endY) {
    this->ptrGameOver.reset(new ui::GameOver(_startX, _startY, _endX, _endY));
    this->_gameOverTitle = FLAG_STATUS::UP;
    this->ptrGameOver.get()->update();
}

void ScoreBoard::showBoard(int _startX, int _startY, int _endX, int _endY) {
    this->ptrBoard.reset(new ui::Board(10, this->score));
    this->_scoreBoard = FLAG_STATUS::UP;
}

void ScoreBoard::update() {
    if(this->_gameOverTitle == FLAG_STATUS::UP) this->ptrGameOver.get()->update();
    if(this->_scoreBoard == FLAG_STATUS::UP) this->ptrBoard.get()->update();
}

void ScoreBoard::resetAllFlags() {
    this->_gameOverTitle = FLAG_STATUS::DOWN;
    this->_scoreBoard = FLAG_STATUS::DOWN;
}

namespace ui {
    GameOver::GameOver(int _startX, int _startY, int _endX, int _endY): startX(_startX), startY(_startY), x(_startX), y(_startY), endX(_endX), endY(_endY), left(bn::sprite_items::ui_gameover.create_sprite(0, 0)), right(bn::sprite_items::ui_gameover.create_sprite(0, 0)), center(bn::sprite_items::ui_gameover.create_sprite(0, 0)) {
        this->setX(_startX);
        this->setY(_startY);
        this->center.set_tiles(bn::sprite_items::ui_gameover.tiles_item().create_tiles(1));
        this->right.set_tiles(bn::sprite_items::ui_gameover.tiles_item().create_tiles(2));

        this->left.set_bg_priority(0);
        this->center.set_bg_priority(0);
        this->right.set_bg_priority(0);

        this->left.set_blending_enabled(true);
        this->center.set_blending_enabled(true);
        this->right.set_blending_enabled(true);
    }
    int GameOver::getX() {
        return this->x;
    }
    void GameOver::setX(int _x) {
        this->x = _x;
    }
    int GameOver::getY() {
        return this->y;
    }
    void GameOver::setY(int _y) {
        this->y = _y;
    }
    void GameOver::update() {
        if(this->fadeIntensity < 1) {
            this->fadeIntensity = clamp(this->fadeIntensity + .1, 0, 1);
            bn::blending::set_transparency_alpha(this->fadeIntensity);
        }
        if(this->x > this->endX) {
            this->x -= 2;
        }
        if(this->y > this->endY) {
            this->y -= 2;
        }
        this->left.set_x(this->x + this->WIDTH_HALF);
        this->left.set_y(this->y + this->HEIGHT_HALF);
        this->center.set_x(this->x + this->WIDTH_HALF + (this->WIDTH * 1));
        this->center.set_y(this->y + this->HEIGHT_HALF);
        this->right.set_x(this->x + this->WIDTH_HALF + (this->WIDTH * 2));
        this->right.set_y(this->y + this->HEIGHT_HALF);
    }
}

namespace ui {
    Board::Board(int _endY, ScoreData _scoreData): endY(_endY), x(0), y(140), scoreData(_scoreData), bg(bn::regular_bg_items::bg_score_board.create_bg(0, 140)), score(44, -11, FontType::SMALL), maxScore(44, 10, FontType::SMALL) {
        this->maxScore.setAlignment(bn::sprite_text_generator::alignment_type::RIGHT);
        this->maxScore.setPriority(0);
        this->maxScore.setValue(this->scoreData.max);
        this->maxScoreY = 140 + 10;

        this->score.setAlignment(bn::sprite_text_generator::alignment_type::RIGHT);
        this->score.setPriority(0);
        this->scoreY = 140 + -11;

        this->bg.set_priority(1);
    }

    void Board::update() {
        if(this->y > 0) {
            this->y -= 5;
            this->maxScoreY -= 5;
            this->scoreY -= 5;
        }
        else {
            if(this->score.getValue() < this->scoreData.current) {
                int _step = 1;
                if(this->scoreData.current > 50) _step = 5;
                if(this->scoreData.current > 150) _step = 10;
                if(this->scoreData.current > 200) _step = 30;
                if(this->scoreData.current > 1000) _step = 500;
                int _nextValue = this->score.getValue() + _step;
                if(_nextValue > this->scoreData.current) _nextValue = this->scoreData.current;
                this->score.setValue(_nextValue);
            }
            else {
                if(this->scoreData.current > this->scoreData.max) {
                    int _newFlagXPos = 28;
                    if(this->scoreData.current > 9) _newFlagXPos = 22;
                    if(this->scoreData.current > 99) _newFlagXPos = 16;
                    if(this->scoreData.current > 999) _newFlagXPos = 10;
                    this->maxScore.setValue(this->scoreData.current);
                    this->maxScore.update();
                    this->ptrNewFlag.reset(new ui::NewFlag(_newFlagXPos, 13));
                    this->ptrNewFlag.get()->setPriority(1);

                    if(this->scoreData.current >= 10) this->ptrMedal.reset(new ui::Medal(-33, 4));
                    if(this->scoreData.current >= 40) this->ptrMedal.get()->setIndex(3);
                    else if(this->scoreData.current >= 30) this->ptrMedal.get()->setIndex(2);
                    else if(this->scoreData.current >= 20) this->ptrMedal.get()->setIndex(1);
                }
            }
        }
        this->bg.set_x(this->x);
        this->bg.set_y(this->y);
        this->maxScore.setY(this->maxScoreY);
        this->maxScore.update();
        this->score.setY(this->scoreY);
        this->score.update();
    }
}

namespace ui {
    NewFlag::NewFlag(int _x, int _y): sprite(bn::sprite_items::ui_new.create_sprite(_x, _y)), x(_x), y(_y) {}
    void NewFlag::setX(int _x) {
        this->x = _x;
    }
    void NewFlag::setY(int _y) {
        this->y = _y;
    }
    int NewFlag::getX() {
        return this->x;
    }
    int NewFlag::getY() {
        return this->y;
    }
    void NewFlag::update() {
        this->sprite.set_x(this->x);
        this->sprite.set_y(this->y);
    }
    void NewFlag::setPriority(int _priority) {
        this->sprite.set_bg_priority(_priority);
    }
}

namespace ui {
    Medal::Medal(int _x, int _y): x(_x), y(_y), sprite(bn::sprite_items::ui_medal.create_sprite(_x, _y)) {
        this->sprite.set_bg_priority(0);
    }
    void Medal::setIndex(int _index) {
        this->sprite.set_tiles(bn::sprite_items::ui_medal.tiles_item().create_tiles(_index));
    }
}