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

    void Action(Point2d newlocation ) override;
    virtual void Attack(std::list<Soldiers*>& list ) override;


private:
    virtual void toString(std::ostream &os) const;
};


#endif //WARGAME_HEALERSOLDIER_H
