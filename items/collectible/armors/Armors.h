//
// Created by eliran on 18/12/17.
//

#ifndef WARGAME_ARMORS_H
#define WARGAME_ARMORS_H


#include "../CollectibleItems.h"

class Armors: public CollectibleItems {

public:
    Armors(double _armorlevel);

    Armors();

    const double getLevelarmor() const;

protected:
    virtual void toString(std::ostream &os) const override =0;

private:
    const double levelarmor;

};


#endif //WARGAME_ARMORS_H
