//
// Created by eliran on 02/01/18.
//

#ifndef WARGAME_READFROMUSER_H
#define WARGAME_READFROMUSER_H


#include "../Data/Decoder.h"
#include "InitCSV.h"
#include "../Exceptions/argumentException.h"

class ReadFromuser {
public:
    Decoder *getBuffer() const;
    const std::list<FileControler *> &getFiletoplayers() const;
    void readArgv(int argc, char **argv) throw (decodeException,argumentException,numofplayerException,numofSoldiersException);
    virtual ~ReadFromuser();

private:
    Decoder* buffer;
    std::list<FileControler*> filetoplayers;

};


#endif //WARGAME_READFROMUSER_H
