//
// Created by eliran on 19/12/17.
//

#include <cmath>
#include "RegularSoldier.h"

RegularSoldier::RegularSoldier(int _id,Weapons* _weapon)
        : Soldiers(_id,DEFAULT_LIFE_REGULAR,DEFAULT_SPEED_REGULAR),weapon(_weapon) {}


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

void RegularSoldier::Action(Point2d newlocation) {}

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
    if (getSoldierLocation().getX() < point.getX()) {
        if (getSoldierLocation().getY() < point.getY()) {
            can.setX(getSoldierLocation().getX() - speed);
            can.setY(getSoldierLocation().getY() - speed);

        } else if (getSoldierLocation().getY() == point.getY()) {
            can.setX(getSoldierLocation().getX() - speed);
        } else {
            can.setX(getSoldierLocation().getX() - speed);
            can.setY(getSoldierLocation().getY() + speed);
        }
    } else if (getSoldierLocation().getX() == point.getX()) {
        if (getSoldierLocation().getY() < point.getY()) {
            can.setY(getSoldierLocation().getY() - speed);

        } else if (getSoldierLocation().getY() == point.getY()) {
        } else {
            can.setY(getSoldierLocation().getY() + speed);
        }
    } else {
        if (getSoldierLocation().getY() < point.getY()) {
            can.setX(getSoldierLocation().getX() + speed);
            can.setY(getSoldierLocation().getY() - speed);

        } else if (getSoldierLocation().getY() == point.getY()) {
            can.setX(getSoldierLocation().getX() + speed);
        } else {
            can.setX(getSoldierLocation().getX() + speed);
            can.setY(getSoldierLocation().getY() + speed);
        }

    }
    return can;
}

void RegularSoldier::Attack(std::list<Soldiers*>& list ){
    for(auto& soldiertoattack:list){
        if(soldiertoattack->getId() != getId()){
            double d=std::sqrt(std::pow(getSoldierLocation().getX()-soldiertoattack->getSoldierLocation().getX(),2)+
                               std::pow(getSoldierLocation().getY()-soldiertoattack->getSoldierLocation().getY(),2));//calculate distance and check
            int sikui=(1/d)*10;
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
            break;

        }
    }
}

RegularSoldier::~RegularSoldier() {

    if(weapon != nullptr){
        delete(weapon);
    }
}
