//
// Created by eliran on 26/12/17.
//

#include "Player.h"
#include "Factory.h"

int Player::id=1;

Player::Player():playerId(id){
    ++id;
}
Strategy *Player::getStrategy() const {
    return strategy;
}

void Player::setStrategy(Strategy *s) {
    strategy = s;
}
const int Player::getId() const {
    return id;
}

const std::map<Soldiers *, std::list<Point2d>> &Player::getArmy() const {
    return army;
}


void Player::setArmy(const std::map<Soldiers *, std::list<Point2d>> &army) {
Player::army = army;
}

void Player::InitArmy(const std::list<Node>& listSoldiers){
    int counter=0;
    auto itlist=listSoldiers.begin();
    while(itlist != listSoldiers.end() && counter<listSoldiers.size() ){
        Soldiers* s=Factory::createSoldier((*itlist).soldier,playerId,(*itlist).weapon);
        s->setSoldierLocation((*itlist).point);
        const std::list<Point2d>& points=strategy->getDestination()[counter];
        army.emplace(s,points);
        ++counter;
        ++itlist;

    }
}

std::ostream &operator<<(std::ostream &os, const Player &player) {
    os << "Player Id: " << player.playerId << ", Strategy: " << *player.strategy;
    size_t i=1;
    os<<std::endl<<"Soldiers: \n";
    for(auto& soldierInArmy:player.army) {
        os << "Soldier (" << i << "):" << *soldierInArmy.first;
        ++i;
        os<<std::endl<<" Steps: ";
        for(auto& points:soldierInArmy.second){
            os<<points;
        }
        os<<std::endl;
    }

    return os;
}

void Player::round(Environment* arena){
    for(auto& soldier:army){
        Soldiers* currentsoldier=soldier.first;
        if(currentsoldier->getLife()<=0){ //check if soldier alive.
            army.erase(soldier.first);//need to check itarator validition
        }
        else {
            auto liststeps = soldier.second.begin();//take 1 step for each soldier and move it on arena
            if (liststeps != soldier.second.end()) {//chec if there is a steps for the soldier
                Point2d newlocation=*liststeps;
                newlocation=currentsoldier->checkifcanstep(newlocation);
                if(newlocation.getX()>arena->getWSize()){
                    newlocation.setX(arena->getWSize()-1);
                }
                else if(newlocation.getX()<0){
                    newlocation.setX(0);
                }
                if(newlocation.getY()>arena->getHSize()){
                    newlocation.setY(arena->getHSize()-1);
                }
                else if(newlocation.getY()<0){
                    newlocation.setY(0);
                }
                auto itemEnv=arena->getItemsinArena(newlocation.getX(),newlocation.getY());


                arena->removeSoldier(soldier.first->getSoldierLocation().getX(),//delete current location of soldier from the arena
                                     soldier.first->getSoldierLocation().getY(),
                                     soldier.first);
                (*(soldier.first)).Action(newlocation);//move the soldier and attack or heal
                arena->addSoldier(soldier.first->getSoldierLocation().getX(),//update the envrioment to the new location of the soldier
                                  soldier.first->getSoldierLocation().getY(),
                                  soldier.first);
                soldier.second.remove(*liststeps);//remove the 1st step after Action of a soldier.
            }
        }

    }
}


Player::~Player() {
    for(auto& soldierInArmy:army) {
        if(soldierInArmy.first){
            soldierInArmy.second.clear();
            delete(soldierInArmy.first);
        }
    }
    if(strategy)
        delete(strategy);
}



