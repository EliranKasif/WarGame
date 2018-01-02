//
// Created by eliran on 02/01/18.
//

#ifndef WARGAME_EQUALITYEXCEPTION_H
#define WARGAME_EQUALITYEXCEPTION_H


#include <string>
#include "MyException.h"

class equalityException: public MyException {
private:
    const int numof;
    std::string wheretheproblem;
public:
    equalityException(const int numof);

public:
    const char *what() const noexcept override;
};


#endif //WARGAME_EQUALITYEXCEPTION_H
