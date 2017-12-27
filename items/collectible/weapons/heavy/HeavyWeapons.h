//
// Created by eliran on 18/12/17.
//

#ifndef WARGAME_HEAVYWEPONS_H
#define WARGAME_HEAVYWEPONS_H


#include "../Weapons.h"

class HeavyWepons: public Weapons {
public:
    HeavyWepons(int _power,int _numofshots);

    //HeavyWepons();

    const int getNumofshots() const;

protected:
    virtual void toString(std::ostream &os) const override =0;
private:
    const int numofshots;
};



#endif //WARGAME_HEAVYWEPONS_H
