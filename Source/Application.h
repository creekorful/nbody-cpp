#ifndef NBODY_CPP_APPLICATION_H
#define NBODY_CPP_APPLICATION_H

#include <iomanip>

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

    /**
     * set scale in ratio of AU
     *
     * @param scale scale to be set
     */
    void setScale(double scale);

    std::vector<Body> getBodies();
};


#endif //NBODY_CPP_APPLICATION_H
