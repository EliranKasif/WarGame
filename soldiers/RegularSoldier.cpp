//
// Created by eliran on 19/12/17.
//

#include <iostream>
#include <fstream>
#include <complex>
#include "RegularSoldier.h"

RegularSoldier::RegularSoldier(int _id,Weapons* _weapon)
        : Soldiers(_id,DEFAULT_LIFE_REGULAR,DEFAULT_SPEED_REGULAR,DEFAULT_LIFE_REGULAR),weapon(_weapon) {}


Weapons *RegularSoldier::getWeapon() const {
    return weapon;
}

void RegularSoldier::setWeapon(Weapons *weapon) {
    RegularSoldier::weapon = weapon;
}


void RegularSoldier:: toString(std::ostream &os) const {
    os << "Type: Regular Soldier, ";
    Soldiers::toString(os);
    os<<"Weapon: " <<* weapon;
}

Weapons* RegularSoldier::Action(Weapons *weapon) {
    Weapons *selfweapon=getWeapon();
    weapon->setLocation(getSoldierLocation());
    setWeapon(weapon);
    return selfweapon;
}

Point2d RegularSoldier::checkifcanstep(const Point2d& point){
    Point2d can;
    int speed=getSpeed();
    if(std::sqrt(std::pow(getSoldierLocation().getX()-point.getX(),2)+
                         std::pow(getSoldierLocation().getY()-point.getY(),2))>=4*getSpeed())//calculate distance and check
                        //if it grater then regular walk mul 4.
    {
        if(getLife()-10 > 0) { //check if soldier after running still alive
            speed = DEFAULT_RUNNING_REGULAR;
            setLife(getLife() - 10);
        }
    }
    if (getSoldierLocation().getX() > point.getX()) {
        if (getSoldierLocation().getY() > point.getY()) {
            can.setX(getSoldierLocation().getX() - getSpeed());
            can.setY(getSoldierLocation().getY() - getSpeed());

        } else if (getSoldierLocation().getY() == point.getY()) {
            can.setX(getSoldierLocation().getX() - getSpeed());
        } else {
            can.setX(getSoldierLocation().getX() - getSpeed());
            can.setY(getSoldierLocation().getY() + getSpeed());
        }
    } else if (getSoldierLocation().getX() == point.getX()) {
        if (getSoldierLocation().getY() > point.getY()) {
            can.setY(getSoldierLocation().getY() - getSpeed());

        } else if (getSoldierLocation().getY() == point.getY()) {
        } else {
            can.setY(getSoldierLocation().getY() + getSpeed());
        }
    } else {
        if (getSoldierLocation().getY() > point.getY()) {
            can.setX(getSoldierLocation().getX() + getSpeed());
            can.setY(getSoldierLocation().getY() - getSpeed());

        } else if (getSoldierLocation().getY() == point.getY()) {
            can.setX(getSoldierLocation().getX() + getSpeed());
        } else {
            can.setX(getSoldierLocation().getX() + getSpeed());
            can.setY(getSoldierLocation().getY() + getSpeed());
        }

    }
    return can;
}

void RegularSoldier::Attack(std::list<Soldiers*>& list,std::ofstream& ss  ){
    for(auto& soldiertoattack:list){
        if(soldiertoattack->getId() != getId()){
            double powX=std::pow((getSoldierLocation().getX()-soldiertoattack->getSoldierLocation().getX()),2);
            double powY=std::pow(getSoldierLocation().getY()-soldiertoattack->getSoldierLocation().getY(),2);
            double d=std::sqrt(powX+powY);//calculate distance and check
            if(d==0)
            {
                std::cout<<"Cant Attack, Soldier to close"<<std::endl;
                ss<<"Cant Attack, Soldier to close"<<std::endl;
                break;
            }
            double sikui=(1/d)*10;
            int numofshots=weapon->getNumofshots();
            while(numofshots) {
                int rand=Soldiers::random();
                std::cout<<"and decied to attack: "<<std::endl<< *soldiertoattack<<std::endl;
                ss<<"and decied to attack: "<<std::endl<< *soldiertoattack<<std::endl;
                if (sikui >= rand) {
                    int power=weapon->getPower();
                    typeofObject typeweapon=weapon->whoami();
                    if(soldiertoattack->getArmors()[0]!= nullptr){
                        if(weapon->whoami()==typeofObject::HEAVY)
                            power=power*soldiertoattack->getArmors()[0]->getLevelarmor();
                        else
                        {
                            if(soldiertoattack->getArmors()[0]->whoami()==typeofObject::BODYARMOR)
                            {
                                power=power*soldiertoattack->getArmors()[0]->getLevelarmor();
                            }
                        }
                    }
                    if(soldiertoattack->getArmors()[1]!= nullptr){
                        if(weapon->whoami()==typeofObject::HEAVY)
                            power=power*soldiertoattack->getArmors()[0]->getLevelarmor();
                        else
                        {
                            if(soldiertoattack->getArmors()[0]->whoami()==typeofObject::BODYARMOR)
                            {
                                power=power*soldiertoattack->getArmors()[0]->getLevelarmor();
                            }
                        }
                    }
                    soldiertoattack->setLife(soldiertoattack->getLife() -power);
                    if(soldiertoattack->getLife()<=0){
                        std::cout<<"and succsess to hit and the soldier is dead: "<<soldiertoattack->getLife()<<std::endl;
                        ss<<"and succsess to hit and the soldier is dead: "<<soldiertoattack->getLife()<<std::endl;
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

                    std::cout << "and missed up "<< std::endl;
                    ss<< "and missed up "<< std::endl;
                }
                --numofshots;
            }
            break;

        }
    }
}


RegularSoldier::~RegularSoldier(){
    if(weapon){
        delete(weapon);
    }
}
