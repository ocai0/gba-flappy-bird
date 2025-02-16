#ifndef ABSTRACT_STATE_H_
#define ABSTRACT_STATE_H_
    #include "Actors/Actor.hpp"
    // #include "StateMachine.hpp"

    class AbstractState {
        public:
            Actor* actor;
            // StateMachine* machine;
            AbstractState* parentState;
            /** Amount of time this scene is alive (in ms) */
            int time;
            /** Run only once! Activated when Scene is loaded */
            virtual void load();
            /** Run every tick */
            virtual void update();
            virtual void render();
            void tick();
            /** Run only once! Activated when Scene is unloaded */
            virtual void leave();
            virtual ~AbstractState() = default;
    };
#endif