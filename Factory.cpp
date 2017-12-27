//
// Created by eliran on 25/12/17.
//

#include "Factory.h"
#include "items/collectible/weapons/light/M16.h"
#include "items/collectible/weapons/heavy/Missile.h"
#include "items/collectible/weapons/light/Uzi.h"
#include "items/collectible/armors/ShieldArmor.h"
#include "items/collectible/armors/BodyArmor.h"
#include "items/notcollectible/Tree.h"


Player* Factory::createPlayer(Object type,const int _numofsoldiers,const double _battlefieldwidth,const double _battlefieldheight){

    Player* p= nullptr;
    switch (type){
        case Object ::HUMAN:
            p=new Player();
            Strategy* s=new HumanStrategy(_numofsoldiers,_battlefieldwidth,_battlefieldheight);
            p->setStrategy(s);
            break;

        case Object ::COMPUTERRANDOM:
            p=new Player();
            Strategy* s1=new ComputerStrategy();
            p->setStrategy(s1);
            break;
    }
    return p;
}

Soldiers*  Factory::createSoldier(Object type,int _id,Object weapon) {
    Soldiers *s = nullptr;
    Weapons* w=nullptr;
    switch (type) {
        case Object::REGULARSOLDIER:
            w=Factory::createWeapon(weapon);
            s = new RegularSoldier(_id,w);
            break;
        case Object::HEALERSOLDIER:
            s = new HealerSoldier(_id);
            break;
        case Object::SNIPERSOLDIER:
            w=Factory::createWeapon(weapon);
            s = new SniperSoldier(_id,w);
            break;
    }

    return s;
}


Weapons* Factory::createWeapon(Object type){
    Weapons* w=nullptr;

    switch (type){
        case Object ::M16:
            w=new M16();
            break;
        case Object ::MISSILE:
            w=new Missile();
            break;
        case Object ::UZI:
            w=new Uzi();
            break;
    }
    return w;
}

Armors*  Factory::createArmor(Object type,double _levelarmor){
    Armors* a= nullptr;
    switch (type){
        case Object ::SHIELDARMOR:
            a=new ShieldArmor(_levelarmor);
            break;
        case Object ::BODYARMOR:
            a=new BodyArmor(_levelarmor);
            break;
    }
    return a;
}

NotCollectibleItems*  Factory::createSolid(Object type,double _width, double _height){
    NotCollectibleItems* solid= nullptr;
    switch (type) {
        case Object::TREE:
            solid = new Tree(_width,_height);
            break;
    }
    return solid;
}

