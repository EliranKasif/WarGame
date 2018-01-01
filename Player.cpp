//
// Created by eliran on 26/12/17.
//

#include <complex>
#include "Player.h"
#include "Factory.h"

int Player::id=1;
int Player::steps=0;

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

void Player::isInArena(Point2d& newlocation,int wSize,int hSize){
    if(newlocation.getX()>wSize){//check if the newlocation is on map.
        newlocation.setX(wSize-1);
    }
    else if(newlocation.getX()<0){
        newlocation.setX(0);
    }
    if(newlocation.getY()>hSize){
        newlocation.setY(hSize-1);
    }
    else if(newlocation.getY()<0){
        newlocation.setY(0);
    }
}

void Player::round(Environment& arena,std::ofstream& ss) {
    auto itonarmy = army.begin();
    while (itonarmy != army.end()) {
        Soldiers &currentsoldier2 = *((*itonarmy).first);
        if (currentsoldier2.isCanmove()) {
            if (currentsoldier2.getLife() <= 0) { //check if soldier alive.
                army.erase(itonarmy);//need to check itarator validition
                ++steps;
                currentsoldier2.setCanmove(false);
            } else {
                bool ifcanwalk = true;
                auto liststeps = (*itonarmy).second.begin();//take 1 step for each soldier and move it on arena
                if (liststeps != (*itonarmy).second.end()) {//check if there is a steps for the soldier
                    Point2d newlocation = *liststeps;
                    newlocation = currentsoldier2.checkifcanstep(newlocation);//check how far the soldier can walk.
                    Player::isInArena(newlocation, arena.getWSize(), arena.getHSize());
                    auto &itemEnv = arena.getItemsinArena(newlocation.getX(), newlocation.getY());
                    auto &soldierEnv = arena.getSoldiersinArena(newlocation.getX(), newlocation.getY());
                    auto it = itemEnv.begin();
                    if (*it == nullptr) {
                        arena.removeSoldier(
                                (*itonarmy).first->getSoldierLocation().getX(),//delete current location of soldier from the arena
                                (*itonarmy).first->getSoldierLocation().getY(),
                                (*itonarmy).first);
                        std::cout << currentsoldier2 << std::endl << "Walked to: " << newlocation << std::endl;
                        ss << currentsoldier2 << std::endl << "Walked to: " << newlocation << std::endl;
                        currentsoldier2.setSoldierLocation(newlocation);
                        arena.addSoldier(
                                (*itonarmy).first->getSoldierLocation().getX(),//update the envrioment to the new location of the soldier
                                (*itonarmy).first->getSoldierLocation().getY(),
                                (*itonarmy).first);
                    }
                    while (it != itemEnv.end()) {
                        typeofObject type = (*it)->whoami();
                        if (type == typeofObject::NOTCOLLECTIBLE) {
                            ifcanwalk = false;//cant walk there;
                            std::cout << "Can't walk to: " << newlocation << " there is a solid there." << std::endl;
                            ss << "Can't walk to: " << newlocation << " there is a solid there." << std::endl;
                            break;
                        }
                        if (ifcanwalk) {
                            arena.removeSoldier(
                                    currentsoldier2.getSoldierLocation().getX(),//delete current location of soldier from the arena
                                    currentsoldier2.getSoldierLocation().getY(),
                                    &currentsoldier2);
                            std::cout << currentsoldier2 << std::endl << "Walked to: " << newlocation << std::endl;
                            ss << currentsoldier2 << std::endl << "Walked to: " << newlocation << std::endl;
                            currentsoldier2.setSoldierLocation(newlocation);
                            arena.addSoldier(
                                    currentsoldier2.getSoldierLocation().getX(),//update the envrioment to the new location of the soldier
                                    currentsoldier2.getSoldierLocation().getY(),
                                    &currentsoldier2);
                            double powX = std::pow(
                                    (currentsoldier2.getSoldierLocation().getX() - (*it)->getLocation().getX()), 2);
                            double powY = std::pow(
                                    currentsoldier2.getSoldierLocation().getY() - (*it)->getLocation().getY(), 2);
                            double distance = std::sqrt(powX + powY);//calculate distance and check
                            if (type == typeofObject::WEAPON || type == typeofObject::HEAVY) {
                                if (distance <= DEFAULT_PICKING_RADIUS) {
                                    auto weap = (Weapons *) *it;
                                    std::cout << "And decied to pick a Weapon: " << *weap << std::endl;
                                    ss << "And decied to pick a Weapon: " << *weap << std::endl;
                                    weap = currentsoldier2.Action(
                                            weap);//set new weapon and bring back the perviuos weapon
                                    if (weap) {
                                        Point2d current = currentsoldier2.getSoldierLocation();
                                        weap->setLocation(current);
                                        *it = weap;
                                    }
                                }
                                break;


                            } else if (type == typeofObject::SHEILDARMOR || type == typeofObject::BODYARMOR) {
                                if (distance <= DEFAULT_PICKING_RADIUS) {
                                    auto armor = (Armors *) *it;
                                    std::cout << "And decied to pick a Armor: " << *armor << std::endl;
                                    ss << "And decied to pick a Armor: " << *armor << std::endl;
                                    armor = currentsoldier2.setArmors(
                                            armor);//set new armor and bring back the perviuos armor
                                    if (armor) {
                                        *it = armor;
                                    } else {
                                        it = itemEnv.erase(it);
                                    }
                                }
                                break;


                            }
                        }

                    }
                    currentsoldier2.Attack(soldierEnv, ss);//Attack with the soldier
                    (*itonarmy).second.erase(liststeps);//remove the 1st step after Action of a soldier.
                } else {//there is no steps for this player any more
                    currentsoldier2.setCanmove(false);
                    ++steps;
                }

            }
        }
        ++itonarmy;
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



