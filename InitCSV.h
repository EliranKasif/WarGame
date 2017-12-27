//
// Created by eliran on 24/12/17.
//

#ifndef WARGAME_INITCSV_H
#define WARGAME_INITCSV_H


#include "FileControler.h"

class InitCSV: public FileControler {
public:
    std::ifstream* read() override;

    InitCSV(const std::string &path);

    virtual ~InitCSV();

    const std::string &getPath() const;

    void setPath(const std::string &path);

private:
    std::string path;
    std::ifstream* file;
};


#endif //WARGAME_INITCSV_H
