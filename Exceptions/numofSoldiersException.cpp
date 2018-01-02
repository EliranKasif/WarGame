//
// Created by eliran on 02/01/18.
//

#include "numofSoldiersException.h"

const char *numofSoldiersException::what()  const noexcept{
    return "Number of Soldiers for each player is not equal\n"
            "Please fix the init file.";
}
