//
// Created by eliran on 25/12/17.
//

#ifndef WARGAME_FACTORY_H
#define WARGAME_FACTORY_H


#include "InitObject.h"
#include "HumanStrategy.h"
#include "ComputerStrategy.h"
#include "items/collectible/weapons/Weapons.h"
#include "items/collectible/armors/Armors.h"
#include "items/notcollectible/NotCollectibleItems.h"
#include "soldiers/RegularSoldier.h"
#include "soldiers/HealerSoldier.h"
#include "soldiers/SniperSoldier.h"


//TO-DO: Factory singelton.
class Factory {

public:

    static Player* createPlayer(Object type,int _numofsoldiers,double _battlefieldwidth,double _battlefieldheight,std::list<FileControler*>::iterator& it);
    static Soldiers*  createSoldier(Object type,int _id,Object weapon);
    static Weapons*  createWeapon(Object type);
    static Armors*  createArmor(Object type,double _levelarmor);
    static NotCollectibleItems*  createSolid(Object type,double width, double height);

};


#endif //WARGAME_FACTORY_H
