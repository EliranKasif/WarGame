//
// Created by eliran on 02/01/18.
//

#ifndef WARGAME_ARGUMENTEXCEPTION_H
#define WARGAME_ARGUMENTEXCEPTION_H


#include "MyException.h"

class argumentException: public MyException {
public:
    const char *what() const noexcept override;


};



#endif //WARGAME_ARGUMENTEXCEPTION_H
