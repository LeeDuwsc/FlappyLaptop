#include <cmath>
#include "Vector.h"

using namespace std;

Vector::Vector(float c_x, float c_y)
{
    x = c_x;
    y = c_y;
}
float Vector::getX() const
{
    return x;
}
float Vector::getY() const
{
    return y;
}
void Vector::setX(float value)
{
    x = value;
}
void Vector::setY(float value)
{
    y = value;
}
float Vector::getAngle() const
{
    return atan2(y, x);
}
void Vector::setAngle(float angle)
{
    float length = getLength();
    x = cos(angle) * length;
    y = sin(angle) * length;
}
float Vector::getLength() const
{
    return sqrt(x * x + y * y);
}
void Vector::setLength(float length)
{
    float angle = getAngle();
    x = cos(angle) * length;
    y = sin(angle) * length;
}
void Vector::addTo(const Vector &v)
{
    x += v.x;
    y += v.y;
}
void Vector::subTo(const Vector &v)
{
    x -= v.x;
    y -= v.y;
}
void Vector::Scale(float times)
{
    x *= times;
    y *= times;
}
void Vector::Scale(float x, float y)
{
    x *= x;
    y *= y;
}
float Vector::Dot(const Vector &other) const
{
    return (x * other.x + y * other.y);
}
Vector Vector::operator+(const Vector &other) const
{
    return Vector(x + other.x, y + other.y);
}
Vector Vector::operator-(const Vector &other) const
{
    return Vector(x - other.x, y - other.y);
}
