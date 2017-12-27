//
// Created by eliran on 19/12/17.
//

#ifndef WARGAME_REGULARSOLDIER_H
#define WARGAME_REGULARSOLDIER_H
#include "Soldiers.h"
#include "../items/collectible/weapons/Weapons.h"

class RegularSoldier : public Soldiers{

public:
    RegularSoldier()= default;
    RegularSoldier(int _id,Weapons* weapon);

    Weapons *getWeapon() const;

    void setWeapon(Weapons *weapon);

    virtual void Action() override;

private:

    Weapons* weapon;
};




#endif //WARGAME_REGULARSOLDIER_H
