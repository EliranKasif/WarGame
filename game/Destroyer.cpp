//
// Created by eliran on 01/01/18.
//

#include "Destroyer.h"

void Destroyer::Destroy(std::vector<Destroyer*>& vec){
    for(auto& bye:vec){
        if(bye){
            delete(bye);
        }
    }
    vec.clear();
}

Destroyer::~Destroyer() {

}