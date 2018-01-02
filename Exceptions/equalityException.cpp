//
// Created by eliran on 02/01/18.
//

#include "equalityException.h"

const char *equalityException::what() const noexcept {
    return "Ambiguous number of Players or Soldiers in init files";
}

equalityException::equalityException(const int numof)
        : numof(numof) {}
