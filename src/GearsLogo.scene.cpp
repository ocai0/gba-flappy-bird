#include "Scenes/GearsLogo.scene.hpp"
#include "bn_log.h"

using namespace Scenes;

GearsLogo::GearsLogo() : flappy(0, 0, 10, 10, 0, 0), pipe(0, -20, 30, 1) {
    this->flappy.setRotation(90);
}

bn::optional<SceneType> GearsLogo::update() {
    while(!bn::keypad::start_held()) {
        int deltaX = 1 * (bn::keypad::right_pressed() - bn::keypad::left_pressed());
        this->flappy.setX(this->flappy.getX() + deltaX);
        int deltaY = 1 * (bn::keypad::down_pressed() - bn::keypad::up_pressed());
        this->flappy.setY(this->flappy.getY() + deltaY);

        this->flappy.update();
        
        this->flappy.setCollidingFlag(false);
        bool collides = this->flappy.getX() < this->pipe.getX() + 32 &&
                        this->flappy.getX() + this->flappy.getWidth() > this->pipe.getX() &&
                        this->flappy.getY() < this->flappy.getY() + this->pipe.getGapSize() &&
                        this->flappy.getY() + this->flappy.getHeight() > this->pipe.getY();
        if(collides) {
            this->flappy.setCollidingFlag(true);
        }
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

