//
// Created by eliran on 18/12/17.
//

#include "Uzi.h"

Uzi::Uzi()
        :LightWeapons(DEFAULT_UZI_POWER,DEFAULT_UZI_CLIPS){}

void Uzi::toString(std::ostream &os) const{
    os << "Uzi- ";
    LightWeapons::toString(os);
}

Uzi::~Uzi() {

}
