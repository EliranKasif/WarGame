//
// Created by eliran on 02/01/18.
//

#include "inithumanException.h"

const char *inithumanException::what() const noexcept {
    return "You need to fix your init file \nYour file should look like(for 3 Soldiers) :\n"
            "Player\n"
            "[10 10],[15 18],[0 1],[0 0],[2 -2]\n"
            "[20 16]\n"
            "[20 16]";

}