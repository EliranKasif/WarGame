//
// Created by eliran on 01/01/18.
//

#ifndef WARGAME_DESTROYER_H
#define WARGAME_DESTROYER_H


#include <vector>

class Destroyer {
public:
    virtual ~Destroyer();
static void Destroy(std::vector<Destroyer*>& vec);
};

#endif //WARGAME_DESTROYER_H
