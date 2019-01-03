#include "BodiesLoader.h"

BodiesLoader::BodiesLoader(const std::string& filePath) : m_file(filePath)
{
}

bool BodiesLoader::isOpen()
{
    return m_file.is_open();
}

std::vector<Body> BodiesLoader::loadBodies()
{
    std::vector<Body> bodies;
    std::string line;
    while (std::getline(m_file, line))
    {
        std::stringstream ssline(line);
        std::vector<std::string> parts;
        std::string part;

        while (std::getline(ssline, part, ';'))
        {
            parts.push_back(part);
        }

        Body body = bodies.emplace_back(parts[0], std::stod(parts[1]), std::stod(parts[2]),
                                        Vector(std::stod(parts[3]) * AU, std::stod(parts[4]) * AU),
                                        Vector(std::stod(parts[5]), std::stod(parts[6])),
                                        sf::Color(static_cast<sf::Uint32>(std::stoul(parts[7]))));

        std::cout << "Loaded body: " << body.name() << ". Position: " << body.position() << " AU. Orbital velocity: "
                  << body.velocity() << "km/s. Mass: " << body.mass() << "kg. Radius: " << body.radius() << "km."
                  << std::endl;
    }

    return bodies;
}