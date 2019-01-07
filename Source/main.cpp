#include "Application/OldApplication.h"
#include "Application/Application.h"

int main(int argc, char** argv)
{
    int ret = -1;
    // if --engine flag is passed switch to new game engine version
    if (argc > 1 && strcmp(argv[1], "--engine") == 0)
    {
        auto application = new Application(argc, argv);
        ret = application->execute();
    }
    // otherwise fallback to old one
    else
    {
        auto application = new OldApplication(argc, argv);
        ret = application->execute();
    }

    return ret;
}