//
// Created by eliran on 02/01/18.
//

#include "MyException.h"


const char *MyException::what() const noexcept {
    return exception::what();
}
