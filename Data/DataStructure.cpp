//
// Created by eliran on 24/12/17.
//

#include "DataStructure.h"


void DataStructure:: build(const Reader& design) {
        data.setDecoder(design.getBuffer());
        auto list=design.getFiletoplayers();
        auto it=list.begin();
        data.Initialze(it);
        BuildArena build;
        build.buildArena(arena,data);
}

std::ostream &operator<<(std::ostream &os, const DataStructure &structure) {
    os /*<< "data: " << structure.data*/ << std::endl<<" arena: " << structure.arena;
    return os;
}

InitObject* DataStructure::getData() {
    return &data;
}

Environment& DataStructure::getArena() {
    return arena;
}
