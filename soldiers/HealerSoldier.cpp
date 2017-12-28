//
// Created by eliran on 19/12/17.
//

#include "HealerSoldier.h"

HealerSoldier::HealerSoldier(int _id)
        : Soldiers(_id,DEFAULT_LIFE_HEALER,DEFAULT_SPEED_HEALER) {}


void HealerSoldier::Action() {

}

void HealerSoldier:: toString(std::ostream &os) const {
    os << "Type: Healer Soldier, ";
    Soldiers::toString(os);
}

HealerSoldier::~HealerSoldier() {

}
