//
// Created by eliran on 18/12/17.
//

#ifndef WARGAME_LIGHTWEAPONS_H
#define WARGAME_LIGHTWEAPONS_H


#include "../Weapons.h"


class LightWeapons: public Weapons {
public:
    LightWeapons(int _power,int _numofshots);
    LightWeapons();
    virtual ~LightWeapons();

    const int getNumofshots() const;

protected:
    virtual void toString(std::ostream &os) const override =0;

private:
    const int numofshots;


};


#endif //WARGAME_LIGHTWEAPONS_H
