//
// Created by noysi on 26-Dec-17.
//

#ifndef WAR_ENVIRONMENT_H
#define WAR_ENVIRONMENT_H


#include <vector>
#include <list>
#include <ostream>
#include "soldiers/Soldiers.h"

class Environment {

private:
    size_t wSize,hSize;
    std::vector<std::vector<std::list<Items*>>> itemsEnviroment;
    std::vector<std::vector<std::list<Soldiers*>>> SolidersEnviroment;
public:
    friend std::ostream &operator<<(std::ostream &os, const Environment &environment);

public:
    Environment();

    void build();

    size_t getWSize() const;

    void setWSize(size_t wSize);

    size_t getHSize() const;

    void setHSize(size_t hSize);
    Soldiers* getSoldier(size_t i,size_t j);
    void addSoldier(size_t i,size_t j,Soldiers* soldier);
    void removeSoldier(size_t i,size_t j,Soldiers* solidier);
    void addItem(size_t i,size_t j,Items* soldier);
    void removeIteam(size_t i,size_t j,Items* solidier);
    void updateSoldierEnvironment(const Soldiers* solidier);
    void updateItemEnvironment(const Items* solidier);



};


#endif //WAR_ENVIRONMENT_H