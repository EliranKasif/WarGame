//
// Created by eliran on 26/12/17.
//

#ifndef WARGAME_PLAYER_H
#define WARGAME_PLAYER_H


#include <map>
#include "Strategy.h"
#include "soldiers/Soldiers.h"
#include "Decoder.h"

class Player {
private:
    static int id;
    const int playerId;
    Strategy* strategy;
    std::map<Soldiers*,std::list<Point2d>> army;
public:
    Player();

    //void round(/Envarioment/);

    void setStrategy(Strategy *strategy);

    Strategy *getStrategy() const;

    const int getId() const;

    const std::map<Soldiers *, std::list<Point2d>> &getArmy() const;

    void setArmy(const std::map<Soldiers *, std::list<Point2d>> &army);

    void InitArmy(std::list<Node>& listSoldiers);
    //{for( on army) strategy.getVector[i]}
};


#endif //WARGAME_PLAYER_H
