#ifndef SCENE_MANAGER
#define SCENE_MANAGER
    #include "Scene.hpp"
    
    class SceneManager {
        volatile Scene* scene = nullptr;
        public:
            void load();
            void update();
            void next(volatile Scene*);
    };
#endif