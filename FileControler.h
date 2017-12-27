//
// Created by eliran on 24/12/17.
//

#ifndef WARGAME_FILECONTROLER_H
#define WARGAME_FILECONTROLER_H


#include <fstream>

class FileControler {
public:
    virtual std::ifstream* read()=0;
    FileControler();
    virtual ~FileControler();


};


#endif //WARGAME_FILECONTROLER_H
