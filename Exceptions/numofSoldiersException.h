//
// Created by eliran on 02/01/18.
//

#ifndef WARGAME_NUMOFSOLDIERSEXCEPTION_H
#define WARGAME_NUMOFSOLDIERSEXCEPTION_H


#include "MyException.h"

class numofSoldiersException: public MyException {

public:
    const char *what() const noexcept override;
};


#endif //WARGAME_NUMOFSOLDIERSEXCEPTION_H
