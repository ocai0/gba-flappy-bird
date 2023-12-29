#include "Scenes/Title.scene.hpp"
#include "bn_log.h"

Title::Title() : flappy(0, 0) {}

void Title::onUpdate() {
    BN_LOG("Title update");
    this->flappy.setY(1);
    this->flappy.update();
}