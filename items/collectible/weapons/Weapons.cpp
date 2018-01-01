//
// Created by eliran on 18/12/17.
//

#include "Weapons.h"

Weapons::Weapons(const int power,const int _numofshot) : power(power),numofshots(_numofshot) {}

Weapons::Weapons() : power(ZERO),numofshots(ZERO){}

const int Weapons::getPower() const {
    return power;
}

void Weapons::toString(std::ostream &os) const{
    os<<"Power: "<<power<<", "<<"numofshots: "<<numofshots<<", ";
}

typeofObject Weapons:: whoami(){
    return typeofObject ::WEAPON;
}

Weapons::~Weapons() {

}

const int Weapons::getNumofshots() const {
    return numofshots;
}


