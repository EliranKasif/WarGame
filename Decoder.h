//
// Created by eliran on 24/12/17.
//

#ifndef WARGAME_DECODER_H
#define WARGAME_DECODER_H


#include "FileControler.h"
#include "Point2d.h"
#include <sstream>
#include <iostream>
#include <map>
#include <list>
#include <vector>

enum class Object:int
{UNDI=-1,HUMAN,COMPUTERRANDOM,REGULARSOLDIER,SNIPERSOLDIER,HEALERSOLDIER,M16,MISSILE,UZI,BODYARMOR,SHIELDARMOR,TREE,ARMOR,WEAPON,SOLID};

class Node{
public:
    Object soldier;
    Object weapon;
    Point2d point;
    Node(){}
};

class Node2{
public:
    Point2d point;
    Object type;
    Object itemType;
    Node2(){}
};

class Decoder {
public:
    Decoder(FileControler *buffer);

    void decode();

    virtual ~Decoder();

    FileControler *getBuffer() const;

    void setBuffer(FileControler *buffer);

    void print();

    int getBattlefieldwidth() const;

    int getBattlefieldheight() const;

    int getPlayers() const;

    const std::map<std::pair<std::string, int>, std::list<Node>> &getMap_to_init_players() const;

    int getSoldiers() const;

    const std::list<Node2> &getList_init_to_items_on_map() const;

    const std::list<std::pair<double, double>> &getSolid() const;

    const std::list<double> &getArmorlevel() const;

private:
    FileControler *buffer;
    int battlefieldwidth=0;
    int battlefieldheight=0;
    int players=0;
    int soldiers=0;
    std::list<double> armorlevel;
    std::list<std::pair<double,double>> solid;
    enum class flag:char{FROMPLAYER,FROMOBJECT};

    template<typename Out>
    void split(const std::string &s, char delim, Out result);
    void split(const std::string &s, char delim, std::vector<std::string> &elems);
    void initWeaponsEnum(std::vector<std::string>::iterator& it,flag from);
    void initSoldierEnum(std::vector<std::string>::iterator& it,flag from);
    void initPlayersEnum(std::vector<std::string>::iterator& it,int soldiers);
    void initPointsObj(std::vector<std::string>::iterator& it,flag from);
    std::map <std::pair<std::string,int>,std::list<Node>> map_to_init_players;
    Node obj;
    std::list<Node> nodes;
    Node2 obj2;
    std::list<Node2> list_init_to_items_on_map;


};



#endif //WARGAME_DECODER_H
