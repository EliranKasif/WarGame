//
// Created by eliran on 03/01/18.
//

#include "Reader.h"

Decoder *Reader::getBuffer() const {
    return buffer;
}

const std::list<FileControler *> &Reader::getFiletoplayers() const {
    return filetoplayers;
}
Reader::~Reader() {
    if (buffer) {
        delete (buffer);
    }
    for (auto &del:filetoplayers) {
        if (del) {
            delete (del);
        }
    }
    filetoplayers.clear();
}