//
// Created by eliran on 02/01/18.
//

#include "numofplayerException.h"

const char *numofplayerException::what()  const noexcept{
    return "Number of Players must be 2 to 4 Players!!!\n"
            "change it in the init file";
}
