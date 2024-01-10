#include "Scenes/GearsLogo.scene.hpp"
#include "bn_log.h"

using namespace Scenes;

GearsLogo::GearsLogo() : flappy(0, 0, 12, 10, 2, 2), pipe(0, 0, 8, 1) {
    this->flappy.setRotation(90);
}

bn::optional<SceneType> GearsLogo::update() {
    while(!bn::keypad::start_held()) {
        int deltaX = 1 * (bn::keypad::right_pressed() - bn::keypad::left_pressed());
        this->flappy.setX(this->flappy.getX() + deltaX);
        int deltaY = 1 * (bn::keypad::down_pressed() - bn::keypad::up_pressed());
        this->flappy.setY(this->flappy.getY() + deltaY);

        this->flappy.update();
        
        bool collides = this->flappy.getX() < this->pipe.getX() + PipeWall::PIPE_WIDTH &&
                        this->flappy.getX() + this->flappy.getWidth() > this->pipe.getX() &&
                        this->flappy.getY() < this->pipe.getY() + this->pipe.getGapSize() &&
                        this->flappy.getY() + this->flappy.getHeight() > this->pipe.getY();
        this->flappy.setCollidingFlag(collides);
        // if( this->flappy.getX() > this->pipe.getX() && this->flappy.getX() < this->pipe.getX() + PipeWall::PIPE_WIDTH ) {
        //         if(this->flappy.getY() < this->pipe.getY() || this->flappy.getY() > this->pipe.getY() + this->pipe.getGapSize()) {
        //             this->flappy.setCollidingFlag(true);
        //         }
        // }
        BN_LOG(this->flappy.isColliding());
        bn::core::update();
    }
    return SceneType::GAMEPLAY;
}

