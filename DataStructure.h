//
// Created by eliran on 24/12/17.
//

#ifndef WARGAME_DATASTRUCTURE_H
#define WARGAME_DATASTRUCTURE_H


#include <ostream>
#include "items/Items.h"
#include "InitObject.h"
#include "Environment.h"

class DataStructure {
public:
    DataStructure(int argc, char *argv[]);

    InitObject* getData() ;

    Environment& getArena() ;

    friend std::ostream &operator<<(std::ostream &os, const DataStructure &structure);

private:
    InitObject data;
    Environment arena;
    void build(int argc, char *argv[]);//get the file names from the command line.

};


#endif //WARGAME_DATASTRUCTURE_H
