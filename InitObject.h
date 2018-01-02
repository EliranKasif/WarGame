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
#include "Exceptions/MyException.h"
#include "Exceptions/numofplayerException.h"

//TO-DO: Singelton!!

class InitObject {


public:

    /*
     * @brief default Constructor
     */
    InitObject();

    /*
     * @brief Constructor
     * @param Decoder *
     */
    InitObject(Decoder *decoder);

    /*
     * @brief virtual Destructor
     */
    virtual ~InitObject();

    /*
     * @brief Initialze objects
     * @param std::list<FileControler*>::iterator&
     * @return void
     */
    void Initialze(std::list<FileControler*>::iterator& it)throw(decodeException);

    /*
     * @brief get Battlefield width
     * @return int
     */
    int getBattlefieldwidth() const;

    /*
     * @brief set Battlefield width
     * @param int
     * @return void
     */
    void setBattlefieldwidth(int battlefieldwidth);

    /*
     * @brief get Battlefield height
     * @return int
     */
    int getBattlefieldheight() const;

    /*
     * @brief set Battlefield height
     * @param int
     * @return void
     */
    void setBattlefieldheight(int battlefieldheight);

    /*
     * @brief get Num of players
     * @return int
     */
    int getNumofplayers() const;

    /*
     * @brief set Num of players
     * @param int
     * @return void
     */
    void setNumofplayers(int numofplayers);

    /*
     * @brief get Num of soldiers
     * @return int
     */
    int getNumofsoldiers() const;

    /*
     * @brief set Num of soldiers
     * @param int
     * @return void
     */
    void setNumofsoldiers(int numofsoldiers);

    /*
     * @brief get Decoder
     * @return Decoder*
     */
    Decoder *getDecoder() const;

    /*
     * @brief set Decoder
     * @param Decoder*
     * @return void
     */
    void setDecoder(Decoder *decoder);

    /*
     * @brief get Players
     * @return const std::vector<Player *> &
     */
    const std::vector<Player *> &getPlayers() const;

    /*
     * @brief set Players
     * @param const std::vector<Player *> &
     * @return void
     */
    void setPlayers(const std::vector<Player *> &players);

    /*
     * @brief get Items
     * @return const std::vector<Items *> &
     */
    const std::vector<Items *> &getItems() const;

    /*
     * @brief set Items
     * @param const std::vector<Items *> &
     * @return void
     */
    void setItems(const std::vector<Items *> &items);

    /*
     * @brief override operator<<
     * @param os - ostream& to return the stream
     * @param const Environment & the object we want to print
     * @return ostream
     */
    friend std::ostream &operator<<(std::ostream &os, const InitObject &object);

private:
    int battlefieldwidth;
    int battlefieldheight;
    int numofplayers;
    int numofsoldiers;
    Decoder* decoder;
    std::vector<Player*> players;
    std::vector<Items*> items;

    /*
     * @brief Initialze Players
     * @param std::list<FileControler*>::iterator&
     * @return void
     */
    void InitialzePlayers(std::list<FileControler*>::iterator& it);

    /*
     * @brief Initialze Items On Map
     * @return void
     */
    void InitialzeItemsOnMap();

};


#endif //WARGAME_INITOBJECT_H
