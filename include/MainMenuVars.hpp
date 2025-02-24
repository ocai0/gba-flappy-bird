#ifndef MAIN_MENU_VARS_H_
#define MAIN_MENU_VARS_H_
    #include "Enum/BirdType.Enum.hpp"
    #include "Enum/BackgroundType.Enum.hpp"
    
    typedef struct {
        Enum::BirdType birdType;
        Enum::BackgroundType backgroundType;
        Enum::PipeType pipeType;
    } MainMenuVars;
#endif