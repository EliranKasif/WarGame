//
// Created by eliran on 02/01/18.
//

#ifndef WARGAME_MYEXCEPTION_H
#define WARGAME_MYEXCEPTION_H


#include <exception>

class MyException: public std::exception {
public:

    const char *what() const noexcept override;
};



#endif //WARGAME_MYEXCEPTION_H
