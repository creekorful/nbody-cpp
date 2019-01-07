#include "Application.h"

Application::Application(int argc, char** argv) : m_gameEngine("N-Body C++ !")
{
}

int Application::execute()
{
    m_gameEngine.setCurrentState(&MainMenuState::instance());
    while (m_gameEngine.isRunning())
    {
        m_gameEngine.execute();
    }

    return 0;
}
