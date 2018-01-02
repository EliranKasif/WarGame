//
// Created by eliran on 19/12/17.
//

#ifndef WARGAME_HEALERSOLDIER_H
#define WARGAME_HEALERSOLDIER_H


#include "Soldiers.h"

class HealerSoldier: public Soldiers {

public:

    /*
     * @brief Constructor
     * @param int id
     */
    HealerSoldier(int _id);

    /*
     * @brief default Constructor
     */
    HealerSoldier()= default;

    /*
     * @brief virtual Destructor
     */
    virtual ~HealerSoldier();

    /*
     * @brief Action
     * @param Weapons*
     * @return Weapons*
     */
    Weapons* Action(Weapons *weapon) override;

    /*
     * @brief check if can heal and if cant choose a soldier to attack and attack him
     * @param std::list<Soldiers*>&
     * @param std::ofstream&
     */
    virtual void Attack(std::list<Soldiers*>& list,std::ofstream& ss ) override;


private:
    /*
     * @brief virtual func for specific print of HealerSoldier
     * @param ostream &
     * @return void
     */
    virtual void toString(std::ostream &os) const;
};


#endif //WARGAME_HEALERSOLDIER_H
