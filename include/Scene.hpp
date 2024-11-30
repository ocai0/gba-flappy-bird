#ifndef SCENE
#define SCENE

    class Scene {
        public:
            virtual void load();
            virtual Scene* update();
            virtual void leave();
            virtual ~Scene() = default;
    };
#endif