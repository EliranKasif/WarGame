//
// Created by eliran on 28/12/17.
//

#include <iostream>
#include "Environment.h"

void Environment:: addSoldier(size_t i,size_t j,Soldiers* soldier){
    SolidersEnviroment[i/10][j/10].push_back(soldier);
}
void Environment:: removeSoldier(size_t i,size_t j,Soldiers* soldier){
    SolidersEnviroment[i/10][j/10].remove(soldier);
}
void Environment:: addItem(size_t i,size_t j,Items* item){
    itemsEnviroment[i/10][j/10].emplace_back(item);
}
void Environment:: removeIteam(size_t i,size_t j,Items* item){
    itemsEnviroment[i/10][j/10].remove(item);
}

void Environment:: build(){
    size_t x=wSize/10;
    size_t y=hSize/10;
    itemsEnviroment.resize(x);
    SolidersEnviroment.resize(x);
    for(int i = 0 ; i < x ; ++i)
    {
        //Grow Columns by hSize
        itemsEnviroment[i].resize(y);
        SolidersEnviroment[i].resize(y);

    }
}

Environment::Environment():wSize(ZERO), hSize(ZERO) {}

size_t Environment::getWSize() const {
    return wSize;
}

void Environment::setWSize(size_t wSize) {
    Environment::wSize = wSize;
}

size_t Environment::getHSize() const {
    return hSize;
}

void Environment::setHSize(size_t hSize) {
    Environment::hSize = hSize;
}



std::ostream &operator<<(std::ostream &os, const Environment &environment) {
    os << "wSize: " << environment.wSize << " hSize: " << environment.hSize << "\nSoldiersEnviroment: "<<std::endl;
    size_t x=environment.wSize/10;
    size_t y=environment.hSize/10;
    for(size_t i=0;i<x;++i){
        for(size_t j=0;j<y;++j){
            os<<"["<<i<<","<<j<<"]: ";
            for(auto& it:environment.SolidersEnviroment[i][j])
            {
                os<<it->getSoldierLocation()<<", ";
            }

        }
        os<<std::endl;
    }

    os<<"Items on Map: "<<std::endl;
    for(size_t i=0;i<x;++i){
        for(size_t j=0;j<y;++j){
            os<<"["<<i<<","<<j<<"]: ";
            for(auto& it:environment.itemsEnviroment[i][j])
            {
                os<<it->getLocation()<<", ";
            }

        }
        os<<std::endl;
    }


    return os;
}