//
// Created by noysi on 26-Dec-17.
//

#ifndef WAR_ENVIRONMENT_H
#define WAR_ENVIRONMENT_H


#include <vector>
#include <list>
#include <ostream>
#include <iostream>
#include "../items/Items.h"
#include "../soldiers/Soldiers.h"

class Environment {

private:
    size_t wSize,hSize;
    std::vector<std::vector<std::list<Items*>>> itemsEnviroment;
    std::vector<std::vector<std::list<Soldiers*>>> SolidersEnviroment;


public:
    /*
     * @brief default Constructor
     */
    Environment();

    /*
     * @brief virtual Destructor
     */
    ~Environment();

    /*
     * @brief reSize environment by the data
     * @return void
     */
    void reSizeArena();

    /*
     * @brief get width size of the environment
     * @return size_t
     */
    size_t getWSize() const;

    /*
     * @brief set width size of the environment
     * @param size_t
     * @return void
     */
    void setWSize(size_t wSize);

    /*
     * @brief get height size of the environment
     * @return size_t
     */
    size_t getHSize() const;

    /*
     * @brief set height size of the environment
     * @param size_t
     * @return void
     */
    void setHSize(size_t hSize);

    /*
     * @brief add Soldier to the right place in the environment
     * @param size_t
     * @param size_t
     * @param Soldiers*
     * @return void
     */
    void addSoldier(size_t i,size_t j,Soldiers* soldier);

    /*
     * @brief remove Soldier from the right place in the environment
     * @param size_t
     * @param size_t
     * @param Soldiers*
     * @return void
     */
    void removeSoldier(size_t i,size_t j,Soldiers* solidier);

    /*
     * @brief add Item to the right place in the environment
     * @param size_t
     * @param size_t
     * @param Items&
     * @return void
     */
    void addItem(size_t i,size_t j,Items& item);

    /*
     * @brief remove item from the right place in the environment
     * @param size_t
     * @param size_t
     * @param Items&
     * @return void
     */
    void removeIteam(size_t i,size_t j,Items& item);

    /*
     * @brief check if there is solid in a given Point2d
     * @param Point2d
     * @return void
     */
    bool ifsolid(Point2d point);

    /*
     * @brief get Soldiers in the environment
     * @param size_t
     * @param size_t
     * @return std::list<Soldiers*>&
     */
    std::list<Soldiers*>& getSoldiersinArena(size_t i,size_t j);

    /*
     * @brief get Items in the environment
     * @param size_t
     * @param size_t
     * @return std::list<Items*>&
     */
    std::list<Items*>& getItemsinArena(size_t i,size_t j);

    /*
     * @brief override operator<<
     * @param os - ostream& to return the stream
     * @param const Environment & the object we want to print
     * @return ostream
     */
    friend std::ostream &operator<<(std::ostream &os, const Environment &environment);
};


#endif //WAR_ENVIRONMENT_H