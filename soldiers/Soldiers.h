//
// Created by eliran on 19/12/17.
//

#ifndef WARGAME_SOLDIERS_H
#define WARGAME_SOLDIERS_H


#include <ostream>
#include "../Point2d.h"
#include "../DefaultDefines.h"
#include "../items/collectible/armors/Armors.h"
#include "../items/collectible/weapons/Weapons.h"
#include <list>
class Soldiers: public Destroyer  {

private:
    const int id;
    int life;
    const int defaultlife;
    const int speed;
    Point2d soldierLocation;
    Armors* armors[2];
    bool switched=false;
    bool canmove=true;

public:

    /*
     * @brief Constructor
     * @param int id
     * @param int life
     * @param speed
     */
    Soldiers(int _id,int _life,int _speed);

    /*
     * @brief default Constructor
     */
    Soldiers();

    /*
     * @brief virtual Destructor
     */
    virtual ~Soldiers();

    /*
     * @brief get Soldier Default life
     * @return const int
     */
    const int getDefaultlife() const;

    /*
     * @brief pure virtual func for action (replace weapon)
     * @return Weapons*
     */
    virtual Weapons* Action(Weapons* )=0;

    /*
     * @brief pure virtual func for attack
     * @return void
     */
    virtual void Attack(std::list<Soldiers*>& list,std::ofstream& ss )=0;

    /*
     * @brief get Soldier life
     * @return int
     */
    int getLife() const;

    /*
     * @brief set Soldier life
     * @return void
     */
    void setLife(int life);

    /*
     * @brief get the location of a soldier on the game
     * @return const Point2d &
     */
    const Point2d &getSoldierLocation() const;

    /*
     * @brief set the location of a soldier on the game
     * @param const Point2d &
     * @return void
     */
    void setSoldierLocation(const Point2d &soldierLocation);

    /*
     * @brief get soldier Speed
     * @return const int
     */
    const int getSpeed() const;

    /*
     * @brief get soldier Id
     * @return const int
     */
    const int getId() const;

    /*
     * @brief get soldier Armors
     * @return Armors *
     */
    Armors *const *getArmors() const;

    /*
     * @brief set soldier Armors
     * @param Armors*
     * @return Armors*
     */
    Armors* setArmors(Armors* armor);

    /*
     * @brief check if the soldier can step to a given point and return the point he can go to
     * @param const Point2d&
     * @return Point2d
     */
    virtual Point2d checkifcanstep(const Point2d& point);

    /*
     * @brief generate a random num
     * @return int
     */
    int random();

    /*
     * @brief check if the soldier can move
     * @return bool
     */
    bool isCanmove() const;

    /*
     * @brief set Canmove if the soldier cant move
     */
    void setCanmove(bool canmove);

    /*
     * @brief override operator<<
     * @param os - ostream& to return the stream
     * @param const Soldiers & the object we want to print
     * @return ostream
     */
    friend std::ostream &operator<<(std::ostream &os, const Soldiers &soldiers);


protected:
  /*
   * @brief pure virtual func for specific print of the derived classes
   * @param ostream &
   * @return void
   */
    virtual void toString(std::ostream &os) const =0;


};


#endif //WARGAME_SOLDIERS_H
