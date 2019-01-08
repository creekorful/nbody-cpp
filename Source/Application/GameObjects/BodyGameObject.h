#ifndef NBODY_CPP_BODYGAMEOBJECT_H
#define NBODY_CPP_BODYGAMEOBJECT_H

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "../../Majoris/Source/Engine/GameObject/GameObject.h"

class BodyGameObject : public ma::GameObject
{
public:
    BodyGameObject(const std::string& name, float radius, const sf::Color& color);

protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    sf::CircleShape m_shape;
};


#endif //NBODY_CPP_BODYGAMEOBJECT_H
