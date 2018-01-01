//
// Created by eliran on 24/12/17.
//

#ifndef WARGAME_FILECONTROLER_H
#define WARGAME_FILECONTROLER_H


#include <fstream>

class FileControler {
public:
    /*
     * @brief default Constructor
     */
    FileControler();

    /*
     * @brief virtual Destructor
     */
    virtual ~FileControler();

    /*
     * @brief pure virtual func to read specific file type
     * return std::ifstream*
     */
    virtual std::ifstream* read()=0;
};


#endif //WARGAME_FILECONTROLER_H
