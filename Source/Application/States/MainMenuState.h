#ifndef NBODY_CPP_MAINMENUSTATE_H
#define NBODY_CPP_MAINMENUSTATE_H


#include "../../Majoris/Source/Engine/State/GameState.h"

class MainMenuState : public ma::GameState
{
public:
    void update(float dt) override;

    void pollEvent(const sf::Event& event) override;

    std::string title() override;


    static MainMenuState& instance()
    {
        static MainMenuState instance;
        return instance;
    }

protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void initialize() override;
};


#endif //NBODY_CPP_MAINMENUSTATE_H
