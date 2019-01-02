#ifndef NBODY_CPP_SYSTEM_H
#define NBODY_CPP_SYSTEM_H

#include <vector>
#include <map>
#include <iostream>

#include "Body.h"

class System
{
public:
    explicit System(const std::vector<Body>& bodies);

    /**
     * perform one step / iteration
     * this will compute bodies position
     */
    void simulate();

    /**
     * @return bodies present in the system
     */
    std::vector<Body> bodies() const;

private:
    std::vector<Body> m_bodies;
    int m_iteration;
};


#endif //NBODY_CPP_SYSTEM_H
