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

void Player::InitArmy(std::list<Node>& listSoldiers){
    int counter=0;
    auto itlist=listSoldiers.begin();
    while(itlist != listSoldiers.end() && counter<listSoldiers.size() ){
        Soldiers* s=Factory::createSoldier((*itlist).soldier,playerId,(*itlist).weapon);
        s->setSoldierLocation((*itlist).point);
        ++itlist;
        ++counter;
    }
}



