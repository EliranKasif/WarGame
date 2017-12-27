//
// Created by noysi on 23-Dec-17.
//

#ifndef UNTITLED_COMPUTERSTRATEGY_H
#define UNTITLED_COMPUTERSTRATEGY_H

#include "Strategy.h"

class ComputerStrategy: public Strategy {
public:

    ComputerStrategy(const int numOfSoldiers, const int height, const int width);

    ComputerStrategy();

    virtual void implementStrategy() override;

    virtual ~ComputerStrategy();
};


#endif //UNTITLED_COMPUTERSTRATEGY_H