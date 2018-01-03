//
// Created by noysi on 23-Dec-17.
//

#ifndef UNTITLED_STRATEGY_H
#define UNTITLED_STRATEGY_H


#include <vector>
#include <list>
#include <ostream>
#include "../game/Point2d.h"

class Strategy {

protected:
    std::vector<std::list<Point2d>> destination;

public:

    /*
     * @brief default Constructor
     */
    Strategy();

    /*
     * @brief virtual Destructor
     */
    virtual ~Strategy();

    /*
     * @brief pure virtual func that implement the Strategy
     * after we know the specific type
     * @return void
     */
    virtual void implementStrategy()=0;

    /*
     * @brief get destination a vector of lists with the points the soliders need to go to
     * @return const std::vector<std::list<Point2d>>
     */
    const std::vector<std::list<Point2d>> &getDestination() const;

    /*
     * @brief pure virtual func for specific print of the derived classes
     * @param ostream &
     * @return void
     */
    virtual void toString(std::ostream &os)const =0;

    /*
     * @brief override operator<<
     * @param os - ostream& to return the stream
     * @param const Strategy & the object we want to print
     * @return ostream
     */
    friend std::ostream &operator<<(std::ostream &os, const Strategy &strategy);
};


#endif //UNTITLED_STRATEGY_H