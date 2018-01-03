//
// Created by eliran on 03/01/18.
//

#ifndef WARGAME_READER_H
#define WARGAME_READER_H

#include "../Data/Decoder.h"
class Reader {
protected:
    Decoder* buffer;
    std::list<FileControler*> filetoplayers;
public:
    Decoder *getBuffer() const;
    const std::list<FileControler *> &getFiletoplayers() const;
    virtual void readArgv(int argc, char **argv)=0;
    virtual ~Reader();
};


#endif //WARGAME_READER_H
