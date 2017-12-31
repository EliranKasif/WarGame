//
// Created by eliran on 18/12/17.
//

#ifndef WARGAME_BODYARMOR_H
#define WARGAME_BODYARMOR_H


#include "Armors.h"
class BodyArmor: public Armors {
public:
    /*
     * @brief Constructor
     * @param double armor level
     */
    BodyArmor(double _levelarmor);

    /*
     * @brief default Constructor
     */
    BodyArmor()= default;
    /*
     * @brief virtual Destructor
     */
    virtual ~BodyArmor();

private:
    /*
     * @specific print of BodyArmor
     * @param ostream &
     * @return void
     */
    void toString(std::ostream &os) const override;

};


#endif //WARGAME_BODYARMOR_H
