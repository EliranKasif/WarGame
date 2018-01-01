//
// Created by eliran on 24/12/17.
//

#include "InitObject.h"


InitObject::InitObject(Decoder *decoder) : decoder(decoder){}
InitObject::InitObject():decoder(nullptr) {}

void InitObject::Initialze(std::list<FileControler*>::iterator& it){
    if(decoder == nullptr)
        return;
    decoder->decode();
    battlefieldwidth=decoder->getBattlefieldwidth();
    battlefieldheight=decoder->getBattlefieldheight();
    numofplayers=decoder->getPlayers();
    numofsoldiers=decoder->getSoldiers();
    InitObject::InitialzePlayers(it);
    InitObject::InitialzeItemsOnMap();

    //decoder->print();
}

void InitObject::InitialzePlayers(std::list<FileControler*>::iterator& it){


    const std::map <std::pair<std::string,int>,std::list<Node>>& map_to_init_players=decoder->getMap_to_init_players();
    auto itMapKeyTypePlayer =map_to_init_players.begin();
    int count=0;
    while(count<numofplayers)
    {
        Player * p=Factory::createPlayer((Object )(*itMapKeyTypePlayer).first.second,numofsoldiers,battlefieldwidth,battlefieldheight,it);
        p->getStrategy()->implementStrategy();
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
            w->setLocation((*itItemsBegin).point);
            items.emplace_back(w);
        }
        else if((*itItemsBegin).itemType==Object::ARMOR){
            Armors * a=Factory::createArmor((*itItemsBegin).type,(*itArmorlevel));
            a->setLocation((*itItemsBegin).point);
            items.emplace_back(a);
            ++itArmorlevel;

        }
        else if((*itItemsBegin).itemType==Object::SOLID){
            NotCollectibleItems * n=Factory::createSolid((*itItemsBegin).type,(*itSolid).first,(*itSolid).second);
            n->setLocation((*itItemsBegin).point);
            items.emplace_back(n);
            ++itSolid;
        }
        ++itItemsBegin;
    }

}

std::ostream &operator<<(std::ostream &os, const InitObject &object) {
    os << "battlefieldwidth: " << object.battlefieldwidth << " battlefieldheight: " << object.battlefieldheight
       << " numofplayers: " << object.numofplayers << " numofsoldiers: " << object.numofsoldiers<<std::endl;
    os<<"Players:\n";
    size_t i=1;
    for(auto & player:object.players){
        os<<"Player ("<<i<<"): "<<*player<<std::endl;
        ++i;
    }
    os<<"Items:\n";
    i=1;
    for(auto & item:object.items){
        os<<"Item ("<<i<<"): "<<*item<<std::endl;
        ++i;
    }
    return os;
}

InitObject::~InitObject() {
    for(auto& player:players){
        if(player!= nullptr){
            delete (player);
            player= nullptr;
        }
    }
    players.clear();
//    for (auto &item:items) {
//        if (item) {
//            delete (item);
//            item = nullptr;
//        }
//    }
    items.clear();

}

int InitObject::getBattlefieldwidth() const {
    return battlefieldwidth;
}

void InitObject::setBattlefieldwidth(int battlefieldwidth) {
    InitObject::battlefieldwidth = battlefieldwidth;
}

int InitObject::getBattlefieldheight() const {
    return battlefieldheight;
}

void InitObject::setBattlefieldheight(int battlefieldheight) {
    InitObject::battlefieldheight = battlefieldheight;
}

int InitObject::getNumofplayers() const {
    return numofplayers;
}

void InitObject::setNumofplayers(int numofplayers) {
    InitObject::numofplayers = numofplayers;
}

int InitObject::getNumofsoldiers() const {
    return numofsoldiers;
}

void InitObject::setNumofsoldiers(int numofsoldiers) {
    InitObject::numofsoldiers = numofsoldiers;
}

Decoder *InitObject::getDecoder() const {
    return decoder;
}

void InitObject::setDecoder(Decoder *decoder) {
    InitObject::decoder = decoder;
}

const std::vector<Player *> &InitObject::getPlayers() const {
    return players;
}

void InitObject::setPlayers(const std::vector<Player *> &players) {
    InitObject::players = players;
}

const std::vector<Items *> &InitObject::getItems() const {
    return items;
}

void InitObject::setItems(const std::vector<Items *> &items) {
    InitObject::items = items;
}



