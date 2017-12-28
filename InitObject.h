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
#include "Environment.h"

//TO-DO: Singelton!!

class InitObject {


public:
    InitObject();
    InitObject(Decoder *decoder);
    InitObject(Decoder *decoder,Environment* arena);
    void Initialze(std::list<FileControler*>::iterator& it);
    friend std::ostream &operator<<(std::ostream &os, const InitObject &object);

private:
    int battlefieldwidth;
public:
    virtual ~InitObject();

    int getBattlefieldwidth() const;

    void setBattlefieldwidth(int battlefieldwidth);

    int getBattlefieldheight() const;

    void setBattlefieldheight(int battlefieldheight);

    int getNumofplayers() const;

    void setNumofplayers(int numofplayers);

    int getNumofsoldiers() const;

    void setNumofsoldiers(int numofsoldiers);

    Decoder *getDecoder() const;

    void setDecoder(Decoder *decoder);

    const std::vector<Player *> &getPlayers() const;

    void setPlayers(const std::vector<Player *> &players);

    const std::vector<Items *> &getItems() const;

    void setItems(const std::vector<Items *> &items);

private:
    int battlefieldheight;
    int numofplayers;
    int numofsoldiers;
    Decoder* decoder;
    Environment* arena;
    std::vector<Player*> players;
    std::vector<Items*> items;
    void InitialzePlayers(std::list<FileControler*>::iterator& it);
    void InitialzeItemsOnMap();

};


#endif //WARGAME_INITOBJECT_H
