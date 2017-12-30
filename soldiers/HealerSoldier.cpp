//
// Created by eliran on 19/12/17.
//

#include "HealerSoldier.h"

HealerSoldier::HealerSoldier(int _id)
        : Soldiers(_id,DEFAULT_LIFE_HEALER,DEFAULT_SPEED_HEALER) {}


void HealerSoldier::Action(Point2d newlocation){}


void HealerSoldier:: toString(std::ostream &os) const {
    os << "Type: Healer Soldier, ";
    Soldiers::toString(os);
}

void HealerSoldier::Attack(std::list<Soldiers*>& list ){
    for(auto& soldierto:list){
        if(soldierto->getId() == getId())//check if there is someone to heal first !
        {

        }

    }

}
HealerSoldier::~HealerSoldier() {

}
