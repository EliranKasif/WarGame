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
class Soldiers {

private:
    const int id;
    int life;
    const int defaultlife;
    const int speed;
    Point2d soldierLocation;
    Armors* armors[2];
    bool switched=false;
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
     * @brief set the location of a soldier on the game
     * @param const Point2d &
     * @return void
     */
    const Point2d &getSoldierLocation() const;

    void setSoldierLocation(const Point2d &soldierLocation);

    const int getSpeed() const;

    const int getId() const;

    friend std::ostream &operator<<(std::ostream &os, const Soldiers &soldiers);

    Armors *const *getArmors() const;

    Armors* setArmors(Armors* armor);

    virtual Point2d checkifcanstep(const Point2d& point);

    int random();

protected:
    /*
   * @brief pure virtual func for specific print of the derived classes
   * @param ostream &
   * @return void
   */
    virtual void toString(std::ostream &os) const =0;


};


#endif //WARGAME_SOLDIERS_H
