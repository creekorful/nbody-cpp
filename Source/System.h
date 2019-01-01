#ifndef NBODY_CPP_SYSTEM_H
#define NBODY_CPP_SYSTEM_H

#include <vector>
#include <map>

#include "Body.h"

class System
{
public:
    explicit System(const std::vector<Body>& bodies);

    int simulate();

private:
    std::vector<Body> m_bodies;
};


#endif //NBODY_CPP_SYSTEM_H
