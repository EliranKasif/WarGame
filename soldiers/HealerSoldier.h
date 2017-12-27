//
// Created by eliran on 19/12/17.
//

#ifndef WARGAME_HEALERSOLDIER_H
#define WARGAME_HEALERSOLDIER_H


#include "Soldiers.h"

class HealerSoldier: public Soldiers {

public:

    HealerSoldier(int _id);

    HealerSoldier()= default;

    virtual void Action() override;

};


#endif //WARGAME_HEALERSOLDIER_H
