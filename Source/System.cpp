#include "System.h"

System::System(const std::vector<Body>& bodies)
{
    m_bodies = bodies;
}

int System::simulate()
{
    double timestep = 24*3600; // one day

    while (true)
    {
        std::map<Body, Vector> forces;

        for (const Body& body : m_bodies)
        {
            // output information about current body
            std::cout << body << std::endl;

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
            body.updateVelocity(force / body.mass() * timestep);

            // Update position based on velocity
            body.updatePosition(body.velocity() * timestep);
        }
    }

    return 0;
}
