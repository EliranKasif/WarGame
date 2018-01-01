//
// Created by eliran on 18/12/17.
//

#include "NotCollectibleItems.h"

NotCollectibleItems::NotCollectibleItems(double width, double height)
        : width(width), height(height) {}

NotCollectibleItems::NotCollectibleItems()
        : width(ZERO), height(ZERO) {}

const double NotCollectibleItems::getWidth() const {
    return width;
}

const double NotCollectibleItems::getHeight() const {
    return height;
}

void NotCollectibleItems::toString(std::ostream &os) const{
    os << "width: " << width << ", height: " << height<<", ";
}


typeofObject NotCollectibleItems:: whoami(){
    return typeofObject::NOTCOLLECTIBLE;
}

NotCollectibleItems::~NotCollectibleItems() {

}
