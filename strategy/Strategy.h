//
// Created by noysi on 23-Dec-17.
//

#ifndef UNTITLED_STRATEGY_H
#define UNTITLED_STRATEGY_H


#include <vector>
#include <list>
#include <ostream>
#include "../Point2d.h"

class Strategy {
public:
    friend std::ostream &operator<<(std::ostream &os, const Strategy &strategy);

protected:
    std::vector<std::list<Point2d>> destination;

public:

    Strategy();

    virtual ~Strategy();

    virtual void implementStrategy()=0;

    const std::vector<std::list<Point2d>> &getDestination() const;
    virtual void toString(std::ostream &os)const =0;
};


#endif //UNTITLED_STRATEGY_H