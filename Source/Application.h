#ifndef NBODY_CPP_APPLICATION_H
#define NBODY_CPP_APPLICATION_H

#include <iomanip>

#include <SFML/Graphics/RenderWindow.hpp>

#include "System.h"

class Application
{
public:
    Application(int argc, char** argv);

    int execute();
};


#endif //NBODY_CPP_APPLICATION_H
