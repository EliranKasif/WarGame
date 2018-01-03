//
// Created by eliran on 24/12/17.
//

#ifndef WARGAME_INITCSV_H
#define WARGAME_INITCSV_H


#include "FileControler.h"

class InitCSV: public FileControler {
public:

    /*
     * @brief Constructor
     * @param const std::string &
     */
    InitCSV(const std::string &path);

    /*
     * @brief virtual Destructor
     */
    virtual ~InitCSV();

    /*
     * @brief read the file
     * @return std::ifstream*
     */
    std::ifstream* read() override;

    /*
     * @brief get the path of the file
     * @return const std::string &
     */
    const std::string &getPath() const;

    /*
     * @brief set the path of the file
     * @return const std::string &
     */
    void setPath(const std::string &path);

private:
    std::string path;
    std::ifstream* file;
};


#endif //WARGAME_INITCSV_H
