#include "Scenes/MainMenu.hpp"
#include "bn_log.h"

void Scenes::MainMenu::load() {
    this->flappy = Flappy(-2, -8, 8, 8, 2, 2);
    this->ui = bn::regular_bg_items::bg_main_menu.create_bg(2, 0);
    this->background = Background();
    this->floor = Floor(0, 32);
    this->random = bn::random();

    this->flappy->setRotation(90);
    this->background->setBackground(DAY);
    BN_LOG(this->random->get_int(1, 2));
    if(this->random->get_int(1, 2) == 1) this->background->setBackground(NIGHT);
    this->ui->set_priority(0);
}

Scene* Scenes::MainMenu::update() {
    BN_LOG("MainMenu::update");
    int flappySignMovement = 1;
    bn::fixed flappyVelocity(.125);
    bn::fixed _flappyNextY = 0;
    while(!bn::keypad::start_pressed()) {
        _flappyNextY = flappyVelocity * flappySignMovement;
        if(this->flappy->getY() + _flappyNextY > 2)  flappySignMovement = -1;
        if(this->flappy->getY() + _flappyNextY < -6)  flappySignMovement = 1;
        this->flappy->setY(this->flappy->getY() + _flappyNextY);
        this->floor->setX(this->floor->getX() - (bn::fixed) .7);

        this->floor->update();
        this->flappy->update();
        bn::core::update();
    }
    return new MainMenu;
}

void Scenes::MainMenu::leave() {
    this->flappy.~optional();
    this->ui.~optional();
    this->background.~optional();
    this->floor.~optional();
    this->random.~optional();
}