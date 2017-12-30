//
// Created by eliran on 19/12/17.
//

#include <cmath>
#include "SniperSoldier.h"


SniperSoldier::SniperSoldier(int _id,Weapons* _weapon)
        : Soldiers(_id, DEFAULT_LIFE_SNIPER,DEFAULT_SPEED_SNIPER),weapon(_weapon){}

Weapons *SniperSoldier::getWeapon() const {
    return weapon;
}

void SniperSoldier::setWeapon(Weapons *weapon) {
    SniperSoldier::weapon = weapon;
}

void SniperSoldier:: toString(std::ostream &os) const {
    os << "Type: Sniper Soldier, ";
    Soldiers::toString(os);
    os<<"Weapon: " <<* weapon;
}


void SniperSoldier::Action(Point2d newlocation ){


}

void SniperSoldier::Attack(std::list<Soldiers*>& list ){
    for(auto& soldiertoattack:list){
        if(soldiertoattack->getId() != getId()){
            double d=std::sqrt(std::pow(getSoldierLocation().getX()-soldiertoattack->getSoldierLocation().getX(),2)+
            std::pow(getSoldierLocation().getY()-soldiertoattack->getSoldierLocation().getY(),2));//calculate distance and check
            int sikui=((d-1)/d)*10;
            int rand=Soldiers::random();
            int numofshots=weapon->getNumofshots();
            while(numofshots) {
                if (sikui <= rand) {
                    int power=weapon->getPower();
                    if(soldiertoattack->getArmors()[0]!= nullptr){
                        power=power*soldiertoattack->getArmors()[0]->getLevelarmor();
                    }
                    if(soldiertoattack->getArmors()[1]!= nullptr){
                        power=power*soldiertoattack->getArmors()[1]->getLevelarmor();
                    }
                    soldiertoattack->setLife(soldiertoattack->getLife() -power);
                }
                --numofshots;
            }
            break;//after 1 attack will stop.
        }
    }
}




SniperSoldier::~SniperSoldier() {
    if(weapon != nullptr){
        delete(weapon);
    }

}

