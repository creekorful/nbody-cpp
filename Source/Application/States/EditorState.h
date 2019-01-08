#ifndef NBODY_CPP_EDITORSTATE_H
#define NBODY_CPP_EDITORSTATE_H

#include "../../Majoris/Source/Engine/State/GameState.h"

#include "MainMenuState.h"

class EditorState : public ma::GameState
{
public:
    std::string title() override;

    void pollEvent(const sf::Event& event) override;

protected:
    void initialize() override;
};


#endif //NBODY_CPP_EDITORSTATE_H
