#include "Scenes/Gameplay.scene.hpp"
#define COLOR_WHITE 1

int max(int a, int b) {
    return (a > b) * a + (b > a) * b;
}

int min(int a, int b) {
    return (a < b) * a + (b < a) * b;
}

Gameplay::Gameplay(SceneEnum* _mainController) : _currentScene(_mainController), flappy(0, 0) {
    this->status = ALIVE;
    this->pipes.push_back(PipeWall(0, 0, 1, COLOR_WHITE));
    this->pipes.push_back(PipeWall(32, 0, 2, COLOR_WHITE));
}

void Gameplay::manage() {
    this->load();
    while(this->status == ALIVE) this->update();
    this->leave();
}

void Gameplay::load() {
    this->flappyData.deltaY = 0;
    this->pipeSpeed = 0;
    this->MAX_PIPE_SPEED = 16;
    this->flappyData.gravity = 2;
    this->flappyData.direction = -1;
    this->flappyData.MAX_FALL_SPEED = 48;
    this->SUB_PIXEL_ZONE = 4; // the subpixel area is the 4 rightmost bits of the variable coords (X and Y)
    this->flappyData.VERTICAL_JUMP_SPEED = (6 * (2 * this->SUB_PIXEL_ZONE)) * -1;
    this->flappy.setRotation(90);
}

void Gameplay::update() {

    this->pipeSpeed += 16;
    if(this->pipeSpeed > this->MAX_PIPE_SPEED) this->pipeSpeed = 0;

    if(this->flappyData.deltaY < 0) this->flappy.setRotation(this->flappy.getRotation() - 1);
    else this->flappy.setRotation(this->flappy.getRotation() - 5);

    this->flappyData.deltaY += this->flappyData.gravity;
    if(this->flappyData.deltaY > this->flappyData.MAX_FALL_SPEED) this->flappyData.deltaY = this->flappyData.MAX_FALL_SPEED;

    if(bn::keypad::a_pressed()) {
        if(this->flappy.getRotation() + 120 > 180) this->flappy.setRotation(180);
        else this->flappy.setRotation(this->flappy.getRotation() + 120);

        this->flappyData.deltaY = this->flappyData.VERTICAL_JUMP_SPEED;
    }
    if(this->flappyData.deltaY < 0 && bn::keypad::a_released()) {
        this->flappyData.deltaY = max(this->flappyData.deltaY, 0);
    }

    for(int index = 0; index < this->pipes.size(); index++) {
        bn::optional<PipeWall>* pipe = &this->pipes.at(index);
        pipe->get()->setX(pipe->get()->getX() - (this->pipeSpeed >> this->SUB_PIXEL_ZONE));
    }


    this->flappy.setY(this->flappy.getY() + (this->flappyData.deltaY >> this->SUB_PIXEL_ZONE));
    this->flappy.update();
    bn::core::update();
}

void Gameplay::leave() {}

void Gameplay::paused() {}