//
// Created by eliran on 18/12/17.
//

#include "Point2d.h"
Point2d::Point2d(double x, double y) : x(x), y(y) {}

std::ostream &operator<<(std::ostream &os, const Point2d &d) {
    os << "[x: " << d.x << " y: " << d.y<<"]";
    return os;
}

double Point2d::getX() const {
    return x;
}

double Point2d::getY() const {
    return y;
}

void Point2d::setX(double x) {
    Point2d::x = x;
}

void Point2d::setY(double y) {
    Point2d::y = y;
}

Point2d::Point2d():x(DEFAULT_LOCATION),y(DEFAULT_LOCATION) {}


