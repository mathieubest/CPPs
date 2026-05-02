#pragma once

#include "Fixed.hpp"
#include <iostream>

class Point {
    private:
        const Fixed _x;
        const Fixed _y;

    public:
        Point();
        Point(const float num1, const float num2);
        Point(const Point &other);
        Point &operator=(const Point &other);
        ~Point();
        Fixed getX() const;
        Fixed getY() const;
        static Fixed sign(Point const p1, Point const p2, Point const p3);
};

bool bsp(Point const a, Point const b, Point const c, Point const point);