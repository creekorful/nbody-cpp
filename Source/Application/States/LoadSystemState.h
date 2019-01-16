#ifndef NBODY_CPP_LOADSYSTEMSTATE_H
#define NBODY_CPP_LOADSYSTEMSTATE_H

#include <iostream>
#include <vector>
#include <map>

#include "../../Majoris/Source/Engine/State/GameState.h"
#include "../../Majoris/Source/Engine/GameObject/Gui/Menu.h"
#include "../../Majoris/Source/Engine/Filesystem/Directory.h"

#include "../System.h"
#include "../Body/BodiesLoader.h"
#include "MainMenuState.h"

#define BACK "Back"

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

    std::map<std::string, ma::Filesystem::File> m_systemFiles;

    /**
     * Load system from given file
     *
     * @param file the system file
     * @return loaded system
     */
    System loadSystem(ma::Filesystem::File file);
};


#endif //NBODY_CPP_LOADSYSTEMSTATE_H
