#ifndef NBODY_CPP_MAINMENUSTATE_H
#define NBODY_CPP_MAINMENUSTATE_H

#define PLAY_SIMULATION "Play Simulation"
#define SIMULATION_EDITOR "Simulation Editor"
#define QUIT "Quit"

#include <iostream>

#include <SFML/Graphics/Text.hpp>

#include "../../Majoris/Source/Engine/State/GameState.h"
#include "../../Majoris/Source/Engine/GameObject/Gui/Menu.h"

class MainMenuState : public ma::GameState, public ma::Gui::IMenuCallback
{
public:

    void pollEvent(const sf::Event& event) override;

    std::string title() override;

    void onMenuItemSelected(const std::string& itemName) override;

    void onMenuItemHovered(const std::string& itemName) override;


    static MainMenuState& instance()
    {
        static MainMenuState instance;
        return instance;
    }

protected:
    void initialize() override;

private:
    sf::Font m_arialFont;
    ma::Gui::Menu m_menu;
};


#endif //NBODY_CPP_MAINMENUSTATE_H
