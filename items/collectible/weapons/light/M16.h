//Missile
// Created by eliran on 18/12/17.
//

#ifndef WARGAME_M16_H
#define WARGAME_M16_H


#include "LightWeapons.h"

class M16: public LightWeapons {
public:
    /*
     * @brief default Constructor
     */
    M16();

    /*
     * @brief virtual Destructor
     */
    virtual ~M16();

private:
    /*
     * @brief specific print for M16
     * @param ostream &
     * @return void
     */
   virtual void toString(std::ostream &os) const override;

};


#endif //WARGAME_M16_H
