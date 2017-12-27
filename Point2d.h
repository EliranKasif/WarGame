//
// Created by eliran on 18/12/17.
//

#ifndef WARGAME_POINT2D_H
#define WARGAME_POINT2D_H

#include <ostream>
#include "DefaultDefines.h"

class Point2d {

public:
    Point2d(double x, double y);
    Point2d(const Point2d& p):x(p.getX()),y(p.getY()){}

    Point2d();

    double getX() const;

    double getY() const;


    void setX(double x);

    void setY(double y);



    /*
    Point2d(double _x,double _y):x(_x),y(_y){}
    Point2d(const Point2d& p):x(p.getX()),y(p.getY()){}
    Point2d():x(DEFAULT_LOCATION),y(DEFAULT_LOCATION){}
    double getX() const {return x;}
    double getY() const {return y;}
    void setX(double _x){x=_x;}
    void setY(double _y){y=_y;}
     */
    friend std::ostream &operator<<(std::ostream &os, const Point2d &d);

private:
    double x,y;

};


#endif //WARGAME_POINT2D_H
