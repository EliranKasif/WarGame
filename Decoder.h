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
    /*
     * @brief Constructor
     * @param FileControler *
     */
    Decoder(FileControler *buffer);

    /*
     * @brief build enum from string
     */
    void decode();

    /*
     * @brief virtual Destructor
     */
    virtual ~Decoder();

    /*
     * @brief get Buffer
     * @return FileControler*
     */
    FileControler *getBuffer() const;

    /*
     * @brief set buffer
     * @param FileControler *
     * @return void
     */
    void setBuffer(FileControler *buffer);

    /*
     * @brief print
     * @return void
     */
    void toString();

    /*
     * @brief get Battlefieldwidth
     * @return int
     */
    int getBattlefieldwidth() const;

    /*
     * @brief get Battlefieldheight
     * @return int
     */
    int getBattlefieldheight() const;

    /*
     * @brief get Players
     * @return int
     */
    int getPlayers() const;

    /*
     * @brief get Map_to_init_players
     * @return const std::map<std::pair<std::string, int>, std::list<Node>>
     */
    const std::map<std::pair<std::string, int>, std::list<Node>> &getMap_to_init_players() const;

    /*
     * @brief get Soldiers
     * @return int
     */
    int getSoldiers() const;

    /*
     * @brief get List_init_to_items_on_map
     * @return const std::list<Node2> &
     */
    const std::list<Node2> &getList_init_to_items_on_map() const;

    /*
     * @brief get Solid
     * @return const std::list<std::pair<double, double>> &
     */
    const std::list<std::pair<double, double>> &getSolid() const;

    /*
     * @brief get Armorlevel
     * @return const std::list<double> &
     */
    const std::list<double> &getArmorlevel() const;

private:
    FileControler *buffer;
    int battlefieldwidth=0;
    int battlefieldheight=0;
    int players=0;
    int soldiers=0;
    std::list<double> armorlevel;
    std::list<std::pair<double,double>> solid;
    std::map <std::pair<std::string,int>,std::list<Node>> map_to_init_players;
    Node obj;
    std::list<Node> nodes;
    Node2 obj2;
    std::list<Node2> list_init_to_items_on_map;
    enum class flag:char{FROMPLAYER,FROMOBJECT};

    /*
     * @brief template split cut by comma
     * @param const std::string &
     * @param Out- itrerator of the result
     * @return void
     */
    template<typename Out>
    void split(const std::string &s, char delim, Out result);

    /*
     * @brief specific split, cut by comma
     * @param const std::string &
     * @param std::vector<std::string> &
     * @return void
     */
    void split(const std::string &s, char delim, std::vector<std::string> &elems);

    /*
     * @brief if the object is weapon init Weapons Enum
     * @param std::vector<std::string>::iterator&
     * @param flag- check if belong to soldier or item on the map
     * @return void
     */
    void initWeaponsEnum(std::vector<std::string>::iterator& it,flag from);

    /*
     * @brief if the object is soldier init soldier Enum
     * @param std::vector<std::string>::iterator&
     * @param flag- change if belong to soldier or item on the map
     * @return void
     */
    void initSoldierEnum(std::vector<std::string>::iterator& it,flag from);

    /*
     * @brief if the object is player init player Enum
     * @param std::vector<std::string>::iterator&
     * @param int- num of soldiers for computer strategy
     * @return void
     */
    void initPlayersEnum(std::vector<std::string>::iterator& it,int soldiers);

    /*
     * @brief if the object is item on the map init Points Obj
     * @param std::vector<std::string>::iterator&
     * @param flag- check if belong to soldier or item on the map
     * @return void
     */
    void initPointsObj(std::vector<std::string>::iterator& it,flag from);

};



#endif //WARGAME_DECODER_H
