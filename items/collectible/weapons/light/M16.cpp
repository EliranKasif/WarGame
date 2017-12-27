//
// Created by eliran on 18/12/17.
//

#include "M16.h"

M16::M16():LightWeapons(DEFAULT_M16_POWER,DEFAULT_M16_CLIPS){}

void M16::toString(std::ostream &os) const{
    os << "M16- ";
    LightWeapons::toString(os);
}