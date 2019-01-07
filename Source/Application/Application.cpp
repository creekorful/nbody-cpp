#include "Application.h"

Application::Application(int argc, char** argv) : m_gameEngine("N-Body C++ !")
{

}

int Application::execute()
{

    while (m_gameEngine.isRunning())
    {
        m_gameEngine.execute();
    }

    return 0;
}
