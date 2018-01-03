//
// Created by eliran on 25/12/17.
//

#include "Factory.h"
#include "../items/collectible/weapons/light/M16.h"
#include "../items/collectible/weapons/heavy/Missile.h"
#include "../items/collectible/weapons/light/Uzi.h"
#include "../items/collectible/armors/ShieldArmor.h"
#include "../items/collectible/armors/BodyArmor.h"
#include "../items/notcollectible/Tree.h"

std::vector<Destroyer*> Factory:: byebye;


Player* Factory::createPlayer(Object type, int _numofsoldiers, double _battlefieldwidth, double _battlefieldheight,
                              std::list<FileControler *>::iterator &it) {
    Player* p=nullptr;
    switch(type){
        case Object::COMPUTERRANDOM : {
            p = new Player();
            Strategy *s = new ComputerStrategy(_numofsoldiers, _battlefieldwidth, _battlefieldheight);
            p->setStrategy(s);
            //Factory::byebye.emplace_back(p);
            break;
        }
        case Object ::HUMAN: {
            p = new Player();
            Strategy *s1 = new HumanStrategy(*it,_numofsoldiers);
            ++it;
            p->setStrategy(s1);
            //Factory::byebye.emplace_back(p);
            break;
        }
    }
    return p;
}


Soldiers*  Factory::createSoldier(Object type,int _id,Object weapon) {
    Soldiers *s = nullptr;
    Weapons* w=nullptr;
    switch (type) {
        case Object::REGULARSOLDIER: {
            w = Factory::createWeapon(weapon);
            s = new RegularSoldier(_id, w);
            Factory::byebye.emplace_back(s);
            break;
        }
        case Object::HEALERSOLDIER: {
            s = new HealerSoldier(_id);
            Factory::byebye.emplace_back(s);
            break;
        }
        case Object::SNIPERSOLDIER: {
            w = Factory::createWeapon(weapon);
            s = new SniperSoldier(_id, w);
            Factory::byebye.emplace_back(s);
            break;
        }
    }

    return s;
}


Weapons* Factory::createWeapon(Object type){
    Weapons* w=nullptr;

    switch (type){
        case Object ::M16: {
            w = new M16();
            Factory::byebye.emplace_back(w);
            break;
        }
        case Object ::MISSILE: {
            w = new Missile();
            Factory::byebye.emplace_back(w);
            break;
        }
        case Object ::UZI: {
            w = new Uzi();
            Factory::byebye.emplace_back(w);
            break;
        }
    }
    return w;
}

Armors*  Factory::createArmor(Object type,double _levelarmor){
    Armors* a= nullptr;
    switch (type){
        case Object ::SHIELDARMOR: {
            a = new ShieldArmor(_levelarmor);
            Factory::byebye.emplace_back(a);
            break;
        }
        case Object ::BODYARMOR: {
            a = new BodyArmor(_levelarmor);
            Factory::byebye.emplace_back(a);
            break;
        }
    }
    return a;
}

NotCollectibleItems*  Factory::createSolid(Object type,double _width, double _height){
    NotCollectibleItems* solid= nullptr;
    switch (type) {
        case Object::TREE: {
            solid = new Tree(_width, _height);
            Factory::byebye.emplace_back(solid);
            break;
        }
    }
    return solid;
}

std::vector<Destroyer *> &Factory::getByebye() {
    return byebye;
}


