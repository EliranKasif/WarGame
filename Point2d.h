//
// Created by eliran on 18/12/17.
//

#ifndef WARGAME_POINT2D_H
#define WARGAME_POINT2D_H

#include <ostream>
#include "DefaultDefines.h"

class Point2d {

public:
    /*
     * @brief Constructor
     * @param double x
     * @param double y
     */
    Point2d(double x, double y);

    /*
     * @brief copy ctor
     * @param const Point2d&
     * @return Point2d
     */
    Point2d(const Point2d& p):x(p.getX()),y(p.getY()){}

    /*
     * @brief default ctor
     */
    Point2d();

    /*
     * @brief get x
     * @return double
     */
    double getX() const;

    /*
     * @brief get y
     * @return double
     */
    double getY() const;

    /*
     * @brief set x
     * @param double
     * @return void
     */
    void setX(double x);

    /*
     * @brief set x
     * @param double
     * @return void
     */
    void setY(double y);

    /*
     * @brief operator==
     * @param const Point2d &
     * @return bool
     */
    bool operator==(const Point2d &rhs) const;
    /*
     * @brief operator!=
     * @param const Point2d &
     * @return bool
     */
    bool operator!=(const Point2d &rhs) const;

    /*
     * @brief override operator<<
     * @param os - ostream& to return the stream
     * @param const Point2d & the object we want to print
     * @return ostream
     */
    friend std::ostream &operator<<(std::ostream &os, const Point2d &d);

private:
    double x,y;

};


#endif //WARGAME_POINT2D_H
