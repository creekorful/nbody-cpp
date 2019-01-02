#include "Body.h"

Body::Body(const std::string& name, double mass, const Vector& position, const Vector& velocity, const sf::Color& color)
{
    m_name = name;
    m_mass = mass;
    m_position = position;
    m_velocity = velocity;
    m_color = color;
}

std::string Body::name() const
{
    return m_name;
}

double Body::mass() const
{
    return m_mass;
}

Vector Body::position() const
{
    return m_position;
}

Vector Body::velocity() const
{
    return m_velocity;
}

Vector Body::attraction(const Body& body) const
{
    // compute distance between two body
    Vector distance = m_position - body.position();
    double d = std::sqrt(std::pow(distance.x, 2) + std::pow(distance.y, 2));

    // compute force of attraction
    double force = G * m_mass * body.mass() / std::pow(d, 2);

    // compute force direction (vector)
    double theta = std::atan2(distance.y, distance.x);
    return Vector(std::cos(theta) * force, std::sin(theta) * force);
}

bool Body::operator==(const Body& other) const
{
    return m_name == other.name();
}

void Body::updateVelocity(Vector offset)
{
    m_velocity += offset;
}

void Body::updatePosition(Vector offset)
{
    m_position += offset;
}

bool Body::operator<(const Body& other) const
{
    return m_name < other.name();
}

sf::Color Body::color() const
{
    return m_color;
}

std::ostream& operator<<(std::ostream& outs, const Body& body)
{
    return outs << body.name() << " Pos=" << body.position()/AU << " Vel=" << body.velocity();
}
