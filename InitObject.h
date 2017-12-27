//
// Created by eliran on 24/12/17.
//

#ifndef WARGAME_INITOBJECT_H
#define WARGAME_INITOBJECT_H

#include <iostream>
#include <map>
#include <list>
#include <vector>
#include "Player.h"
#include "items/Items.h"
#include "Decoder.h"
#include "Factory.h"

//TO-DO: Singelton!!

class InitObject {


public:
    InitObject(Decoder *decoder);
    void Initialze();
    void InitialzePlayers();
    void InitialzeItemsOnMap();

private:
    int battlefieldwidth;
    int battlefieldheight;
    int numofplayers;
    int numofsoldiers;
    Decoder* decoder;
    std::vector<Player*> players;
    std::vector<Items*> items;



};


#endif //WARGAME_INITOBJECT_H
