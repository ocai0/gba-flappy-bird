#include "bn_core.h"
#include "bn_log.h"
#include "SceneManager.hpp"

int main() {

    SceneManager sceneManager(SceneType::GAMEPLAY);

    while(true) {
        BN_LOG("while true do main");
        sceneManager.update();
        bn::core::update();
    }
}

// int main() {
//     bn::core::init();

//     SceneEnum currentScene = GAMEPLAY;

//     while(true) {

//         switch(currentScene) {
//             case GEARS_LOGO:
//                 {
//                     GearsLogo logo(&currentScene);
//                     logo.update();
//                     break;
//                 }
//             case MAIN_MENU:
//                 {
//                     MainMenu mainMenu(&currentScene);
//                     mainMenu.manage();
//                     break;
//                 }
//             case GAMEPLAY:
//                 {
//                     Gameplay gameplay(&currentScene);
//                     gameplay.manage();
//                     break;
//                 }
//         }
        
//         bn::core::update();
//     }
// }
