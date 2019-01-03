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

    /**
     * Set time step to use for position calculation
     *
     * @param timestep new timestep (in seconds)
     */
    void setTimestep(int timestep);

    /**
     * @return current timestep
     */
    int timestep() const;

private:
    std::vector<Body> m_bodies;
    int m_iteration;
    int m_timestep;
};


#endif //NBODY_CPP_SYSTEM_H
