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

    virtual ~HealerSoldier();

    Weapons* Action(Weapons *weapon) override;
    virtual void Attack(std::list<Soldiers*>& list,std::ofstream& ss ) override;


private:
    virtual void toString(std::ostream &os) const;
};


#endif //WARGAME_HEALERSOLDIER_H
