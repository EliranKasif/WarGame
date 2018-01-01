//
// Created by eliran on 18/12/17.
//

#ifndef WARGAME_HEAVYWEPONS_H
#define WARGAME_HEAVYWEPONS_H


#include "../Weapons.h"

class HeavyWepons: public Weapons {
public:
    /*
     * @brief Constructor
     * @param const int power
     * @param const int num of shots
     */
    HeavyWepons(int _power,int _numofshots);
    /*
     * @brief default Constructor
     */
    HeavyWepons();

    /*
     * @brief virtual Destructor
     */
    virtual ~HeavyWepons();

    /*
    * @brief virtual func for know which type is
    * @return typeofObject (enum)
    */
    virtual typeofObject whoami();
protected:
    /*
     * @brief pure virtual func for specific print of the derived classes
     * @param ostream &
     * @return void
     */
    virtual void toString(std::ostream &os) const override =0;



};



#endif //WARGAME_HEAVYWEPONS_H
