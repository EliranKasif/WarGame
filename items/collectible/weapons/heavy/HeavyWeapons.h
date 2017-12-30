//
// Created by eliran on 18/12/17.
//

#ifndef WARGAME_HEAVYWEPONS_H
#define WARGAME_HEAVYWEPONS_H


#include "../Weapons.h"

class HeavyWepons: public Weapons {
public:
    HeavyWepons(int _power,int _numofshots);
    HeavyWepons();
    virtual ~HeavyWepons();

protected:
    virtual void toString(std::ostream &os) const override =0;
};



#endif //WARGAME_HEAVYWEPONS_H
