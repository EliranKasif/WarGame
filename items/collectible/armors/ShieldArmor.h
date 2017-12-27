//
// Created by eliran on 18/12/17.
//

#ifndef WARGAME_SHIELDARMOR_H
#define WARGAME_SHIELDARMOR_H


#include "Armors.h"

class ShieldArmor: public Armors {
public:
    ShieldArmor(double _levelarmor);
    ShieldArmor()= default;

private:
    void toString(std::ostream &os) const override;


};


#endif //WARGAME_SHIELDARMOR_H
