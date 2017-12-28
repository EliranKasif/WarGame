//
// Created by noysi on 23-Dec-17.
//

#ifndef UNTITLED_HUMANSTRATEGY_H
#define UNTITLED_HUMANSTRATEGY_H


#include "Strategy.h"
#include "../FileControler.h"

class HumanStrategy : public Strategy{
private:
    FileControler* fileControler;
    void split(std::string& s,char delim,std::list<Point2d> &list);
    virtual void toString(std::ostream &os)const override ;


public:
    HumanStrategy(FileControler*);
    virtual void implementStrategy() override;
    virtual ~HumanStrategy();

    void setFileControler(FileControler *fileControler);
};


#endif //UNTITLED_HUMANSTRATEGY_H