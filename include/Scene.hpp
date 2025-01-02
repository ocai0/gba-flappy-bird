#ifndef SCENE_H_
#define SCENE_H_

    class Scene {
        public:
            virtual void load();
            virtual Scene* update();
            virtual void leave();
            virtual ~Scene() = default;
    };
#endif