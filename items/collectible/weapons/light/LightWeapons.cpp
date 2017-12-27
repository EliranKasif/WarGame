//
// Created by eliran on 18/12/17.
//

#include "LightWeapons.h"

LightWeapons::LightWeapons(int _power, int numofshots)
        : Weapons(_power), numofshots(numofshots) {}

//LightWeapons::LightWeapons()
//       :Weapons(),numofshots(ZERO){}

const int LightWeapons::getNumofshots() const {
    return numofshots;
}
void LightWeapons::toString(std::ostream &os) const{
    Weapons::toString(os);
    os<<"numofshots: "<<numofshots<<", ";
}