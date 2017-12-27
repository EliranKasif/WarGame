//
// Created by eliran on 19/12/17.
//

#include "RegularSoldier.h"

RegularSoldier::RegularSoldier(int _id,Weapons* _weapon)
        : Soldiers(_id,DEFAULT_LIFE_REGULAR,DEFAULT_SPEED_REGULAR),weapon(_weapon) {}


Weapons *RegularSoldier::getWeapon() const {
    return weapon;
}

void RegularSoldier::setWeapon(Weapons *weapon) {
    RegularSoldier::weapon = weapon;
}

void RegularSoldier::Action() {

}
