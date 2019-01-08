#ifndef NBODY_CPP_SIMULATIONSTATE_H
#define NBODY_CPP_SIMULATIONSTATE_H

#include <map>

#include "../../Majoris/Source/Engine/State/GameState.h"
#include "../../Majoris/Source/Engine/GameObject/Gui/Text.h"
#include "../System.h"
#include "../GameObjects/BodyGameObject.h"

class SimulationState : public ma::GameState
{
public:
    std::string title() override;

    /**
     * Initialize the simulation using provided system
     *
     * @param system system to simulate
     */
    void initialize(System system);

    void update(float dt) override;

    void pollEvent(const sf::Event& event) override;

protected:
    void initialize() override;

private:
    System m_system;

    sf::Vector2f m_centerOffset;

    double m_scale;

    std::map<std::string, BodyGameObject*> m_bodiesGameObjects;

    ma::Gui::Text m_timeDetails;

    /**
     * Compute elapsed time into human readable format
     *
     * @param time time in seconds
     * @return time in human readable format
     */
    std::string formatTime(double time) const;
};


#endif //NBODY_CPP_SIMULATIONSTATE_H
