#include "Vector.h"

Vector::Vector()
{
    x = 0;
    y = 0;
}

Vector::Vector(double x, double y)
{
    this->x = x;
    this->y = y;
}

Vector Vector::operator-(const Vector& other)
{
    return Vector(other.x - x, other.y - y);
}

void Vector::operator+=(const Vector& other)
{
    this->x += other.x;
    this->y += other.y;
}

Vector Vector::operator/(double scalar)
{
    return Vector(this->x / scalar, this->y + scalar);
}

Vector Vector::operator*(double scalar)
{
    return Vector(this->x * scalar, this->y * scalar);
}
