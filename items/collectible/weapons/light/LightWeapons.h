//
// Created by eliran on 18/12/17.
//

#ifndef WARGAME_LIGHTWEAPONS_H
#define WARGAME_LIGHTWEAPONS_H


#include "../Weapons.h"


class LightWeapons: public Weapons {
public:
    /*
     * @brief Constructor
     * @param const int power
     * @param const int num of shots
     */
    LightWeapons(int _power,int _numofshots);

    /*
     * @brief default Constructor
     */
    LightWeapons();

    /*
     * @brief virtual Destructor
     */
    virtual ~LightWeapons();

protected:
    /*
     * @brief pure virtual func for specific print of the derived classes
     * @param ostream &
     * @return void
     */
    virtual void toString(std::ostream &os) const override =0;

};


#endif //WARGAME_LIGHTWEAPONS_H
