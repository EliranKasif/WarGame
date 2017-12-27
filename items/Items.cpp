//
// Created by eliran on 18/12/17.
//

#include "Items.h"

Items::Items() {}

const Point2d &Items::getLocation() const {
    return itemLocation;
}

void Items::setLocation(const Point2d &location) {
    Items::itemLocation = location;
}

std::ostream &operator<<(std::ostream &os, const Items &item) {
    item.toString(os);
    os<<"item location: "<<item.itemLocation<<" ";
    return os;
}