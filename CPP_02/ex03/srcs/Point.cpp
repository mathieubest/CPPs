#include "../includes/Point.hpp"

// Default constructor
Point::Point() : _x(0), _y(0) {}

// Parameterized constructor
Point::Point(const float num1, const float num2) : _x(num1), _y(num2) {}

// Copy constructor
Point::Point(const Point &other) : _x(other._x), _y(other._y) {}

// Assignment operator
Point &Point::operator=(const Point &other) {
    if (this != &other) {
        const_cast<Fixed&>(this->_x) = other._x;
        const_cast<Fixed&>(this->_y) = other._y;
    }
    return *this;
}

// Destructor
Point::~Point() {}

// Getters
Fixed Point::getX() const {
    return this->_x;
}

Fixed Point::getY() const {
    return this->_y;
}

// Static method to calculate the sign
Fixed Point::sign(Point const p1, Point const p2, Point const p3) {
    return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

// Function to check if a point is inside a triangle
bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed d1, d2, d3;
    bool has_neg, has_pos;

    d1 = Point::sign(point, a, b);
    d2 = Point::sign(point, b, c);
    d3 = Point::sign(point, c, a);

    has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(has_neg && has_pos);
}