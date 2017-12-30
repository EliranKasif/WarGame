//
// Created by eliran on 18/12/17.
//

#include "HeavyWeapons.h"

HeavyWepons::HeavyWepons(int _power,int _numofshots)
        :Weapons(_power,_numofshots){}

HeavyWepons::HeavyWepons()
       :Weapons(){}

void HeavyWepons::toString(std::ostream &os) const{
    Weapons::toString(os);
}

HeavyWepons::~HeavyWepons() {

}
