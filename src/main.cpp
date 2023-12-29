#include "bn_core.h"
#include "bn_keypad.h"
#include "SceneEnum.hpp"
#include "Scenes/GearsLogo.scene.hpp"
#include "Scenes/MainMenu.scene.hpp"
#include "Scenes/Gameplay.scene.hpp"

int main() {
    bn::core::init();

    SceneEnum currentScene = GAMEPLAY;

    while(true) {

        switch(currentScene) {
            case GEARS_LOGO:
                {
                    GearsLogo logo(&currentScene);
                    logo.update();
                    break;
                }
            case MAIN_MENU:
                {
                    MainMenu mainMenu(&currentScene);
                    mainMenu.manage();
                    break;
                }
            case GAMEPLAY:
                {
                    Gameplay gameplay(&currentScene);
                    gameplay.manage();
                    break;
                }
        }
        
        bn::core::update();
    }
}
