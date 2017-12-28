//
// Created by eliran on 18/12/17.
//

#include "BodyArmor.h"

BodyArmor::BodyArmor(double _levelarmor)
        :Armors(_levelarmor){}

void BodyArmor::toString(std::ostream &os) const{
    os << "Body Armor- ";
    Armors::toString(os);
}

BodyArmor::~BodyArmor() {

}
