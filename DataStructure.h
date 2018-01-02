//
// Created by eliran on 24/12/17.
//

#ifndef WARGAME_DATASTRUCTURE_H
#define WARGAME_DATASTRUCTURE_H


#include <ostream>
#include "items/Items.h"
#include "InitObject.h"
#include "Environment.h"
#include "Exceptions/argumentException.h"

class DataStructure {
public:

    /*
     * @brief default Constructor get the num of files and files names from the command line.
     * @param int
     * @param char
     */
    DataStructure(int argc, char *argv[]) throw(decodeException,argumentException,equalityException,numofplayerException,numofSoldiersException);

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

private:
    InitObject data;
    Environment arena;

    /*
     * @brief build get the num of files and files names from the command line.
     * and build init object and Environment from init object
     * @param int
     * @param char*
     */
    void build(int argc, char *argv[]) throw(decodeException,argumentException,equalityException,numofplayerException,numofSoldiersException);

};


#endif //WARGAME_DATASTRUCTURE_H
