//
// Created by noysi on 26-Dec-17.
//

#ifndef WAR_ENVIRONMENT_H
#define WAR_ENVIRONMENT_H


#include <vector>
#include <list>
#include <ostream>
#include "items/Items.h"
#include "soldiers/Soldiers.h"

class Environment {

private:
    size_t wSize,hSize;
    std::vector<std::vector<std::list<Items*>>> itemsEnviroment;
    std::vector<std::vector<std::list<Soldiers*>>> SolidersEnviroment;


public:
    Environment();

    void build();

    size_t getWSize() const;

    void setWSize(size_t wSize);

    size_t getHSize() const;

    void setHSize(size_t hSize);
    void addSoldier(size_t i,size_t j,Soldiers* soldier);
    void removeSoldier(size_t i,size_t j,Soldiers* solidier);
    void addItem(size_t i,size_t j,Items* soldier);
    void removeIteam(size_t i,size_t j,Items* solidier);
    bool ifsolid(Point2d point);
    std::list<Soldiers*>& getSoldiersinArena(size_t i,size_t j);
    std::list<Items*>& getItemsinArena(size_t i,size_t j);


    friend std::ostream &operator<<(std::ostream &os, const Environment &environment);




};


#endif //WAR_ENVIRONMENT_H