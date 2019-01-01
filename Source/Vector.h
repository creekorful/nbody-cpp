#ifndef NBODY_CPP_VECTOR_H
#define NBODY_CPP_VECTOR_H


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


#endif //NBODY_CPP_VECTOR_H
