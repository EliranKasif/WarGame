//
// Created by eliran on 18/12/17.
//

#ifndef WARGAME_NOTCOLLECTIBLEITEMS_H
#define WARGAME_NOTCOLLECTIBLEITEMS_H


#include <ostream>
#include "../Items.h"

class NotCollectibleItems: public Items {
public:
    /*
     * @brief Constructor
     * @param double width
     * @param double height
     */
    NotCollectibleItems(double width, double height);

    /*
     * @brief default Constructor
     */
    NotCollectibleItems();

    /*
     * @brief virtual Destructor
     */
    virtual ~NotCollectibleItems();

    /*
     * @brief get the width of a not Collectible item
     * @return double
     */
    const double getWidth() const;

    /*
     * @brief get the height of a not Collectible item
     * @return double
     */
    const double getHeight() const;

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



private:
    const double width,height;

};


#endif //WARGAME_NOTCOLLECTIBLEITEMS_H
