//
// Created by eliran on 18/12/17.
//

#ifndef WARGAME_WEAPONS_H
#define WARGAME_WEAPONS_H


#include "../CollectibleItems.h"

class Weapons: public CollectibleItems {

public:

    /*
     * @brief Constructor
     * @param const int power
     * @param const int num of shots
     */
    Weapons(const int power,const int _numofshots);

    /*
     * @brief default Constructor
     */
    Weapons();

    /*
     * @brief virtual Destructor
     */
    virtual ~Weapons();

    /*
     * @brief get the power of the weapon
     * @return const int
     */
    const int getPower() const;

    /*
     * @brief get the num of shots of the weapon
     * @return const int
     */
    const int getNumofshots() const;


protected:
    /*
     * @brief pure virtual func for specific print of the derived classes
     * @param ostream &
     * @return void
     */
    virtual void toString(std::ostream &os) const override =0;

private:
    const int power;
    const int numofshots;


};


#endif //WARGAME_WEAPONS_H
