//
// Created by eliran on 02/01/18.
//

#include <cstring>
#include "decodeException.h"


const char *decodeException::what() const noexcept {
   return "You need to fix your init file \nYour file should look like :\n"
            "Game\n"
            "battlefieldSize,100,200\n"
            "players,2\n"
            "soldiers,3\n"
            "p1,human\n"
            "normal,[2 3],M16\n"
            "paramedic,[10 31]\n"
            "sniper,[5 12],UZI\n"
            "p2,computer,0\n"
            "normal,[90 112],Missile\n"
            "sniper,[90 113],M16\n"
            "normal,[65 100],M16\n"
            "Objects\n"
            "weapon,M16,[5 5]\n"
            "Armor,BodyArmor,0.8,[1 2]\n"
            "weapon,Missile,[15 115]\n"
            "solid,Tree,4,4,[20 20]";

}
