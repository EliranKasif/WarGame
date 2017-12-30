//
// Created by eliran on 18/12/17.
//

#ifndef WARGAME_WEAPONS_H
#define WARGAME_WEAPONS_H


#include "../CollectibleItems.h"

class Weapons: public CollectibleItems {

public:

    Weapons(const int power,const int _numofshots);

    Weapons();

    virtual ~Weapons();

    const int getPower() const;

    const int getNumofshots() const;


protected:
    virtual void toString(std::ostream &os) const override =0;

private:
    const int power;
    const int numofshots;


};


#endif //WARGAME_WEAPONS_H
