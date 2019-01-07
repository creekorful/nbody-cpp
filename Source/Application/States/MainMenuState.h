#ifndef NBODY_CPP_MAINMENUSTATE_H
#define NBODY_CPP_MAINMENUSTATE_H

#include <iostream>

#include <SFML/Graphics/Text.hpp>

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

private:
    sf::Font m_arialFont;
    sf::Text m_playText;
    sf::Text m_editorText;
    sf::Text m_quitText;
};


#endif //NBODY_CPP_MAINMENUSTATE_H
