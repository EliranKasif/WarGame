//
// Created by eliran on 18/12/17.
//

#ifndef WARGAME_ITEMS_H
#define WARGAME_ITEMS_H


#include <ostream>
#include "../Point2d.h"
#include "../DefaultDefines.h"

class Items {

public:

    Items();

    const Point2d &getLocation() const;

    void setLocation(const Point2d &location);

    friend std::ostream &operator<<(std::ostream &os, const Items &items);

protected:
    virtual void toString(std::ostream &os) const =0;


private:
    Point2d itemLocation;

};


//TO-DO: operator << and virtual toString()=0;

#endif //WARGAME_ITEMS_H
