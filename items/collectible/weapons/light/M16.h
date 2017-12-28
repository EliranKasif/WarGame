//Missile
// Created by eliran on 18/12/17.
//

#ifndef WARGAME_M16_H
#define WARGAME_M16_H


#include "LightWeapons.h"

class M16: public LightWeapons {
public:
    M16();

    virtual ~M16();

private:
    void toString(std::ostream &os) const override;

};


#endif //WARGAME_M16_H
