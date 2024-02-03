#include "Entities/ScoreBoard.hpp"

#define TRANSPARENT 0 
#define OPAQUE 1 
ScoreBoard::ScoreBoard() {
    this->resetAllFlags();
}

void ScoreBoard::showGameOverText(int _startX, int _startY, int _endX, int _endY) {
    this->ptrGameOver.reset(new ui::GameOver(_startX, _startY, _endX, _endY));
    this->_gameOverTitle = FLAG_STATUS::UP;
    this->ptrGameOver.get()->update();
}

void ScoreBoard::update() {
    if(this->_gameOverTitle == FLAG_STATUS::UP) this->ptrGameOver.get()->update();
}

void ScoreBoard::resetAllFlags() {
    this->_gameOverTitle = FLAG_STATUS::DOWN;
}

namespace ui {
    GameOver::GameOver(int _startX, int _startY, int _endX, int _endY): startX(_startX), startY(_startY), x(_startX), y(_startY), endX(_endX), endY(_endY), left(bn::sprite_items::ui_gameover.create_sprite(0, 0)), right(bn::sprite_items::ui_gameover.create_sprite(0, 0)), center(bn::sprite_items::ui_gameover.create_sprite(0, 0)) {
        this->setX(_startX);
        this->setY(_startY);
        this->center.set_tiles(bn::sprite_items::ui_gameover.tiles_item().create_tiles(1));
        this->right.set_tiles(bn::sprite_items::ui_gameover.tiles_item().create_tiles(2));

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
