//
// Created by eliran on 18/12/17.
//

#ifndef WARGAME_BODYARMOR_H
#define WARGAME_BODYARMOR_H


#include "Armors.h"
class BodyArmor: public Armors {
public:
    BodyArmor(double _levelarmor);

    BodyArmor()= default;

private:
    void toString(std::ostream &os) const override;

};


#endif //WARGAME_BODYARMOR_H
