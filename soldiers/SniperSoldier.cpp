//
// Created by eliran on 19/12/17.
//

#include "SniperSoldier.h"


SniperSoldier::SniperSoldier(int _id,Weapons* _weapon)
        : Soldiers(_id, DEFAULT_LIFE_SNIPER,DEFAULT_SPEED_SNIPER),weapon(_weapon){}

Weapons *SniperSoldier::getWeapon() const {
    return weapon;
}

void SniperSoldier::setWeapon(Weapons *weapon) {
    SniperSoldier::weapon = weapon;
}

void SniperSoldier::Action() {

}
