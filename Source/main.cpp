#include "Application/Application.h"

int main(int argc, char** argv)
{
    auto application = new Application(argc, argv);
    return application->execute();
}