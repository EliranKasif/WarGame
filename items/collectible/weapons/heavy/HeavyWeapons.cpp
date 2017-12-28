//
// Created by eliran on 18/12/17.
//

#include "HeavyWeapons.h"

HeavyWepons::HeavyWepons(int _power,int _numofshots)
        :Weapons(_power),numofshots(_numofshots){}

HeavyWepons::HeavyWepons()
       :Weapons(),numofshots(ZERO){}

void HeavyWepons::toString(std::ostream &os) const{
    Weapons::toString(os);
    os<<"numofshots: "<<numofshots<<", ";
}

const int HeavyWepons::getNumofshots() const {
    return numofshots;
}

HeavyWepons::~HeavyWepons() {

}
