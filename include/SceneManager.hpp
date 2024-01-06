#ifndef SCENE_MANAGER_H_
#define SCENE_MANAGER_H_

    #include "bn_core.h"
    #include "Base/Scene.hpp"
    #include "Base/SceneType.enum.hpp"

    #include "Scenes/Gameplay.scene.hpp"
    #include "Scenes/GearsLogo.scene.hpp"

    class SceneManager {
        bn::unique_ptr<Scene> currentScene;
        bn::optional<SceneType> nextScene;
        public:
            [[nodiscard]] SceneManager(SceneType);
            void loadScene();
            void update();
    };

#endif