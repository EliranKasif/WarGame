//
// Created by eliran on 28/12/17.
//

#include "Environment.h"


void Environment:: addSoldier(size_t i,size_t j,Soldiers* soldier){
    SolidersEnviroment[i/DEFAULT_GRID_SIZE][j/DEFAULT_GRID_SIZE].emplace_back(soldier);
}
void Environment:: removeSoldier(size_t i,size_t j,Soldiers* soldier){
    auto it=SolidersEnviroment[i/DEFAULT_GRID_SIZE][j/DEFAULT_GRID_SIZE].begin();
    while(it != SolidersEnviroment[i/DEFAULT_GRID_SIZE][j/DEFAULT_GRID_SIZE].end()){
        if(*it==soldier)
        {
            SolidersEnviroment[i/DEFAULT_GRID_SIZE][j/DEFAULT_GRID_SIZE].erase(it);
            break;
        }
        ++it;
    }
}
void Environment:: addItem(size_t i,size_t j,Items& item){
    auto ktovet=&item;
    itemsEnviroment[i/DEFAULT_GRID_SIZE][j/DEFAULT_GRID_SIZE].emplace_back(&item);
    for(auto& p:itemsEnviroment[i/DEFAULT_GRID_SIZE][j/DEFAULT_GRID_SIZE])
    {
        auto ktovet1=&p;
        ktovet1=&p;
    }
}
void Environment:: removeIteam(size_t i,size_t j,Items& item){
    auto it=itemsEnviroment[i/DEFAULT_GRID_SIZE][j/DEFAULT_GRID_SIZE].begin();
    while(it != itemsEnviroment[i/DEFAULT_GRID_SIZE][j/DEFAULT_GRID_SIZE].end()){
        if(*it==&item)
        {
            itemsEnviroment[i/DEFAULT_GRID_SIZE][j/DEFAULT_GRID_SIZE].erase(it);
            break;
        }
        ++it;
    }
}

void Environment:: reSizeArena(){
    size_t x=wSize/DEFAULT_GRID_SIZE;
    size_t y=hSize/DEFAULT_GRID_SIZE;
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

bool Environment:: ifsolid(Point2d point) {
    auto list = itemsEnviroment[point.getX() / DEFAULT_GRID_SIZE][point.getY() / DEFAULT_GRID_SIZE];
    if (ZERO != list.size()) {//check if the list of the item in [x,y] is notempty
        for (auto &it:list) {//check the type of the item!!

        }
    }
}

std::list<Soldiers*>& Environment::getSoldiersinArena(size_t i,size_t j){
    i=i/DEFAULT_GRID_SIZE;
    j=j/DEFAULT_GRID_SIZE;
    auto ktovetlist=&SolidersEnviroment[i][j];
    return SolidersEnviroment[i][j];
}

std::list<Items*>& Environment::getItemsinArena(size_t i,size_t j){
    i=i/DEFAULT_GRID_SIZE;
    j=j/DEFAULT_GRID_SIZE;
    return itemsEnviroment[i][j];
}

std::ostream &operator<<(std::ostream &os, const Environment &environment) {
    os << "wSize: " << environment.wSize << " hSize: " << environment.hSize << "\nSoldiersEnviroment: "<<std::endl;
    size_t x=environment.wSize/DEFAULT_GRID_SIZE;
    size_t y=environment.hSize/DEFAULT_GRID_SIZE;
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

Environment::~Environment(){
    size_t x=wSize/DEFAULT_GRID_SIZE;
    size_t y=hSize/DEFAULT_GRID_SIZE;
    for(int i = 0 ; i < x ; ++i)
    {
        //Grow Columns by hSize
        for(int j =0 ; j<y;++j){
            itemsEnviroment[i][j].clear();
            SolidersEnviroment[i][j].clear();

        }
        itemsEnviroment[i].clear();
        SolidersEnviroment[i].clear();

    }
    itemsEnviroment.clear();
    SolidersEnviroment.clear();
}
