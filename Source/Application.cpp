#include "Application.h"

Application::Application(int argc, char** argv)
{
    // set digits precision to 2 decimals
    std::cout << std::scientific << std::setprecision(2);
}

int Application::execute()
{
    System system({Body("Sun", 1.98892 * std::pow(10, 30), {}, {}),
                   Body("Earth", 5.9742 * std::pow(10, 24), {-1 * AU, 0}, {0, 29.783 * 1000}),
                   Body("Venus", 4.8685 * std::pow(10, 24), {0.723 * AU, 0}, {0, -35.02 * 1000})});
    return system.simulate();
}
