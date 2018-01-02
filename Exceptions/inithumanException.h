//
// Created by eliran on 02/01/18.
//

#ifndef WARGAME_INITHUMANEXCEPTION_H
#define WARGAME_INITHUMANEXCEPTION_H


#include "MyException.h"

class inithumanException: public MyException {
public:
    const char *what() const noexcept override;

};




#endif //WARGAME_INITHUMANEXCEPTION_H
