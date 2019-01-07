#include "Application/OldApplication.h"

int main(int argc, char** argv)
{
    auto application = new OldApplication(argc, argv);
    return application->execute();
}