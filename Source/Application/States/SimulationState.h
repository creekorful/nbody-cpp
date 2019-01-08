#ifndef NBODY_CPP_SIMULATIONSTATE_H
#define NBODY_CPP_SIMULATIONSTATE_H

#include <map>

#include "../../Majoris/Source/Engine/State/GameState.h"
#include "../System.h"
#include "../GameObjects/BodyGameObject.h"

class SimulationState : public ma::GameState
{
public:
    std::string title() override;

    /**
     * Initialize the simulation using provided system
     *
     * @param pSystem pointer to the system to simulate
     */
    void initialize(System* pSystem);

    static SimulationState& instance()
    {
        static SimulationState instance;
        return instance;
    }

    void update(float dt) override;

protected:
public:
    void pollEvent(const sf::Event& event) override;

protected:
    void initialize() override;

private:
    System* m_pSystem{};

    sf::Vector2f m_centerOffset;

    double m_scale;

    std::map<std::string, BodyGameObject*> m_bodiesGameObjects;
};


#endif //NBODY_CPP_SIMULATIONSTATE_H
