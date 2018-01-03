//
// Created by eliran on 02/01/18.
//

#include "Game.h"

void Game::read(int argc,char *argv[])throw(decodeException,argumentException,equalityException,numofplayerException,numofSoldiersException){
    try {
        design.readArgv(argc, argv);
    }
    catch(const decodeException& e){
        throw e;
    }
    catch(const argumentException& e){
        throw e;
    }
    catch(const equalityException& e){
        throw e;
    }
    catch(const numofplayerException& e){
        throw e;
    }
    catch (const numofSoldiersException& e){
        throw e;
    }

}

void Game:: initDataStructure(){
    DS.build(design);
}

void Game::GameLogic(){
    std::ofstream streamouts;
    streamouts.open(("Out.txt"));
    streamouts<<"The WarGame by Noy && Eliran"<<std::endl;
    int stop=DS.getData()->getNumofplayers()*DS.getData()->getNumofsoldiers();
    while(Player::steps<stop) {
        for (auto &p:DS.getData()->getPlayers()) {
            p->round(DS.getArena(),streamouts);
        }
    }

    int maxArmy=0;
    int WinnerID=0;
    for(auto& print:DS.getData()->getPlayers()) {
        streamouts<<"Player "<<print->getPlayerId()<<" Number of soldiers: "<<print->getArmy().size()<<std::endl;;
        for(auto& print2:print->getArmy()) {
            streamouts<<*print2.first<<std::endl;
            if(print->getArmy().size()>maxArmy){
                maxArmy=print->getArmy().size();
                WinnerID=print->getPlayerId();
            }
        }
    }
    if(WinnerID==0){
        streamouts<<"The Winner is: there is no winner";
    }
    else{
        streamouts<<"The Winner is: Player "<<WinnerID<<std::endl;
    }
    streamouts<<"The WarGame Finished";
    streamouts.close();
    std::cout<<DS;
}

void Game::GameOver() {
    Destroyer::Destroy(Factory::getByebye());
}



