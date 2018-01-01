//
// Created by eliran on 19/12/17.
//

#include <iostream>
#include <fstream>
#include "HealerSoldier.h"

HealerSoldier::HealerSoldier(int _id)
        : Soldiers(_id,DEFAULT_LIFE_HEALER,DEFAULT_SPEED_HEALER,DEFAULT_LIFE_HEALER) {}


Weapons* HealerSoldier::Action(Weapons *weapon){
    return nullptr;
}


void HealerSoldier:: toString(std::ostream &os) const {
    os << "Type: Healer Soldier, ";
    Soldiers::toString(os);
}

void HealerSoldier::Attack(std::list<Soldiers*>& list,std::ofstream& ss  ){
    for(auto& soldierto:list){
        if(soldierto!=this) {
            if (soldierto->getId() == getId())//check if there is someone to heal first !
            {
                std::cout << "and decied to heal: " <<std::endl<< *soldierto << std::endl;
                ss<< "and decied to heal: " <<std::endl<< *soldierto << std::endl;
                soldierto->setLife(soldierto->getDefaultlife());
                std::cout << "and after heal: " << soldierto->getLife() << std::endl;
                ss<<"and after heal: " << soldierto->getLife() << std::endl;
                break;
            } else {
                std::cout << "decied to attack: " << *soldierto << std::endl;
                ss<<"decied to attack: " << *soldierto << std::endl;
                soldierto->setLife(soldierto->getLife() - 10);
                if(soldierto->getLife()<=0) {
                    std::cout << "and kill the soldier" << std::endl;
                    ss << "and kill the soldier" << std::endl;
                    auto i=list.begin();
                    while(i!= list.end()){
                        auto j=i;
                        ++i;
                        if(*j==soldierto)
                        {
                            list.erase(j);
                            break;
                        }
                    }
                }
                else{
                    std::cout << "and attack succsess" << std::endl;
                    ss << "and attack succsess" << std::endl;
                }

            }
        }

    }

}
HealerSoldier::~HealerSoldier() {

}
