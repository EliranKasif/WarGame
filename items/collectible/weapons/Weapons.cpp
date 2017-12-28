//
// Created by eliran on 18/12/17.
//

#include "Weapons.h"

Weapons::Weapons(const int power) : power(power) {}

Weapons::Weapons() : power(ZERO){}

const int Weapons::getPower() const {
    return power;
}

void Weapons::toString(std::ostream &os) const{
    os<<"Power: "<<power<<", ";
}

Weapons::~Weapons() {

}


