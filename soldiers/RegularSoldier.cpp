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
void RegularSoldier:: toString(std::ostream &os) const {
    os << "Type: Regular Soldier, ";
    Soldiers::toString(os);
    os<<"Weapon: " <<* weapon;
}

RegularSoldier::~RegularSoldier() {

    if(weapon != nullptr){
        delete(weapon);
    }
}
