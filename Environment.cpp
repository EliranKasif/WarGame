//
// Created by eliran on 28/12/17.
//

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

Environment::Environment(const size_t wSize, const size_t hSize) : wSize(wSize), hSize(hSize) {
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
