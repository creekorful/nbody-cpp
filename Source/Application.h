#ifndef NBODY_CPP_APPLICATION_H
#define NBODY_CPP_APPLICATION_H

#include <iomanip>
#include <map>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Text.hpp>

#include "System.h"
#include "Body/BodiesLoader.h"

class Application
{
public:
    Application(int argc, char** argv);

    ~Application();

    int execute();

private:
    sf::RenderWindow m_window;
    sf::Vector2f m_centerOffset;
    bool m_showTrace;
    double m_scale;
    std::map<std::string, sf::CircleShape> m_shapes;
    System* m_pSystem;

    // Ui
    sf::Font m_font;
    sf::Text m_timeDetails;

    /**
     * load bodies from persistence storage
     *
     * @return bodies to be simulated
     */
    std::vector<Body> loadBodies();

    /**
     * poll event from the window
     *
     * @param event event to be polled
     */
    void pollEvent(const sf::Event& event);
};


#endif //NBODY_CPP_APPLICATION_H
