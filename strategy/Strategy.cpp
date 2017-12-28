//
// Created by noysi on 23-Dec-17.
//

#include <iostream>
#include "Strategy.h"


Strategy::Strategy(){}

const std::vector<std::list<Point2d>> &Strategy::getDestination() const {
    return destination;
}

Strategy::~Strategy() {
    destination.clear();
}

std::ostream &operator<<(std::ostream &os, const Strategy &strategy) {
    strategy.toString(os);
    return os;
}

