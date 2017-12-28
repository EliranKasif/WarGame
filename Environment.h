//
// Created by noysi on 26-Dec-17.
//

#ifndef WAR_ENVIRONMENT_H
#define WAR_ENVIRONMENT_H


#include <vector>
#include <list>
#include "soldiers/Soldiers.h"

class Environment {

private:
    const size_t wSize,hSize;


public:
    Environment();
    Environment(const size_t wSize, const size_t hSize);
    std::vector<std::vector<std::list<Items*>>> itemsEnviroment;
    std::vector<std::vector<std::list<Soldiers*>>> SolidersEnviroment;
    void addSoldier(size_t i,size_t j,Soldiers* soldier);
    void removeSoldier(size_t i,size_t j,Soldiers* solidier);
    void addItem(size_t i,size_t j,Items* soldier);
    void removeIteam(size_t i,size_t j,Items* solidier);

};


#endif //WAR_ENVIRONMENT_H