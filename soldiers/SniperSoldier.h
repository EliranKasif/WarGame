//
// Created by eliran on 19/12/17.
//

#ifndef WARGAME_SNIPERSOLDIER_H
#define WARGAME_SNIPERSOLDIER_H


#include "Soldiers.h"
#include "../items/collectible/weapons/Weapons.h"


class SniperSoldier: public Soldiers {

public:

    /*
     * @brief Constructor
     * @param int
     * @param Weapons
     */
    SniperSoldier(int _id,Weapons* _weapon);

    /*
     * @brief default Constructor
     */
    SniperSoldier()= default;

    /*
     * @brief virtual Destructor
     */
    virtual ~SniperSoldier();

    /*
     * @brief get soldier Weapons
     * @return Weapons *
     */
    Weapons *getWeapon() const;

    /*
     * @brief set soldier Weapons
     * @param Weapons *
     * @return void
     */
    void setWeapon(Weapons *weapon);

    /*
     *
     */
    Weapons* Action(Weapons *weapon) override;

    /*
     * @brief choose a soldier to attack and attack him
     * @param std::list<Soldiers*>&
     * @param std::ofstream&
     */
    virtual void Attack(std::list<Soldiers*>& list,std::ofstream& ss  ) override;

private:
    Weapons* weapon;

    /*
     * @brief virtual func for specific print of SniperSoldier
     * @param ostream &
     * @return void
     */
    virtual void toString(std::ostream &os) const;


};



#endif //WARGAME_SNIPERSOLDIER_H
