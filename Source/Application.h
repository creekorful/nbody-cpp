#ifndef NBODY_CPP_APPLICATION_H
#define NBODY_CPP_APPLICATION_H

#include <iomanip>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/CircleShape.hpp>

#include "System.h"

class Application
{
public:
    Application(int argc, char** argv);

    int execute();

private:
    sf::RenderWindow m_window;
};


#endif //NBODY_CPP_APPLICATION_H
