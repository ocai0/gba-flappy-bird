#include "Entities/ScoreBoard.hpp"

#define TRANSPARENT 0 
#define OPAQUE 1 

ScoreBoard::ScoreBoard(): x(0), y(20), bg(bn::regular_bg_items::bg_score_board.create_bg(x, y)) {
    this->bg.set_priority(0);
    this->bg.set_blending_enabled(true);
    this->ui_gameover.reset(new ui::GameOver(-48, -72));
}

void ScoreBoard::setX(int _x) {
    this->x = _x;
}

void ScoreBoard::setY(int _y) {
    this->y = _y;
}

int ScoreBoard::getX() {
    return this->x;
}

int ScoreBoard::getY() {
    return this->y;
}

void ScoreBoard::update() {
    if(this->y > 0) this->y -= 2;
    this->fadeIntensity = bn::min(this->fadeIntensity + .1, bn::fixed(OPAQUE));

    bn::blending::set_transparency_alpha(this->fadeIntensity);
    this->bg.set_x(this->x);
    this->bg.set_y(this->y);
    if(this->ui_gameover) this->ui_gameover.get()->update();
}

void ScoreBoard::showGameOver() {   
}

namespace ui {
    GameOver::GameOver(int _x, int _y): x(_x), y(_y), left(bn::sprite_items::ui_gameover.create_sprite(0, 0)), right(bn::sprite_items::ui_gameover.create_sprite(0, 0)), center(bn::sprite_items::ui_gameover.create_sprite(0, 0)) {
        this->setX(_x);
        this->setY(_y);
        this->center.set_tiles(bn::sprite_items::ui_gameover.tiles_item().create_tiles(1));
        this->right.set_tiles(bn::sprite_items::ui_gameover.tiles_item().create_tiles(2));
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
        this->left.set_x(this->x + this->WIDTH_HALF);
        this->left.set_y(this->y + this->HEIGHT_HALF);        
        this->center.set_x(this->x + this->WIDTH_HALF + (this->WIDTH * 1));
        this->center.set_y(this->y + this->HEIGHT_HALF);
        this->right.set_x(this->x + this->WIDTH_HALF + (this->WIDTH * 2));
        this->right.set_y(this->y + this->HEIGHT_HALF);
    }
}
