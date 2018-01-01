//
// Created by eliran on 24/12/17.
//

#include "DataStructure.h"
#include "InitCSV.h"


DataStructure::DataStructure(int argc, char *argv[]){
    build(argc,argv);
}


//need to throw exception if no argv.
void DataStructure:: build(int argc, char *argv[]){
    if(argc == 1)
    {
        std::cerr<<"Error, no inputs files from user";
        return;
    }
    std::string pathinitfile (argv[1]);
    --argc;
    FileControler *initfile = new InitCSV(pathinitfile);
    Decoder *buffer = new Decoder(initfile);
    data.setDecoder(buffer);
    std::list<FileControler*> filetoplayers;
    size_t index=2;
    while(index<= argc){
        std::string pathplayesmoves (argv[index]);
        FileControler *playerfile = new InitCSV(pathplayesmoves);
        filetoplayers.emplace_back(playerfile);
        --argc;
        index++;
    }
    auto it= filetoplayers.begin();
    data.Initialze(it);
    arena.setWSize(data.getBattlefieldwidth());
    arena.setHSize(data.getBattlefieldheight());
    arena.build();
    const auto& Players=data.getPlayers();
    std::vector<Player*>::const_iterator itPlayers=Players.begin();
    while(itPlayers!=data.getPlayers().cend()){//loop over Players
        const auto& Soldier=(*itPlayers)->getArmy();
        std::map<Soldiers*,std::list<Point2d>>::const_iterator itSoldiers=Soldier.begin();
        while(itSoldiers!=(*itPlayers)->getArmy().cend()){//loop over Soldiers for each player.
            Soldiers* s2=(*itSoldiers).first;
            size_t x=(size_t)s2->getSoldierLocation().getX();
            size_t y=(size_t)s2->getSoldierLocation().getY();
            arena.addSoldier(x,y,s2);
            ++itSoldiers;
        }
        ++itPlayers;
    }

    const auto& Item=data.getItems();
    auto itItems=Item.begin();
    while(itItems != Item.end()){//loop over Items on map.
        Items* i=(*itItems);
        size_t x=i->getLocation().getX();
        size_t y=i->getLocation().getY();
        arena.addItem(x,y,i);
        ++itItems;
    }

    delete(initfile);
    delete(buffer);
    for(auto& del:filetoplayers){

        delete(del);
    }
    filetoplayers.clear();

    data.clearItems();

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
