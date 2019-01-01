#include "Application.h"

Application::Application(int argc, char** argv)
{

}

int Application::execute()
{
    System system;
    return system.simulate();
}
