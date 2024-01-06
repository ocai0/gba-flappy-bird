#ifndef SCENE_H_
#define SCENE_H_

    #include "Base/SceneType.enum.hpp"
    #include "bn_optional.h"
    #include "bn_unique_ptr.h"

    class Scene {
        SceneType currentScene;
        public:
            virtual ~Scene() = default;
            [[nodiscard]] virtual bn::optional<SceneType> update() = 0;

        protected:
            Scene() = default;
    };

#endif