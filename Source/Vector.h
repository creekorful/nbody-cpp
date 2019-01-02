#ifndef NBODY_CPP_VECTOR_H
#define NBODY_CPP_VECTOR_H

#include <ostream>

class Vector
{
public:

    double x;
    double y;

    Vector();

    Vector(double x, double y);

    Vector operator-(const Vector& other);

    void operator+=(const Vector& other);

    Vector operator/(double scalar);

    Vector operator*(double scalar);
};

/**
 * Overload operator << to allow display using ostream
 *
 * @param outs associated ostream
 * @param vector the vector to be displayed
 * @return vector string representation
 */
std::ostream& operator<<(std::ostream& outs, const Vector& vector);


#endif //NBODY_CPP_VECTOR_H
