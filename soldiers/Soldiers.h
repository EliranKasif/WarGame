//
// Created by eliran on 19/12/17.
//

#ifndef WARGAME_SOLDIERS_H
#define WARGAME_SOLDIERS_H


#include <ostream>
#include "../Point2d.h"
#include "../DefaultDefines.h"
#include "../items/collectible/armors/Armors.h"

class Soldiers {

public:
    Soldiers(int _id,int _life,int _speed);

    //default ctor
    Soldiers()= default;

    virtual void Action()=0;

    int getLife() const;

    void setLife(int life);

    const Point2d &getSoldierLocation() const;

    void setSoldierLocation(const Point2d &soldierLocation);

    const int getSpeed() const;

    const int getId() const;

    friend std::ostream &operator<<(std::ostream &os, const Soldiers &soldiers);

    Armors *const *getArmors() const;

protected:
    virtual void toString(std::ostream &os) const =0;
private:
    const int id;
    int life;
    const int speed;
    Point2d soldierLocation;
    Armors* armors[2];


};


#endif //WARGAME_SOLDIERS_H
