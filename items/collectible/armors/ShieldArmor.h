//
// Created by eliran on 18/12/17.
//

#ifndef WARGAME_SHIELDARMOR_H
#define WARGAME_SHIELDARMOR_H


#include "Armors.h"

class ShieldArmor: public Armors {
public:
    /*
     * @brief Constructor
     * @param double armor level
     */
    ShieldArmor(double _levelarmor);

    /*
     * @brief default Constructor
     */
    ShieldArmor()= default;

    /*
      * @brief virtual Destructor
      */
    virtual ~ShieldArmor();
    /*
    * @brief virtual func for know which type is
    * @return typeofObject (enum)
    */
    virtual typeofObject whoami();

private:
    /*
     * @specific print of BodyArmor
     * @param ostream &
     * @return void
     */
    void toString(std::ostream &os) const override;


};


#endif //WARGAME_SHIELDARMOR_H
