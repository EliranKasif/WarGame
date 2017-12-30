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

    virtual ~RegularSoldier();

    Weapons *getWeapon() const;

    void setWeapon(Weapons *weapon);

    void Action(Point2d newlocation ) override;
    virtual Point2d checkifcanstep(const Point2d& point);
    virtual void Attack(std::list<Soldiers*>& list ) override;


private:
    virtual void toString(std::ostream &os) const;
    Weapons* weapon;
};




#endif //WARGAME_REGULARSOLDIER_H
