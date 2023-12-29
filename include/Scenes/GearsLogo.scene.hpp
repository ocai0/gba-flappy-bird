#ifndef GEARS_LOGO_SCENE_H_
#define GEARS_LOGO_SCENE_H_

    #include "SceneEnum.hpp"
    #include "SceneStatus.hpp"
    
    class GearsLogo {
        SceneEnum* _currentScene;
        public:
            SceneStatus status;
            GearsLogo(SceneEnum*);
            void load();
            void update();
            void leave();
    };

#endif