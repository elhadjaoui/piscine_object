#ifndef Vector2_HPP
#define Vector2_HPP

#include <iostream>
#include <vector>

class Graph;

class Vector2
{
private:
    int x;
    int y;

public:
    Vector2(int x, int y) : x(x), y(y) {}

    const int &getX() const
    {
        return x;
    }

    const int &getY() const
    {
        return y;
    }

    friend std::ostream &operator<<(std::ostream &p_os, const Vector2 &p_Vector2)
    {
        p_os << "[" << p_Vector2.x << ", " << p_Vector2.y << "]";
        return p_os;
    }
    friend class Graph;
};

#endif