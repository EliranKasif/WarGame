//
// Created by eliran on 18/12/17.
//

#include "ShieldArmor.h"

ShieldArmor::ShieldArmor(double _levelarmor)
        :Armors(_levelarmor){}

void ShieldArmor::toString(std::ostream &os) const{
    os << "Shield Armor- ";
    Armors::toString(os);
}

ShieldArmor::~ShieldArmor() {

}
