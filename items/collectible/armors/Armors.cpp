//
// Created by eliran on 18/12/17.
//

#include "Armors.h"

Armors::Armors(double _levelarmor)
        :levelarmor(_levelarmor){}

Armors::Armors():CollectibleItems(),levelarmor(ZERO){}

const double Armors::getLevelarmor() const {
    return levelarmor;
}

void Armors::toString(std::ostream &os) const{
    os<<"level Armor: "<<levelarmor<<", " ;
}

 typeofObject Armors::whoami(){
     return typeofObject ::ARMOR;
 }


Armors::~Armors() {

}


