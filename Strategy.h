//
// Created by noysi on 23-Dec-17.
//

#ifndef UNTITLED_STRATEGY_H
#define UNTITLED_STRATEGY_H


#include <vector>
#include <list>
#include "Point2d.h"

class Strategy {
private:
    const int numOfSoldiers;
    const double height;
    const  double width;

protected:
    std::vector<std::list<Point2d>> destination;
public:


    Strategy(const int numOfSoldiers, const double width, const double Height);

    Strategy();

    virtual ~Strategy();

    const double getHeight() const;

    const double getWidth() const;

    virtual void implementStrategy()=0;

    int getNumOfSoldiers() const;

    const std::vector<std::list<Point2d>> &getDestination() const;
};


#endif //UNTITLED_STRATEGY_H