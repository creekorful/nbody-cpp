#include "System.h"

System::System(const std::vector<Body>& bodies)
{
    m_bodies = bodies;
}

int System::simulate()
{
    int iteration = 0;
    double timestep = 24*3600; // one day
    std::map<Body, Vector> forces;

    while (true)
    {
        std::cout << "Iteration #" << iteration++ << std::endl;
        // Compute force for all bodies
        for (const Body& body : m_bodies)
        {
            // Output information about current body
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

        std::this_thread::sleep_for(std::chrono::milliseconds(150));

        std::cout << std::endl;
    }

    return 0;
}
