#include "BodyGameObject.h"

BodyGameObject::BodyGameObject(const std::string& name, float radius, const sf::Color& color)
{
    m_shape.setRadius(radius);
    m_shape.setFillColor(color);
    m_shape.setOrigin(m_shape.getRadius(), m_shape.getRadius()); // set center as planet center
}

void BodyGameObject::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= transform();
    target.draw(m_shape, states);
}
