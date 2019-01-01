#ifndef NBODY_CPP_BODY_H
#define NBODY_CPP_BODY_H

#include <iostream>
#include <cmath>

#include "Vector.h"
#include "constant.h"

class Body
{
public:
    Body(const std::string& name, double mass, const Vector& position, const Vector& velocity);

    std::string name() const;

    double mass() const;

    Vector position() const;

    Vector velocity() const;

    Vector attraction(const Body& body) const;

private:
    std::string m_name;
    double m_mass;
    Vector m_position;
    Vector m_velocity;
};


#endif //NBODY_CPP_BODY_H
