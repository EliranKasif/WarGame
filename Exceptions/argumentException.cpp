//
// Created by eliran on 02/01/18.
//

#include "argumentException.h"


const char *argumentException::what() const noexcept {
    return "Missing user argument from the command line\n You should run the program like:\n"
            "./WarGame init_file_example.csv player1_file_example.csv \n"
            "You need to be sure that the number of the files for Humans players is\n"
            "the same number of the human player in the init game file\n"
            "(Put the csv files in the same directory)";
}