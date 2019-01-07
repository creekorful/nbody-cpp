#ifndef NBODY_CPP_APPLICATION_H
#define NBODY_CPP_APPLICATION_H


#include "../Majoris/Source/Engine/GameEngine.h"

class Application
{
public:
    Application(int argc, char** argv);

    int execute();

private:
    ma::GameEngine m_gameEngine;
};


#endif //NBODY_CPP_APPLICATION_H
