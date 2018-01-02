//
// Created by eliran on 24/12/17.
//

#include "DataStructure.h"
#include "InitCSV.h"
#include "ReadFromuser.h"


DataStructure::DataStructure(int argc, char *argv[]) throw(decodeException,argumentException,equalityException,numofplayerException,numofSoldiersException){
    try {
        build(argc, argv);
    }
    catch (const decodeException& e){
        throw e;
    }
    catch (const argumentException& e){
        throw e;
    }
    catch(const equalityException& e){
        throw e;
    }
    catch(const numofplayerException& e){
        throw e;
    }
    catch(const numofSoldiersException& e){
        throw e;
    }
}


//need to throw exception if no argv.
void DataStructure:: build(int argc, char *argv[]) throw(decodeException,argumentException,equalityException,numofplayerException,numofSoldiersException){
    ReadFromuser design;
    try {
        design.build(argc,argv);
        data.setDecoder(design.getBuffer());
        auto list=design.getFiletoplayers();
        auto it=list.begin();
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


    auto& Item=data.getItems();
    //auto ktovet=&data.getItems();
   // auto ktovet2=&Item;
    auto itItems=Item.begin();
    while(itItems != Item.end()){//loop over Items on map.
        Items& i=(**itItems);
       // auto ktoveti=&i;
        size_t x=i.getLocation().getX();
        size_t y=i.getLocation().getY();
        arena.addItem(x,y,i);
        ++itItems;
    }
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
