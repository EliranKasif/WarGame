//
// Created by eliran on 18/12/17.
//

#ifndef WARGAME_COLLECTIBLEITEMS_H
#define WARGAME_COLLECTIBLEITEMS_H


#include "../Items.h"

class CollectibleItems: public Items {

public:
    /*
     * @brief default Constructor
     */
    CollectibleItems()= default;

    /*
     * @brief virtual Destructor
     */
    virtual ~CollectibleItems();

    /*
    * @brief virtual func for know which type is
    * @return typeofObject (enum)
    */
    virtual typeofObject whoami();

private:
    /*
     * @brief pure virtual func for specific print of the derived classes
     * @param ostream &
     * @return void
     */
    void toString(std::ostream &os) const override =0;


};

#endif //WARGAME_COLLECTIBLEITEMS_H
