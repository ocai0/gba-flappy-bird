#ifndef MAIN_MENU_SCENE_H_
#define MAIN_MENU_SCENE_H_

    #include "SceneEnum.hpp"
    #include "SceneStatus.hpp"

    class MainMenu {
        SceneEnum* _currentScene;
        public:
            SceneStatus status;
            MainMenu(SceneEnum*);
            void manage();
    };

#endif