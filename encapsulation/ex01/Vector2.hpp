#ifndef Vector2_HPP
#define Vector2_HPP

#include <iostream>
#include <vector>

class Graph;

class Vector2
{
private:
    float x;
    float y;

public:
    Vector2(int x, int y) : x(x), y(y) {}

    const float &getX() const
    {
        return x;
    }

    const float &getY() const
    {
        return y;
    }

    friend std::ostream &operator<<(std::ostream &p_os, const Vector2 &p_Vector2)
    {
        p_os << "(" << p_Vector2.x << ", " << p_Vector2.y << ")";
        return p_os;
    }
    friend class Graph;
};

#endif