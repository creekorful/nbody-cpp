#ifndef NBODY_CPP_LOADSYSTEMSTATE_H
#define NBODY_CPP_LOADSYSTEMSTATE_H

#include <iostream>
#include <vector>

#include "../../Majoris/Source/Engine/State/GameState.h"
#include "../../Majoris/Source/Engine/GameObject/Gui/Menu.h"

#include "../System.h"
#include "../Body/BodiesLoader.h"
#include "MainMenuState.h"

class LoadSystemState : public ma::GameState, public ma::Gui::IMenuCallback
{
public:
    std::string title() override;

    void onMenuItemSelected(const std::string& itemName) override;

    void onMenuItemHovered(const std::string& itemName) override;

    static LoadSystemState& instance()
    {
        static LoadSystemState instance;
        return instance;
    }

protected:
    void initialize() override;

private:
    ma::Gui::Menu m_saveMenu;

    /**
     * Load system from given file
     *
     * @param fileName the file name
     * @return loaded system
     */
    System loadSystem(const std::string& fileName);
};


#endif //NBODY_CPP_LOADSYSTEMSTATE_H
