//
// Created by eliran on 18/12/17.
//

#ifndef WARGAME_COLLECTIBLEITEMS_H
#define WARGAME_COLLECTIBLEITEMS_H


#include "../Items.h"

class CollectibleItems: public Items {

public:
    CollectibleItems()= default;
private:
    void toString(std::ostream &os) const override =0;
};


#endif //WARGAME_COLLECTIBLEITEMS_H
