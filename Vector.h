#pragma once

class Vector
{
public:
    Vector() = default;
    Vector(float c_x, float c_y);

    float getX() const;

    float getY() const;

    void setX(float value);

    void setY(float value);

    float getAngle() const;

    void setAngle(float angle);

    float getLength() const;

    void setLength(float length);
    // Cong vector vao vector hien tai
    void addTo(const Vector &v);
    // Tru vector khoi vector hien tai
    void subTo(const Vector &v);
    // nhan vector voi 1 so
    void Scale(float times);
    void Scale(float x, float y);
    // tich vo huong
    float Dot(const Vector &other) const;
    Vector operator+(const Vector &other) const;
    Vector operator-(const Vector &other) const;

private:
    float x = 0.f;
    float y = 0.f;
};