//
// Created by eliran on 18/12/17.
//

#include "Missile.h"

Missile::Missile()
        :HeavyWepons(DEFAULT_MISSILE_POWER,DEFAULT_MISSILE_CLIPS){}

void Missile::toString(std::ostream &os) const{
    os << "Missile- ";
    HeavyWepons::toString(os);
}

Missile::~Missile() {

}
