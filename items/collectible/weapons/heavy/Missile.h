//
// Created by eliran on 18/12/17.
//

#ifndef WARGAME_MISSILE_H
#define WARGAME_MISSILE_H


#include "HeavyWeapons.h"

class Missile: public HeavyWepons {
public:
    Missile();

private:
    void toString(std::ostream &os) const override;


};


#endif //WARGAME_MISSILE_H
