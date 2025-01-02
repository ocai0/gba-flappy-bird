#ifndef SCENE_MANAGER_H_
#define SCENE_MANAGER_H_
    #include "Scene.hpp"
    
    class SceneManager {
        volatile Scene* scene = nullptr;
        public:
            void load();
            void update();
            void next(volatile Scene*);
    };
#endif