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

    /*
     * @brief virtual func for specific print of ComputerStrategy
     * @param ostream &
     * @return void
     */
    virtual void toString(std::ostream &os)const override ;


public:

    /*
     * @brief Constructor
     * @param const int numOfSoldiers
     * @param const int height of the arena
     * @param const int width of the arena
     */
    ComputerStrategy(const int numOfSoldiers, const int height, const int width);

    /*
     * @brief default Constructor
     */
    ComputerStrategy();

    /*
     * @brief virtual func that implement ComputerStrategy
     * @return void
     */
    virtual void implementStrategy() override;

    /*
     * @brief virtual Destructor
     */
    virtual ~ComputerStrategy();
};


#endif //UNTITLED_COMPUTERSTRATEGY_H