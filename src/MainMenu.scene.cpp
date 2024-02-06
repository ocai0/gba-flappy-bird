#include "Scenes/MainMenu.scene.hpp"
#include "bn_log.h"

namespace Scenes {
    MainMenu::MainMenu(): flappy(-2, -2, 8, 8, 2, 2), ui(bn::regular_bg_items::bg_main_menu.create_bg(-120, 0)), background(), floor(0, 36) {
        this->flappy.setRotation(90);
        this->background.setBackground(DAY);
        if(this->random.get_int(1, 2) == 1) this->background.setBackground(NIGHT);
        this->ui.set_priority(0);
    }
    bn::optional<SceneType> MainMenu::update() {
        int _x = 0;
        int _y = 0;
        int flappySignMovement = 1;
        bn::fixed flappyVelocity(.125);
        bn::fixed _flappyNextY = 0;
        while(!bn::keypad::start_pressed()) {
            _flappyNextY = flappyVelocity * flappySignMovement;
            if(this->flappy.getY() + _flappyNextY > 4)  flappySignMovement = -1;
            if(this->flappy.getY() + _flappyNextY < -4)  flappySignMovement = 1;
            this->flappy.setY(this->flappy.getY() + _flappyNextY);

            _x = bn::keypad::right_held() - bn::keypad::left_held();
            _y = bn::keypad::down_held() - bn::keypad::up_held();
            this->ui.set_x(this->ui.x() + _x);
            this->ui.set_y(this->ui.y() + _y);
            this->floor.setX(this->floor.getX() - (bn::fixed) .7);

            BN_LOG("UI X: ", this->ui.x());
            BN_LOG("UI Y: ", this->ui.y());

            this->floor.update();
            this->flappy.update();
            bn::core::update();
        }
        return SceneType::GAMEPLAY;
    }
}