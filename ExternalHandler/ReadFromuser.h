//
// Created by eliran on 02/01/18.
//

#ifndef WARGAME_READFROMUSER_H
#define WARGAME_READFROMUSER_H

#include "InitCSV.h"
#include "../Exceptions/argumentException.h"
#include "Reader.h"

class ReadFromuser: public Reader {
public:
    void readArgv(int argc, char **argv) throw (decodeException,argumentException,numofplayerException,numofSoldiersException);
    virtual ~ReadFromuser();



};


#endif //WARGAME_READFROMUSER_H
