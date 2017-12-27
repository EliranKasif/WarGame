//
// Created by eliran on 19/12/17.
//

#ifndef WARGAME_SNIPERSOLDIER_H
#define WARGAME_SNIPERSOLDIER_H


#include "Soldiers.h"
#include "../items/collectible/weapons/Weapons.h"


class SniperSoldier: public Soldiers {

public:
    SniperSoldier(int _id,Weapons* _weapon);

    SniperSoldier()= default;

    Weapons *getWeapon() const;

    void setWeapon(Weapons *weapon);

    void Action() override;

private:

    Weapons* weapon;
};



#endif //WARGAME_SNIPERSOLDIER_H
