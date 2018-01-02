//
// Created by eliran on 24/12/17.
//

#include <iostream>
#include "InitCSV.h"

InitCSV::InitCSV(const std::string &path) : path(path),file(nullptr) {}

std::ifstream* InitCSV::read() {
    if(!file) {
        try {
            file = new std::ifstream(path);
            if (!(*file).is_open()) {
                std::cout << "Can't read file" << std::endl;
                return nullptr;
            }
        }
        catch (std::ios_base& e){
            std::cerr << "exception at reading InitFile CSV, check the path please" << '\n';
            exit(1);

        }
    }
    return file;
}

InitCSV::~InitCSV() {
    if(file) {
        (*file).close();
        delete(file);
        file= nullptr;
    }
}

const std::string &InitCSV::getPath() const {
    return path;
}

void InitCSV::setPath(const std::string &path) {
    InitCSV::path = path;
}


