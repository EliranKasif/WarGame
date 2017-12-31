//
// Created by eliran on 18/12/17.
//

#ifndef WARGAME_UZI_H
#define WARGAME_UZI_H


#include "LightWeapons.h"

class Uzi: public LightWeapons {
public:
    /*
     * @brief default Constructor
     */
    Uzi();
    /*
     * @brief virtual Destructor
     */
    virtual ~Uzi();

private:
    /*
     * @brief specific print for Uzi
     * @param ostream &
     * @return void
     */
    virtual void toString(std::ostream &os) const override;

};


#endif //WARGAME_UZI_H
