//
// Created by eliran on 02/01/18.
//

#include "ReadFromuser.h"

void ReadFromuser::build(int argc, char **argv) throw (decodeException,argumentException,numofplayerException,numofSoldiersException){
    if(argc == 1)
    {
        throw argumentException();
    }
    std::string pathinitfile (argv[1]);
    --argc;
    FileControler *initfile = new InitCSV(pathinitfile);
    buffer = new Decoder(initfile);
    try {
        buffer->decode();
    }
    catch (const decodeException& e){
        throw e;
    }
    catch (const argumentException& e){
        throw e;
    }
    catch (const numofplayerException& e){
        throw e;
    }
    catch(const numofSoldiersException& e){
        throw e;
    }
    int numofhuman=0;

    //data.setDecoder(buffer);
    size_t index=2;
    while(index<= argc){
        std::string pathplayesmoves (argv[index]);
        FileControler *playerfile = new InitCSV(pathplayesmoves);
        filetoplayers.emplace_back(playerfile);
        --argc;
        index++;
    }
    for(auto& map:buffer->getMap_to_init_players()){
        if(map.first.second==Object ::HUMAN){
            ++numofhuman;
        }
    }
    if(numofhuman!=filetoplayers.size()){
        throw argumentException();
    }
    delete(initfile);
}

const std::list<FileControler *> &ReadFromuser::getFiletoplayers() const {
    return filetoplayers;
}

ReadFromuser::~ReadFromuser() {
    if(buffer){
        delete(buffer);
    }
    for(auto& del:filetoplayers){
        if(del) {
            delete (del);
        }
    }
    filetoplayers.clear();

}

Decoder *ReadFromuser::getBuffer() const {
    return buffer;
}
