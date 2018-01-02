//
// Created by eliran on 02/01/18.
//

#ifndef WARGAME_NUMOFPLAYEREXCEPTION_H
#define WARGAME_NUMOFPLAYEREXCEPTION_H


#include "MyException.h"

class numofplayerException : public MyException{
public:
    const char *what() const noexcept override;


};



#endif //WARGAME_NUMOFPLAYEREXCEPTION_H
