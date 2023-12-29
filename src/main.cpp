#include "bn_core.h"
#include "bn_keypad.h"
#include "SceneEnum.hpp"
#include "Scenes/GearsLogo.scene.hpp"
#include "Scenes/Title.scene.hpp"

int main() {
    bn::core::init();

    SceneEnum currentScene = GEARS_LOGO;

    while(true) {

        switch(currentScene) {
            case GEARS_LOGO:
                GearsLogo logo(&currentScene);
                logo.update();
                break;
        }
        
        bn::core::update();
    }
}
