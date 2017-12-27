//
// Created by noysi on 23-Dec-17.
//

#include <iostream>
#include "Strategy.h"

Strategy::Strategy(const int numOfSoldiers, const double height, const double width)
        : numOfSoldiers(numOfSoldiers), height(height), width(width){}

Strategy::Strategy():
        numOfSoldiers(ZERO),height(ZERO),width(ZERO){}


int Strategy::getNumOfSoldiers() const {
    return numOfSoldiers;
}

const std::vector<std::list<Point2d>> &Strategy::getDestination() const {
    return destination;
}

const double Strategy::getHeight() const {
    return height;
}

const double Strategy::getWidth() const {
    return width;
}

Strategy::~Strategy() {

}

