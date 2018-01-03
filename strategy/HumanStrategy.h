//
// Created by noysi on 23-Dec-17.
//

#ifndef UNTITLED_HUMANSTRATEGY_H
#define UNTITLED_HUMANSTRATEGY_H


#include "Strategy.h"
#include "../ExternalHandler/FileControler.h"
#include "../Exceptions/inithumanException.h"
#include "../Exceptions/equalityException.h"

class HumanStrategy : public Strategy{
private:
    FileControler* fileControler;
    const int numOfSoldiers;

    /*
     * @brief split strings by delim and insert into list
     * @param std::string& to split
     * @char to spit by it
     * @std::list<Point2d> & to insert to substrings
     * @return void
     */
    void split(std::string& s,char delim,std::list<Point2d> &list) throw(inithumanException);

    /*
     * @brief virtual func for specific print of HumanStrategy
     * @param ostream &
     * @return void
     */
    virtual void toString(std::ostream &os)const override ;


public:

    /*
     * @brief default Constructor
     * @FileControler*
     * @const int
     */
    HumanStrategy(FileControler*,const int numOfSoldiers);

    /*
     * @brief virtual func that implement HumanStrategy
     * @return void
     */
    virtual void implementStrategy() throw(inithumanException,equalityException) override;

    /*
     * @brief virtual Destructor
     */
    virtual ~HumanStrategy();

    /*
     * @brief set FileControler
     * @param FileControler*
     * @return void
     */
    void setFileControler(FileControler *fileControler);
};


#endif //UNTITLED_HUMANSTRATEGY_H