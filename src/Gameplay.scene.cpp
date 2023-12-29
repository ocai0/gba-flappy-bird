#include "Scenes/Gameplay.scene.hpp"
#include "bn_log.h"

int max(int a, int b) {
    return (a > b) * a + (b > a) * b;
}

Gameplay::Gameplay(SceneEnum* _mainController) : _currentScene(_mainController), flappy(0, 0) {
    this->status = ALIVE;
}

void Gameplay::manage() {
    this->load();
    while(this->status == ALIVE) this->update();
    this->leave();
}

void Gameplay::load() {
    this->flappyData.deltaY = 0;
    this->flappyData.gravity = 2;
    this->flappyData.direction = -1;
    this->flappyData.MAX_FALL_SPEED = 48;
    this->flappyData.SUB_PIXEL_ZONE = 4; // the subpixel area is the 4 rightmost bits of the variable coords (X and Y)
    this->flappyData.VERTICAL_JUMP_SPEED = (6 * (2 * this->flappyData.SUB_PIXEL_ZONE)) * -1;
}

void Gameplay::update() {

    this->flappyData.deltaY += this->flappyData.gravity;

    if(this->flappyData.deltaY > this->flappyData.MAX_FALL_SPEED) {
        this->flappyData.deltaY = this->flappyData.MAX_FALL_SPEED;
    }

    if(bn::keypad::a_pressed()) this->flappyData.deltaY = this->flappyData.VERTICAL_JUMP_SPEED;
    if(this->flappyData.deltaY < 0 && bn::keypad::a_released()) {
        this->flappyData.deltaY = max(this->flappyData.deltaY, 0);
    }

    this->flappy.setY(this->flappy.getY() + (this->flappyData.deltaY >> this->flappyData.SUB_PIXEL_ZONE));
    this->flappy.update();
    bn::core::update();
}

void Gameplay::leave() {}

void Gameplay::paused() {}