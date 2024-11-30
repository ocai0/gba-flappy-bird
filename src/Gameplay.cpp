#include "Scenes/Gameplay.hpp"
#include "bn_log.h"

//misc functions
int generateGapSize(bn::random* random) {
    return 46;
    return random->get_int(46, 54);
}
void Scenes::Gameplay::reset() {
    this->score.setValue(0);
    this->flappyData.deltaY = 0;
    this->flappyData.deltaX = 0;
    this->flappy.setRotation(90);
    this->flappy.setY(0);
    this->flappy.setAliveFlag(true);
    this->flappy.update();
    this->scoreBoard.reset();
    this->ptrPlayButton.reset();
    this->currentSubScene = GET_READY;
    for(int index=0; index < this->pipes.max_size(); index++) this->pipes.at(index)->setBlendingEnabled(true);

    this->random.update();
    if(this->random.get_fixed(1) > .6) this->background.setBackground(DAY);
    else this->background.setBackground(NIGHT);

    for(int index=0; index < this->pipes.max_size(); index++) {
        PipeWall* pipe = (&this->pipes.at(index))->get();
        this->random.update();
        pipe->setX(PIPE_INITIAL_POSITION + (GAP_BTW_PIPES + PIPE_WALL_WIDTH) * index);
        pipe->setY(this->random.get_int(-SCREEN_HEIGHT_HALF + 16, SCREEN_HEIGHT_HALF - 86));
        pipe->setScoredFlag(false);
    }
    this->score.update();
    bn::core::update();
}

// main functions
Scenes::Gameplay::Gameplay() : flappy(-64, 0, 8, 8, 2, 2), score(0, -64, FontType::BIG), background(), floor(0, 36), pauseButton(bn::sprite_items::ui_small_btn.create_sprite(-102, -64)) {
    this->score.setValue(0);
    this->MAX_PIPE_SPEED = 2;
    this->flappyData.direction = -1;
    this->flappyData.gravity = .15;
    this->flappyData.MAX_GRAVITY = 2.6;
    this->flappyData.VERTICAL_JUMP_SPEED = -3;
    this->pipeSpeed = .7;
    this->pauseButton.set_bg_priority(0);
    this->pauseButton.set_visible(false);
    this->pauseButton.set_tiles(bn::sprite_items::ui_small_btn.tiles_item().create_tiles(2));
    this->backgroundSpeed = .1;

    this->random.update();
    if(this->random.get_int(1, 2) == 1) this->background.setBackground(DAY);
    else this->background.setBackground(NIGHT);

    // this->flappy.showDebugBox(true);

    for(int index=0; index < this->pipes.max_size(); index++) {
        this->pipes.push_back(PipeWall(
            PIPE_INITIAL_POSITION + (GAP_BTW_PIPES + PIPE_WALL_WIDTH) * index, 
            this->random.get_int(-SCREEN_HEIGHT_HALF + 16, SCREEN_HEIGHT_HALF - 86), 
            PIPE_WALL_WIDTH,
            generateGapSize(&this->random), COLOR_WHITE, 
            -3));
        this->pipes.at(index)->setBlendingEnabled(true);
    }
}

Scene* Scenes::Gameplay::update() {
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

void Scenes::Gameplay::getReadyScene() {
    this->flappy.setRotation(90);
    this->pauseButton.set_visible(false);
    this->flappyData.deltaY = 0;
    int sign_y = 1;
    bn::fixed FLAPPY_VELOCITY(.1);
    this->getReady.reset(new GetReady());
    this->getReady.get()->fadeIn();
    while(true) {
        if(bn::keypad::a_pressed()) {
            this->getReady.get()->fadeOut();
            this->currentSubScene = GAME;
            return;
        }

        this->flappyData.deltaY += FLAPPY_VELOCITY * sign_y;

        if(this->flappy.getY() > 4) sign_y = -1;
        if(this->flappy.getY() < -4) sign_y = 1;

        this->background.setX(this->background.getX() - this->backgroundSpeed);
        this->flappy.setY(this->flappyData.deltaY);
        this->floor.setX(this->floor.getX() - this->pipeSpeed);

        this->background.update();
        this->flappy.update();
        this->floor.update();
        if(this->getReady == true) this->getReady.get()->update();
        bn::core::update();
    }
}
void Scenes::Gameplay::gameScene() {
        this->pauseButton.set_visible(true);
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
                pipe->setY(this->random.get_int(-SCREEN_HEIGHT_HALF + 16, SCREEN_HEIGHT_HALF - 86));
                pipe->setGapSize(generateGapSize(&this->random));
                pipe->setScoredFlag(false);
            }
        }

        if(bn::keypad::start_pressed()) {
            this->currentSubScene = PAUSED;
            return;
        }

        if(flappy_nextY > FLOOR_Y) {
            this->flappy.setAliveFlag(false);
        }

        this->background.setX(this->background.getX() - this->backgroundSpeed);
        
        this->flappy.setX(this->flappy.getX() + this->flappyData.deltaX);
        this->flappy.setY(this->flappy.getY() + this->flappyData.deltaY);
        this->floor.setX(this->floor.getX() - this->pipeSpeed);

        this->background.update();
        this->flappy.update();
        this->score.update();
        if(this->getReady == true) {
            this->getReady.get()->update();
            if(this->getReady.get()->isDone()) this->getReady.reset();
        }
        this->floor.update();
        bn::core::update();
}

void Scenes::Gameplay::pausedScene() {
    this->pauseButton.set_tiles(bn::sprite_items::ui_small_btn.tiles_item().create_tiles(3));
    bool canResumeGame = false;
    bool startWasPressed = false;
    int framesTillResolve = 0;
    while(!canResumeGame) {
        if(bn::keypad::start_pressed()) {
            startWasPressed = true;
        }
        if(startWasPressed) {
            framesTillResolve++;
        }
        bn::core::update();
    }
    this->currentSubScene = GAME;
    bn::core::update();
    return;
}

void Scenes::Gameplay::gameOverScene() {
    this->pauseButton.set_visible(false);
    int _clock = 0;
    if(this->flappyData.deltaY > -1.6) this->flappyData.deltaY = -1.6;
    this->flappyData.rotationDelta = 145;
    bool _userCanInteract = false;
    this->scoreBoard.reset(new ScoreBoard(this->score.getValue(), 1));

    this->flappy.setBlendingEnabled(true);
    this->floor.setBlendingEnabled(true);
    this->background.setBlendingEnabled(true);

    FadeScreenEffect fadeScreenEffect(bn::blending::fade_color_type::WHITE, .1);
    fadeScreenEffect.fadeInOut();
    fadeScreenEffect.start();
    this->score.setVisible(false);

    while(1) {

        // fadeInOut Effect
        if(fadeScreenEffect.isAlive()) fadeScreenEffect.update();
        // ScoreBoard
        else {
            this->flappy.setBlendingEnabled(false);
            this->floor.setBlendingEnabled(false);
            this->background.setBlendingEnabled(false);
            for(int index=0; index < this->pipes.max_size(); index++) this->pipes.at(index)->setBlendingEnabled(false);

            if(_clock == 70) this->scoreBoard.get()->showGameOverText(-48, -54, -48, -76);
            if(_clock == 100) this->scoreBoard.get()->showBoard(0, 104, 0, -6);
            if(this->scoreBoard.get()->scoreAnimationComplete()) {
                this->ptrPlayButton.reset(new ui::Button(0, 38, ui::ButtonType::PLAY));
                this->ptrPlayButton.get()->update();
                if(bn::keypad::start_pressed()) {
                    return this->reset();
                }
            }
            this->scoreBoard.get()->update();
        }

        // flappy Death Scene
        this->flappyData.deltaY += this->flappyData.gravity;
        if(this->flappy.getY() > 0) this->flappyData.rotationDelta -= 5;
        else this->flappyData.rotationDelta -= 4;
        if(this->flappyData.rotationDelta < 45) this->flappyData.rotationDelta = 45;
        if(this->flappy.getY() + this->flappyData.deltaY < FLOOR_Y + 12) {
            this->flappy.setY(this->flappy.getY() + this->flappyData.deltaY);
            this->flappy.update();
        }
        this->flappy.setRotation(this->flappyData.rotationDelta);

        _clock++;
        bn::core::update();
    }
}
