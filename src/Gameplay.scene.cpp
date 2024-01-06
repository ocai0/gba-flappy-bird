#include "Scenes/Gameplay.scene.hpp"
#include "bn_log.h"
#define COLOR_WHITE 1
#define PIPE_INITIAL_POSITION 144
#define SCREEN_WIDTH_HALF 120
#define SCREEN_HEIGHT_HALF 80
#define GAP_BTW_PIPES 40

using namespace Scenes;

int max(int a, int b) {
    return (a > b) * a + (b > a) * b;
}

int min(int a, int b) {
    return (a < b) * a + (b < a) * b;
}


void Gameplay::setup() {
    this->score.setValue(0);
    this->flappyData.deltaY = 0;
    this->flappy.setRotation(90);
    this->flappy.setX(0);
    this->flappy.setY(0);
    this->pipeSpeed = 0;
    this->score.setValue(0);

    for(int index=0; index < this->pipes.max_size(); index++) {
        PipeWall* pipe = (&this->pipes.at(index))->get();
        this->random.update();
        pipe->setX(PIPE_INITIAL_POSITION + (GAP_BTW_PIPES + PipeWall::PIPE_WIDTH) * index);
        pipe->setY(this->random.get_int(-SCREEN_HEIGHT_HALF + 16, SCREEN_HEIGHT_HALF - 56));
    }
}

Gameplay::Gameplay() : flappy(0, 0), score(0, -64) {
    BN_LOG("Gameplay construct");
    for(int index=0; index < this->pipes.max_size(); index++) {
        this->pipes.push_back(PipeWall(PIPE_INITIAL_POSITION + (GAP_BTW_PIPES + PipeWall::PIPE_WIDTH) * index, this->random.get_int(-SCREEN_HEIGHT_HALF + 16, SCREEN_HEIGHT_HALF - 56), this->random.get_int(28, 38) + 20, COLOR_WHITE));
    }
}

void Gameplay::manage() {
    // this->load();
    // while(true) this->update();
    // this->leave();
}

void Gameplay::load() {
    BN_LOG("Gameplay load");
    this->score.setValue(0);
    this->MAX_PIPE_SPEED = 16;
    this->flappyData.gravity = 2;
    this->flappyData.direction = -1;
    this->flappyData.MAX_FALL_SPEED = 48;
    this->SUB_PIXEL_ZONE = 4; // the subpixel area is the 4 rightmost bits of the variable coords (X and Y)
    this->flappyData.VERTICAL_JUMP_SPEED = (6 * (2 * this->SUB_PIXEL_ZONE)) * -1;

    // this->debugPoint.top_left = bn::sprite_items::debug.create_sprite(0, 0);
    // this->debugPoint.top_right = bn::sprite_items::debug.create_sprite(0, 0);
    // this->debugPoint.bottom_left = bn::sprite_items::debug.create_sprite(0, 0);
    // this->debugPoint.bottom_right = bn::sprite_items::debug.create_sprite(0, 0);
}

bn::optional<SceneType> Gameplay::update() {
    while(1) {
        BN_LOG("Gameplay update");
        this->flappyData.deltaX = 1 * (bn::keypad::right_held() - bn::keypad::left_held());

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

        int flappy_nextX = this->flappy.getX() + (this->flappyData.deltaX);
        int flappy_nextY = this->flappy.getY() + (this->flappyData.deltaY >> this->SUB_PIXEL_ZONE);

        for(int index = 0; index < this->pipes.size(); index++) {
            PipeWall* pipe = (&this->pipes.at(index))->get();
            int pipe_deltaX = pipe->getX() - (this->pipeSpeed >> this->SUB_PIXEL_ZONE);

            if( flappy_nextX + 2 > pipe_deltaX && flappy_nextX - 1 < pipe_deltaX + PipeWall::PIPE_WIDTH ) {
                //check if is colliding with any of the pipes
                if(flappy_nextY - 4 < pipe->getY() || flappy_nextY > pipe->getY() - 6 + pipe->getGapSize()) {
                    this->flappy.setAliveFlag(false);
                }

                //check if scored a point after pass the middle of them
                if(this->flappy.isAlive() && (pipe->getScoredFlag() == false) && (flappy_nextX + 2) > pipe_deltaX + PipeWall::PIPE_WIDTH_HALF) {
                    this->score.setValue(this->score.getValue() + 1);
                    pipe->setScoredFlag(true);
                }
            }
            
            pipe->setX(pipe_deltaX);

            if(pipe->getX() < -SCREEN_WIDTH_HALF - PipeWall::PIPE_WIDTH) {
                this->random.update();
                pipe->setX(PIPE_INITIAL_POSITION);
                pipe->setScoredFlag(false);
            }
        }
        
        this->flappy.setX(this->flappy.getX() + this->flappyData.deltaX);
        this->flappy.setY(this->flappy.getY() + (this->flappyData.deltaY >> this->SUB_PIXEL_ZONE));
        this->flappy.update();
        this->score.setValue(this->score.getValue()); // keep the score above all other sprites
        bn::core::update();
    }
}

void Gameplay::leave() {
    this->showGameOverScreen();
}

void Gameplay::paused() {}

void Gameplay::updateDebugPoints(int x_start, int x_end, int y_start, int y_end) {
    this->debugPoint.top_left.get()->set_x(x_start - 4);
    this->debugPoint.top_left.get()->set_y(y_start + 4);

    this->debugPoint.top_right.get()->set_x(x_end + 4);
    this->debugPoint.top_right.get()->set_y(y_start + 4);

    this->debugPoint.bottom_left.get()->set_x(x_start - 4);
    this->debugPoint.bottom_left.get()->set_y(y_end - 4);

    this->debugPoint.bottom_right.get()->set_x(x_end + 4);
    this->debugPoint.bottom_right.get()->set_y(y_end - 4);
}

void Gameplay::showGameOverScreen() {
    int _internal_tick = 0;
    this->flappyData.deltaX = -8;
    this->flappyData.deltaY = this->flappyData.VERTICAL_JUMP_SPEED + 24;
    this->flappy.setRotation(this->flappy.getRotation() + 80);
    while(_internal_tick++ < 300) {

        BN_LOG(_internal_tick);
        
        this->flappyData.deltaY += this->flappyData.gravity;
        this->flappy.setY(this->flappy.getY() + (this->flappyData.deltaY >> this->SUB_PIXEL_ZONE));


        if(this->flappyData.deltaX < 0) {
            this->flappyData.deltaX += 1;
            this->flappy.setX(this->flappy.getX() + (this->flappyData.deltaX >> this->SUB_PIXEL_ZONE));
        }

        
        if(this->flappyData.deltaY < 0) this->flappy.setRotation(this->flappy.getRotation() - 1);
        else this->flappy.setRotation(this->flappy.getRotation() - 5);
        bn::core::update();
    }
    this->setup();
}