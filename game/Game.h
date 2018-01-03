//
// Created by eliran on 02/01/18.
//

#ifndef WARGAME_GAME_H
#define WARGAME_GAME_H


#include "../Data/DataStructure.h"
#include "../ExternalHandler/ReadFromuser.h"
#include "../Exceptions/equalityException.h"

class Game {

private:
    ReadFromuser design;
    DataStructure DS;
public:
    void read(int argc,char *argv[]) throw (decodeException,argumentException,equalityException,numofplayerException,numofSoldiersException);
    void initDataStructure();
    void GameLogic();
    void GameOver();

};


#endif //WARGAME_GAME_H
