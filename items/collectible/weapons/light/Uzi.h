//
// Created by eliran on 18/12/17.
//

#ifndef WARGAME_UZI_H
#define WARGAME_UZI_H


#include "LightWeapons.h"

class Uzi: public LightWeapons {
public:
    Uzi();
    virtual ~Uzi();

private:
    void toString(std::ostream &os) const override;

};


#endif //WARGAME_UZI_H
