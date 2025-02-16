#ifndef ABSTRACT_STATE_H_
#define ABSTRACT_STATE_H_
    #include "bn_string.h"
    #include "Commons/StateMachine.hpp"
    class StateMachine;

    class AbstractState {
        bn::string<32> name;
        public:
            StateMachine* parentStateMachine;
            StateMachine* subStateMachine;
            AbstractState* parentState;
            /** Amount of time this scene is alive (in ms) */
            unsigned int time;
            /** Run only once! Activated when Scene is loaded */
            virtual void load();
            /** Run every tick */
            virtual void update();
            virtual void render();
            void tick();
            bn::string<32> getName();
            void setName(bn::string<32>);
            /** Run only once! Activated when Scene is unloaded */
            virtual void leave();
            virtual ~AbstractState() = default;
    };
#endif