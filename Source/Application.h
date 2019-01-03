#ifndef NBODY_CPP_APPLICATION_H
#define NBODY_CPP_APPLICATION_H

#include <iomanip>
#include <map>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/CircleShape.hpp>

#include "System.h"
#include "BodiesLoader.h"

class Application
{
public:
    Application(int argc, char** argv);

    int execute();

private:
    sf::RenderWindow m_window;
    sf::Vector2f m_centerOffset;
    bool m_showTrace;
    double m_scale;
    std::map<std::string, sf::CircleShape> m_shapes;

    /**
     * load bodies from persistence storage
     *
     * @return bodies to be simulated
     */
    std::vector<Body> loadBodies();
};


#endif //NBODY_CPP_APPLICATION_H
