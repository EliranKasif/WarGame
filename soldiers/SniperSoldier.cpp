//
// Created by eliran on 19/12/17.
//

#include <complex>
#include <iostream>
#include <fstream>
#include "SniperSoldier.h"


SniperSoldier::SniperSoldier(int _id,Weapons* _weapon)
        : Soldiers(_id, DEFAULT_LIFE_SNIPER,DEFAULT_SPEED_SNIPER,DEFAULT_LIFE_SNIPER),weapon(_weapon){}

Weapons *SniperSoldier::getWeapon() const {
    return weapon;
}

void SniperSoldier::setWeapon(Weapons* weapon) {
    SniperSoldier::weapon = weapon;
}

void SniperSoldier:: toString(std::ostream &os) const {
    os << "Type: Sniper Soldier, ";
    Soldiers::toString(os);
    os<<"Weapon: " <<* weapon;
}


Weapons* SniperSoldier::Action(Weapons *weapon ){
    Weapons *selfweapon=getWeapon();
    weapon->setLocation(getSoldierLocation());
    setWeapon(weapon);
    return selfweapon;

}

void SniperSoldier::Attack(std::list<Soldiers*>& list,std::ofstream& ss  ){
    auto ktovetlist=&list;
    for(auto& soldiertoattack:list){
        if(soldiertoattack->getId() != getId()){
            double powX=std::pow((getSoldierLocation().getX()-soldiertoattack->getSoldierLocation().getX()),2);
            double powY=std::pow(getSoldierLocation().getY()-soldiertoattack->getSoldierLocation().getY(),2);
            double d=std::sqrt(powX+powY);//calculate distance and check
            if(d<=0){
                std::cout<<"Cant Attack, Soldier to close"<<std::endl;
                ss<<"Cant Attack, Soldier to close"<<std::endl;
                break;

            }
            double sikui=10;//((d-1)/d)*10;
            int numofshots=weapon->getNumofshots();
            while(numofshots>0) {
                int rand=Soldiers::random();
                std::cout<<"and decied to attack: "<<std::endl<< *soldiertoattack<<std::endl;
                ss<<"and decied to attack: "<<std::endl<< *soldiertoattack<<std::endl;
                if (sikui >= rand) {
                    int power=weapon->getPower();
                    typeofObject typeweapon=weapon->whoami();
                    if(soldiertoattack->getArmors()[0]!= nullptr){
                        if (soldiertoattack->getArmors()[0]->whoami() == typeofObject::BODYARMOR) {
                            if(weapon->whoami()!=typeofObject::HEAVY) {
                                power = power * soldiertoattack->getArmors()[0]->getLevelarmor();
                            }
                        }
                        else{
                            power = power * soldiertoattack->getArmors()[0]->getLevelarmor();
                        }
                    }
                    if(soldiertoattack->getArmors()[1]!= nullptr){
                        if (soldiertoattack->getArmors()[0]->whoami() == typeofObject::BODYARMOR) {
                            if(weapon->whoami()!=typeofObject::HEAVY) {
                                power = power * soldiertoattack->getArmors()[0]->getLevelarmor();
                            }
                        }
                        else{
                            power = power * soldiertoattack->getArmors()[0]->getLevelarmor();
                        }
                    }
                    soldiertoattack->setLife(soldiertoattack->getLife() -power);
                    if(soldiertoattack->getLife()<=0){
                        std::cout<<"and succsess to hit and the soldier is dead: "<<soldiertoattack->getLife()<<std::endl;
                        ss<<"and succsess to hit and the soldier is dead: "<<soldiertoattack->getLife()<<std::endl;
                        std::cout<<std::endl;
                        auto i=list.begin();
                        while(i!= list.end()){
                            auto j=i;
                            ++i;
                            if(*j==soldiertoattack)
                            {
                                list.erase(j);
                                break;
                            }
                        }
                    }
                    else {
                        std::cout << "and succsess to hit and the life is: " << soldiertoattack->getLife() << std::endl;
                    ss<< "and succsess to hit and the life is: " << soldiertoattack->getLife() << std::endl;

                    }
                }
                else {
                    std::cout<<"and missed up "<<std::endl;
                    ss<<"and missed up "<<std::endl;
                }

                --numofshots;
            }
            break;//after 1 attack will stop.
        }
    }
}




SniperSoldier::~SniperSoldier() {
//    if(weapon != nullptr){
//        delete(weapon);
//        weapon= nullptr;
//    }

}

