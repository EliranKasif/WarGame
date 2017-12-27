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
        for (auto & p:points){
            Point2d x=p;
        }
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



