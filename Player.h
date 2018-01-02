//
// Created by eliran on 26/12/17.
//

#ifndef WARGAME_PLAYER_H
#define WARGAME_PLAYER_H


#include <map>
#include <ostream>
#include "strategy/Strategy.h"
#include "soldiers/Soldiers.h"
#include "Decoder.h"
#include "Environment.h"

class Player:public Destroyer {
private:
    static int id;
    const int playerId;
    Strategy* strategy;
    std::map<Soldiers*,std::list<Point2d>> army;

    /*
     * @brief match a point to the size of the arena
     * @param Point2d&
     * @param int
     * @param int
     */
    void isInArena(Point2d& newlocation,int wSize,int hSize);

public:
    static int steps;

    /*
     * @brief default Constructor
     */
    Player();

    /*
     * @brief virtual Destructor
     */
    virtual ~Player();

    /*
     * @brief turn of the player in the round
     * @param Environment&
     * @param std::ofstream&
     */
    void round(Environment& arena,std::ofstream& ss);

    /*
     * @brief set Strategy
     * @param Strategy*
     */
    void setStrategy(Strategy *strategy);

    /*
     * @brief get Strategy
     * @return Strategy*
     */
    Strategy *getStrategy() const;

    /*
     * @brief get Id
     * @return const int
     */
    const int getId() const;

    /*
     * @brief get Army
     * @return  const std::map<Soldiers *, std::list<Point2d>>&
     */
    const std::map<Soldiers *, std::list<Point2d>> &getArmy() const;

    /*
     * @brief set Army
     * @param const std::map<Soldiers *, std::list<Point2d>>&
     * @return void
     */
    void setArmy(const std::map<Soldiers *, std::list<Point2d>> &army);

    /*
     * @brief init army
     * @param const std::list<Node>&
     * @return void
     */
    void InitArmy(const std::list<Node>& listSoldiers);


    /*
     * @brief override operator<<
     * @param os - ostream& to return the stream
     * @param const Player & the object we want to print
     * @return ostream
     */
    friend std::ostream &operator<<(std::ostream &os, const Player &player);
};


#endif //WARGAME_PLAYER_H
