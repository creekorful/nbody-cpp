#ifndef NBODY_CPP_BODY_H
#define NBODY_CPP_BODY_H

#include <iostream>
#include <cmath>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "Vector.h"
#include "constant.h"

class Body : sf::Drawable
{
public:
    /**
     * Instantiate body
     *
     * @param name the body name
     * @param mass the body mass (in kg)
     * @param position the body position (in km)
     * @param velocity the body velocity (in m/s)
     * @param color the body color
     */
    Body(const std::string& name, double mass, const Vector& position, const Vector& velocity, const sf::Color& color);

    /**
     * @return body name
     */
    std::string name() const;

    /**
     * @return body mass in kg
     */
    double mass() const;

    /**
     * @return vector that represent body position
     */
    Vector position() const;

    /**
     * @return vector that represent body velocity
     */
    Vector velocity() const;

    /**
     * Update velocity based on given vector
     *
     * @param offset the velocity vector to add
     */
    void updateVelocity(Vector offset);

    /**
     * Update position by given vector
     *
     * @param offset the position vector to add
     */
    void updatePosition(Vector offset);

    /**
     * Compute attraction force on body body to current body
     *
     * @param body the body to compute attraction against current body
     * @return computed attraction force as vector
     */
    Vector attraction(const Body& body) const;

    /**
     * Check if other is current body
     *
     * @param other the body to check
     * @return true if other == this false otherwise
     */
    bool operator==(const Body& other) const;

    /**
     * Check if current body is less than current body
     * needed because body are stored in std::map
     * check if performed on body name
     *
     * @param other the body to check against this
     * @return true if other is < than this
     */
    bool operator<(const Body& other) const;

private:
    std::string m_name;
    double m_mass;
    Vector m_position;
    Vector m_velocity;
    sf::CircleShape m_shape;

    /**
     * Render body in window
     *
     * @param target the render target
     * @param states associated render states
     */
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

/**
 * Overload operator << to allow display using ostream
 *
 * @param outs associated ostream
 * @param body the body to be displayed
 * @return body string representation
 */
std::ostream& operator<<(std::ostream& outs, const Body& body);


#endif //NBODY_CPP_BODY_H
