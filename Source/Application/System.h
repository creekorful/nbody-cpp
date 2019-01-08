#ifndef NBODY_CPP_SYSTEM_H
#define NBODY_CPP_SYSTEM_H

#include <vector>
#include <map>
#include <iostream>

#include "Body/Body.h"

class System
{
public:

    System();

    explicit System(const std::vector<Body>& bodies);

    void setBodies(const std::vector<Body>& bodies);

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
    void setTimestep(long timestep);

    /**
     * @return current timestep (in seconds)
     */
    long timestep() const;

    /**
     * @return total elapsed simulation time (in seconds)
     */
    long elapsedTime() const;

private:
    std::vector<Body> m_bodies;
    long m_iteration;
    long m_timestep;
    long m_elapsedTime;
};


#endif //NBODY_CPP_SYSTEM_H
