//
// Created by eliran on 24/12/17.
//

#ifndef WARGAME_DATASTRUCTURE_H
#define WARGAME_DATASTRUCTURE_H


#include "items/Items.h"
#include "InitObject.h"
#include "Environment.h"

class DataStructure {
public:
    DataStructure();

private:
    InitObject data;
    Environment arena;

};


#endif //WARGAME_DATASTRUCTURE_H
