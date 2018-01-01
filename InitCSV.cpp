//
// Created by eliran on 24/12/17.
//

#include <iostream>
#include "InitCSV.h"

InitCSV::InitCSV(const std::string &path) : path(path),file(nullptr) {}

std::ifstream* InitCSV::read() {
    if(!file) {
        file=new std::ifstream(path);
        if (!(*file).is_open()) {
            std::cout << "Can't read file" << std::endl;
            return nullptr;
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


