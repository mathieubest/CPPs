#include "../includes/Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _fixedPointValue(0) {}

Fixed::Fixed(const int fixedPointValue) {
    this->_fixedPointValue = fixedPointValue << this->_fractionalBits;
}

Fixed::Fixed(const float fixedPointValue) {
    this->_fixedPointValue = roundf(fixedPointValue * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &other) {
    *this = other;
}

Fixed::~Fixed() {}

Fixed &Fixed::operator=(const Fixed &other) {
    if (this != &other) {
        this->_fixedPointValue = other.getRawBits();
    }
    return *this;
}

bool Fixed::operator>(const Fixed &other) const {
    return this->_fixedPointValue > other._fixedPointValue;
}

bool Fixed::operator<(const Fixed &other) const {
    return this->_fixedPointValue < other._fixedPointValue;
}

bool Fixed::operator>=(const Fixed &other) const {
    return this->_fixedPointValue >= other._fixedPointValue;
}

bool Fixed::operator<=(const Fixed &other) const {
    return this->_fixedPointValue <= other._fixedPointValue;
}

bool Fixed::operator==(const Fixed &other) const {
    return this->_fixedPointValue == other._fixedPointValue;
}

bool Fixed::operator!=(const Fixed &other) const {
    return this->_fixedPointValue != other._fixedPointValue;
}

Fixed Fixed::operator+(const Fixed &other) const {
    return (this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
    return (this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
    return (this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
    return (this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator++() {
    ++this->_fixedPointValue;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    ++this->_fixedPointValue;
    return temp;
}

Fixed &Fixed::operator--() {
    --this->_fixedPointValue;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    --this->_fixedPointValue;
    return temp;
}

int Fixed::getRawBits(void) const {
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    this->_fixedPointValue = raw;
}

float Fixed::toFloat(void) const {
    return ((float)this->_fixedPointValue) / (float)(1 << this->_fractionalBits);
}

int Fixed::toInt(void) const {
    return (this->_fixedPointValue >> this->_fractionalBits);
}

Fixed &Fixed::min(Fixed &num1, Fixed &num2) {
    return (num1 < num2) ? num1 : num2;
}

const Fixed &Fixed::min(const Fixed &num1, const Fixed &num2) {
    return (num1 < num2) ? num1 : num2;
}

Fixed &Fixed::max(Fixed &num1, Fixed &num2) {
    return (num1 > num2) ? num1 : num2;
}

const Fixed &Fixed::max(const Fixed &num1, const Fixed &num2) {
    return (num1 > num2) ? num1 : num2;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}