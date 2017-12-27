//
// Created by eliran on 18/12/17.
//

#ifndef WARGAME_WEAPONS_H
#define WARGAME_WEAPONS_H


#include "../CollectibleItems.h"

class Weapons: public CollectibleItems {

public:

    Weapons(const int power);

  //  Weapons();

    const int getPower() const;


protected:
    virtual void toString(std::ostream &os) const override =0;

private:
    const int power;


};


#endif //WARGAME_WEAPONS_H
