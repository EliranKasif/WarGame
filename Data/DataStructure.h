//
// Created by eliran on 24/12/17.
//

#ifndef WARGAME_DATASTRUCTURE_H
#define WARGAME_DATASTRUCTURE_H


#include <ostream>
#include "../items/Items.h"
#include "../ExternalHandler/ReadFromuser.h"
#include "BuildArena.h"

class DataStructure {
public:
    /*
     * @brief get data
     * @return InitObject*
     */
    InitObject* getData() ;

    /*
     * @brief get Arena
     * @return Environment&
     */
    Environment& getArena() ;

    /*
     * @brief override operator<<
     * @param os - ostream& to return the stream
     * @param const DataStructure & the object we want to print
     * @return ostream
     */

    friend std::ostream &operator<<(std::ostream &os, const DataStructure &structure);

    /*
    * @brief build get the num of files and files names from the command line.
    * and build init object and Environment from init object
    * @param int
    * @param char*
    */
    void build(const ReadFromuser& design);

private:
    InitObject data;
    Environment arena;
};


#endif //WARGAME_DATASTRUCTURE_H
