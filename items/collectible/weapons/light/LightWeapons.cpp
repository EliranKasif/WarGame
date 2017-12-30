//
// Created by eliran on 18/12/17.
//

#include "LightWeapons.h"

LightWeapons::LightWeapons(int _power, int numofshots)
        : Weapons(_power,numofshots) {}

LightWeapons::LightWeapons()
       :Weapons(){}

void LightWeapons::toString(std::ostream &os) const{
    Weapons::toString(os);
}

LightWeapons::~LightWeapons() {

}
