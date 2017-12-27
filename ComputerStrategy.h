//
// Created by noysi on 23-Dec-17.
//

#ifndef UNTITLED_COMPUTERSTRATEGY_H
#define UNTITLED_COMPUTERSTRATEGY_H

#include "Strategy.h"

class ComputerStrategy: public Strategy {
private:
    const int numOfSoldiers;
    const double height;
    const  double width;
    virtual void toString(std::ostream &os)const override ;


public:

    ComputerStrategy(const int numOfSoldiers, const int height, const int width);

    ComputerStrategy();

    virtual void implementStrategy() override;

    virtual ~ComputerStrategy();
};


#endif //UNTITLED_COMPUTERSTRATEGY_H