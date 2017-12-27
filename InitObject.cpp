//
// Created by eliran on 24/12/17.
//

#include "InitObject.h"





/*
std::ostream &operator<<(std::ostream &os, const InitObject &decoder) {
    os << "battlefieldwidth: " << decoder.battlefieldwidth << " battlefieldheight: " << decoder.battlefieldheight
       << " players: " << decoder.players << " soldiers: " << decoder.soldiers<<std::endl<<"Points: "<<std::endl;

    for(auto& point:decoder.objPoints)
    {
        os<<"["<<point.first<<","<<point.second<<"]"<<std::endl;

    }
    os<<std::endl<<"Armors: ";
    auto it2=decoder.armorlevel.begin();
    while(it2 != decoder.armorlevel.end())
    {
        os<<*it2<<", ";
        it2++;
    }
    os<<std::endl<<"Solid size: ";
    for(auto& solid:decoder.solid)
    {
        os<<"["<<solid.first<<","<<solid.second<<"]"<<std::endl;

    }
    os<<std::endl;
    for(auto& map:decoder.mapEnum){
        std::cout<<map.first<<":";
        auto it=map.second.begin();
        while(it!=map.second.end())
        {
            os << (int)*it<<",";
            it++;
        }
        os <<std::endl;
    }
    os<<std::endl;

    return os;
}

*/


InitObject::InitObject(Decoder *decoder) : decoder(decoder) {}

void InitObject::Initialze(){
    if(decoder == nullptr)
        return;
    decoder->decode();
    battlefieldwidth=decoder->getBattlefieldwidth();
    battlefieldheight=decoder->getBattlefieldheight();
    numofplayers=decoder->getPlayers();
    numofsoldiers=decoder->getSoldiers();
   // InitObject::InitialzePlayers();
    //InitObject::InitialzeItemsOnMap();

    decoder->print();
}

void InitObject::InitialzePlayers(){


    const std::map <std::pair<std::string,int>,std::list<Node>>& map_to_init_players=decoder->getMap_to_init_players();
    auto itMapKeyTypePlayer=map_to_init_players.begin();
    int count=0;
    while(count<numofplayers)
    {
        Player * p=Factory::createPlayer((Object )(*itMapKeyTypePlayer).first.second,numofsoldiers,battlefieldwidth,battlefieldheight);
        p->InitArmy((*itMapKeyTypePlayer).second);
        players.emplace_back(p);
        ++itMapKeyTypePlayer;
        ++count;
    }

}

void InitObject::InitialzeItemsOnMap(){
    const std::list<double>& armorlevel=decoder->getArmorlevel();
    const std::list<std::pair<double,double>>& solid=decoder->getSolid();
    const std::list<Node2>& list_init_to_items_on_map=decoder->getList_init_to_items_on_map();
    auto itArmorlevel=armorlevel.begin();
    auto itSolid=solid.begin();
    auto itItemsBegin=list_init_to_items_on_map.begin();
    auto itItemsEnd=list_init_to_items_on_map.end();
    while(itItemsBegin!=itItemsEnd){
        if((*itItemsBegin).itemType==Object::WEAPON){
            Weapons * w=Factory::createWeapon((*itItemsBegin).type);
            items.emplace_back(w);
        }
        else if((*itItemsBegin).itemType==Object::ARMOR){
            Armors * a=Factory::createArmor((*itItemsBegin).type,(*itArmorlevel));
            items.emplace_back(a);
            ++itArmorlevel;

        }
        else if((*itItemsBegin).itemType==Object::SOLID){
            NotCollectibleItems * n=Factory::createSolid((*itItemsBegin).type,(*itSolid).first,(*itSolid).second);
            items.emplace_back(n);
            ++itSolid;
        }
        ++itItemsBegin;
    }

}

