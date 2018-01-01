//
// Created by eliran on 18/12/17.
//

#ifndef WARGAME_ITEMS_H
#define WARGAME_ITEMS_H


#include <ostream>
#include "../Point2d.h"
#include "../DefaultDefines.h"

enum class typeofObject:int
{COLLECTIBLE,NOTCOLLECTIBLE,ARMOR,WEAPON,HEAVY,LIGHT,BODYARMOR,SHEILDARMOR};

class Items {

public:
    /*
     * @brief default ctor
     */
    Items();

    /*
     * @brief virtual Destructor
     */
    virtual ~Items();

   /*
    * @brief get item location on the game
    * @return const Point2D
    */
    const Point2d &getLocation() const;

    /*
     * @brief set the location of an item on the game
     * @param const Point2d &
     * @return void
     */
    void setLocation(const Point2d &location);

    /*
     * @brief override operator<<
     * @param os - ostream& to return the stream
     * @param const Items& the object we want to print
     * @return ostream
     */
    friend std::ostream &operator<<(std::ostream &os, const Items &items);

    /*
    * @brief virtual func for know which type is
    * @return typeofObject (enum)
    */
    virtual typeofObject whoami()=0;

protected:
    /*
     * @brief pure virtual func for specific print of the derived classes
     * @param ostream &
     * @return void
     */
    virtual void toString(std::ostream &os) const =0;




private:
    Point2d itemLocation;

};

#endif //WARGAME_ITEMS_H
