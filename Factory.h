//
// Created by eliran on 25/12/17.
//

#ifndef WARGAME_FACTORY_H
#define WARGAME_FACTORY_H


#include "InitObject.h"
#include "strategy/HumanStrategy.h"
#include "strategy/ComputerStrategy.h"
#include "items/collectible/weapons/Weapons.h"
#include "items/collectible/armors/Armors.h"
#include "items/notcollectible/NotCollectibleItems.h"
#include "soldiers/RegularSoldier.h"
#include "soldiers/HealerSoldier.h"
#include "soldiers/SniperSoldier.h"

class Factory {



public:
    /*
     * @brief create Player
     * @param Object
     * @param int
     * @param double
     * @param double
     * @param std::list<FileControler*>::iterator&
     * @return Player*
     */
    static Player* createPlayer(Object type,int _numofsoldiers,double _battlefieldwidth,double _battlefieldheight,std::list<FileControler*>::iterator& it);

    /*
     * @brief create Soldiers
     * @param Object
     * @param int
     * @param Object
     * @param std::list<FileControler*>::iterator&
     * @return Soldiers*
     */
    static Soldiers*  createSoldier(Object type,int _id,Object weapon);

    /*
     * @brief create Weapon
     * @param Object
     * @return Weapons*
     */
    static Weapons*  createWeapon(Object type);

    /*
     * @brief create Armor
     * @param Object
     * @param double
     * @return Armors*
     */
    static Armors*  createArmor(Object type,double _levelarmor);

    /*
     * @brief create Solid
     * @param Object
     * @param double
     * @param double
     * @return NotCollectibleItems*
     */
    static NotCollectibleItems*  createSolid(Object type,double width, double height);
    static void Destoryed();
    static std::vector<Destroyer*> byebye;

};


#endif //WARGAME_FACTORY_H
