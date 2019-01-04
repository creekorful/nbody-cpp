#include "System.h"

#include <thread>

System::System(const std::vector<Body>& bodies)
{
    m_bodies = bodies;
    m_iteration = 0;
    m_timestep = 24*3600;
}

void System::simulate()
{
    std::map<Body, Vector> forces;

    m_iteration++;

#ifdef DEBUG_ENABLED
    std::cout << "Iteration #" << m_iteration << std::endl;
#endif

    // Compute force for all bodies
    for (const Body& body : m_bodies)
    {
        // Output information about current body
#ifdef DEBUG_ENABLED
        std::cout << body << std::endl;
#endif

        Vector totalForce;
        for (const Body& other : m_bodies)
        {
            if (body == other)
                continue;

            totalForce += body.attraction(other);
        }

        // record total force exerted on body
        forces[body] = totalForce;
    }

    for (Body& body : m_bodies)
    {
        // Update velocities based upon on the force
        Vector force = forces[body];
        body.updateVelocity(force / body.mass() * m_timestep);

        // Update position based on velocity
        body.updatePosition(body.velocity() * m_timestep);
    }

#ifdef DEBUG_ENABLED
    std::cout << std::endl;
#endif
}

std::vector<Body> System::bodies() const
{
    return m_bodies;
}

void System::setTimestep(long timestep)
{
    m_timestep = timestep;
}

long System::timestep() const
{
    return m_timestep;
}

long System::iteration() const
{
    return m_iteration;
}
