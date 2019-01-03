#ifndef NBODY_CPP_BODY_H
#define NBODY_CPP_BODY_H

#include <iostream>
#include <cmath>

#include <SFML/Graphics/Color.hpp>

#include "Vector.h"
#include "constant.h"

class Body
{
public:
    /**
     * Instantiate body
     *
     * @param name the body name
     * @param mass the body mass (in kg)
     * @param radius the body radius (in km)
     * @param position the body position (in km)
     * @param velocity the body velocity (in m/s)
     * @param color the body color
     */
    Body(const std::string& name, double mass, double radius, const Vector& position, const Vector& velocity,
         const sf::Color& color);

    /**
     * @return body name
     */
    std::string name() const;

    /**
     * @return body mass in kg
     */
    double mass() const;

    /**
     * @return body radius in km
     */
    double radius() const;

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
     * @return body color
     */
    sf::Color color() const;

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
    double m_radius;
    Vector m_position;
    Vector m_velocity;
    sf::Color m_color;
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
