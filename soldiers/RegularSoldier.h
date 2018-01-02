//
// Created by eliran on 19/12/17.
//

#ifndef WARGAME_REGULARSOLDIER_H
#define WARGAME_REGULARSOLDIER_H
#include "Soldiers.h"
#include "../items/collectible/weapons/Weapons.h"

class RegularSoldier : public Soldiers{

public:

    /*
     * @brief default Constructor
     */
    RegularSoldier()= default;

    /*
     * @brief Constructor
     * @param int
     * @param Weapons
     */
    RegularSoldier(int _id,Weapons* weapon);

    /*
     * @brief virtual Destructor
     */
    virtual ~RegularSoldier();

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
     * @brief Action
     * @param Weapons*
     * @return Weapons*
     */
    Weapons* Action(Weapons *weapon ) override;

    /*
     * @brief check if the soldier can step to a given point and return the point he can go to
     * @param const Point2d&
     * @return Point2d
     */
    virtual Point2d checkifcanstep(const Point2d& point);

    /*
     * @brief choose a soldier to attack and attack him
     * @param std::list<Soldiers*>&
     * @param std::ofstream&
     */
    virtual void Attack(std::list<Soldiers*>& list,std::ofstream& ss  ) override;


private:
    Weapons* weapon;

    /*
     * @brief virtual func for specific print of RegularSoldier
     * @param ostream &
     * @return void
     */
    virtual void toString(std::ostream &os) const;

};




#endif //WARGAME_REGULARSOLDIER_H
