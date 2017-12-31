//
// Created by eliran on 18/12/17.
//

#ifndef WARGAME_MISSILE_H
#define WARGAME_MISSILE_H


#include "HeavyWeapons.h"

class Missile: public HeavyWepons {
public:
    /*
     * @brief default Constructor
     */
    Missile();

    /*
     * @brief virtual Destructor
     */
    virtual ~Missile();

private:
    /*
    * @brief specific print for Missile
    * @param ostream &
    * @return void
    */
    virtual void toString(std::ostream &os) const override;


};


#endif //WARGAME_MISSILE_H
