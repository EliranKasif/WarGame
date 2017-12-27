//
// Created by eliran on 18/12/17.
//

#ifndef WARGAME_NOTCOLLECTIBLEITEMS_H
#define WARGAME_NOTCOLLECTIBLEITEMS_H


#include <ostream>
#include "../Items.h"

class NotCollectibleItems: public Items {
public:
    NotCollectibleItems(double width, double height);
    NotCollectibleItems();

    const double getWidth() const;

    const double getHeight() const;

protected:
    virtual void toString(std::ostream &os) const override =0;

private:
    const double width,height;

};


#endif //WARGAME_NOTCOLLECTIBLEITEMS_H

/*
 * #define  MIN_SIZE_NOT_COLLECTIBLE_ITEM 2
 * public:
    NotCollectibleItems(const Point2d& _location,double _width,double _height):Items(_location){
        if(_width<MIN_SIZE_NOT_COLLECTIBLE_ITEM || _height<MIN_SIZE_NOT_COLLECTIBLE_ITEM)
        {
            width=MIN_SIZE_NOT_COLLECTIBLE_ITEM;
            height=MIN_SIZE_NOT_COLLECTIBLE_ITEM;
        }
        else
        {
            width=_width;
            height=_height;
        }
    }
    NotCollectibleItems():Items(),width(MIN_SIZE_NOT_COLLECTIBLE_ITEM),height(MIN_SIZE_NOT_COLLECTIBLE_ITEM){}

 */