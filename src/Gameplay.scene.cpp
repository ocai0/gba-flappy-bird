#include "Scenes/Gameplay.scene.hpp"
#include "bn_log.h"

using namespace Scenes;

//misc functions
int generateGapSize(bn::random* random) {
    return 46;
    return random->get_int(46, 54);
}
void Gameplay::reset() {
    this->score.setValue(0);
    this->flappyData.deltaY = 0;
    this->flappyData.deltaX = 0;
    this->flappy.setRotation(90);
    this->flappy.setX(0);
    this->flappy.setY(0);
    this->flappy.setAliveFlag(true);
    this->flappy.update();
    this->currentSubScene = GAME;
    this->score.setValue(0);

    for(int index=0; index < this->pipes.max_size(); index++) {
        PipeWall* pipe = (&this->pipes.at(index))->get();
        this->random.update();
        pipe->setX(PIPE_INITIAL_POSITION + (GAP_BTW_PIPES + PIPE_WALL_WIDTH) * index);
        pipe->setY(this->random.get_int(-SCREEN_HEIGHT_HALF + 16, SCREEN_HEIGHT_HALF - 56));
    }
    bn::core::update();
}

// main functions
Gameplay::Gameplay() : flappy(-4, 0, 8, 8, 2, 2), score(0, -64) {
    this->MAX_PIPE_SPEED = 2;
    this->flappyData.direction = -1;
    this->flappyData.gravity = .15;
    this->flappyData.MAX_GRAVITY = 2.6;
    this->flappyData.VERTICAL_JUMP_SPEED = -3;
    this->pipeSpeed = .7;

    // this->flappy.showDebugBox(true);

    for(int index=0; index < this->pipes.max_size(); index++) {
        this->pipes.push_back(PipeWall(
            PIPE_INITIAL_POSITION + (GAP_BTW_PIPES + PIPE_WALL_WIDTH) * index, 
            this->random.get_int(-SCREEN_HEIGHT_HALF + 16, SCREEN_HEIGHT_HALF - 56), 
            PIPE_WALL_WIDTH,
            generateGapSize(&this->random), COLOR_WHITE, 
            -3));
        // this->pipes.at(index)->showDebugBox(true);
    }
}
bn::optional<SceneType> Gameplay::update() {
    while(1) {
        switch(this->currentSubScene) {
            default:
            case GET_READY: {
                BN_LOG("Inside GET_READY");
                this->getReadyScene();
                break;
            }
            case GAME: {
                BN_LOG("Inside GAME");
                this->gameScene();
                break;
            }
            case PAUSED: {
                BN_LOG("Inside PAUSED");
                this->pausedScene();
                break;
            }
            case GAME_OVER: {
                BN_LOG("Inside GAME_OVER");
                this->gameOverScene();
                break;
            }
        }
        
    }
}

// sub scenes

void Gameplay::getReadyScene() {
    this->flappy.setRotation(90);
    this->flappyData.deltaY = 0;
    int sign_y = 1;
    bn::fixed FLAPPY_VELOCITY(.1);
    while(true) {

        if(bn::keypad::a_pressed()) {
            this->currentSubScene = GAME;
            return;
        }

        this->flappyData.deltaY += FLAPPY_VELOCITY * sign_y;

        if(this->flappy.getY() > 4) sign_y = -1;
        if(this->flappy.getY() < -4) sign_y = 1;

        this->flappy.setY(this->flappyData.deltaY);
        BN_LOG(this->flappyData.deltaY);
        this->flappy.update();
        bn::core::update();
    }
}
void Gameplay::gameScene() {
        if(!this->flappy.isAlive()) {
            this->currentSubScene = GAME_OVER;
            return;
        }

        // this->flappyData.deltaX = 1 * (bn::keypad::right_held() - bn::keypad::left_held());

        if(this->flappyData.deltaY < 0) this->flappy.setRotation(this->flappy.getRotation() - 1);
        else this->flappy.setRotation(this->flappy.getRotation() - 5);

        // Apply gravity 
        this->flappyData.deltaY += this->flappyData.gravity;
        if(this->flappyData.deltaY > this->flappyData.MAX_GRAVITY) this->flappyData.deltaY = this->flappyData.MAX_GRAVITY;

        if(bn::keypad::a_pressed()) {
            if(this->flappy.getRotation() + 120 > 135) this->flappy.setRotation(135);
            else this->flappy.setRotation(this->flappy.getRotation() + 120);

            this->flappyData.deltaY = this->flappyData.VERTICAL_JUMP_SPEED;
        }
        if(this->flappyData.deltaY < 0 && bn::keypad::a_released()) {
            this->flappyData.deltaY = max(this->flappyData.deltaY, 0);
        }

        bn::fixed flappy_nextX(this->flappy.getX() + this->flappyData.deltaX);
        bn::fixed flappy_nextY(this->flappy.getY() + this->flappyData.deltaY);

        for(int index = 0; index < this->pipes.size(); index++) {
            PipeWall* pipe = (&this->pipes.at(index))->get();
            bn::fixed pipe_deltaX(pipe->getX() - this->pipeSpeed);

            if( flappy_nextX + this->flappy.getWidth() > pipe_deltaX && flappy_nextX < pipe_deltaX + PIPE_WALL_WIDTH ) {
                //check if is colliding with any of the pipes
                if(flappy_nextY < pipe->getY() || flappy_nextY + this->flappy.getHeight() > pipe->getY() + pipe->getGapSize()) {
                    this->flappy.setAliveFlag(false);
                }

                //check if scored a point after pass the middle of them
                if(this->flappy.isAlive() && (pipe->getScoredFlag() == false) && (flappy_nextX + 2) > pipe_deltaX + PIPE_WALL_WIDTH_HALF) {
                    this->score.setValue(this->score.getValue() + 1);
                    pipe->setScoredFlag(true);
                }
            }
            
            pipe->setX(pipe_deltaX);

            if(pipe->getX() < -SCREEN_WIDTH_HALF - PIPE_WALL_WIDTH) {
                this->random.update();
                pipe->setX(pipe->getX() + (GAP_BTW_PIPES + PIPE_WALL_WIDTH) * (this->pipes.size()));
                pipe->setY(this->random.get_int(-SCREEN_HEIGHT_HALF + 16, SCREEN_HEIGHT_HALF - 56));
                pipe->setGapSize(generateGapSize(&this->random));
                pipe->setScoredFlag(false);
            }
        }

        if(bn::keypad::start_pressed()) {
            this->currentSubScene = PAUSED;
            return;
        }
        
        this->flappy.setX(this->flappy.getX() + this->flappyData.deltaX);
        this->flappy.setY(this->flappy.getY() + this->flappyData.deltaY);
        this->flappy.update();
        this->score.update();
        bn::core::update();
        return;
}
void Gameplay::pausedScene() {}
void Gameplay::gameOverScene() {
    int _internal_tick = 0;
    if(this->flappyData.deltaY > -1.6) this->flappyData.deltaY = -1.6;
    this->flappyData.rotationDelta = 145;

    while(_internal_tick++ < 300) {
        this->flappyData.deltaY += this->flappyData.gravity;
        if(this->flappy.getY() > 0) this->flappyData.rotationDelta -= 5;
        else this->flappyData.rotationDelta -= 4;
        
        this->flappy.setY(this->flappy.getY() + this->flappyData.deltaY);
        this->flappy.setRotation(this->flappyData.rotationDelta);
        this->flappy.update();
        bn::core::update();
    }
    this->reset();
    return;
}
