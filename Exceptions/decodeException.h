//
// Created by eliran on 02/01/18.
//

#ifndef WARGAME_DECODEEXCEPTION_H
#define WARGAME_DECODEEXCEPTION_H


#include <string>
#include "MyException.h"

class decodeException: public MyException {

public:
    const char *what() const noexcept override;
};


#endif //WARGAME_DECODEEXCEPTION_H
