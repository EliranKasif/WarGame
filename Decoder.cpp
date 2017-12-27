//
// Created by eliran on 24/12/17.
//

#include "Decoder.h"

Decoder::Decoder(FileControler *buffer) : buffer(buffer) {}

void Decoder::decode() {
    std::ifstream* file=buffer->read();
    if(file == nullptr)
        return;
    std::vector<std::string> strs;
    while(!(*file).eof())
    {
        std::string x;
        std::getline((*file),x);
        split(x,',',strs);
    }
    std::list<Object> listobject;
    auto it = strs.begin()+1;
    while(it<strs.end()) {
        std::string s = *it;
        if (!s.compare("battlefieldSize")) {//add if not battlefield so throw exception
            it++;
            std::string s = *it;
            battlefieldwidth = std::stoi(*(it++), 0, 10);
            battlefieldheight = std::stoi(*it, 0, 10);
        } else if (!s.compare("players")) {
            players = std::stoi(*(++it), 0, 10);
        } else if (!s.compare("soldiers")) {
            soldiers = std::stoi(*(++it), 0, 10);
        } else if (!s.compare("p1")) {
            initPlayersEnum(it,soldiers);
        } else if (!s.compare("p2")) {
            initPlayersEnum(it,soldiers);
        } else if (!s.compare("p3")) {
            initPlayersEnum(it,soldiers);
        } else if (!s.compare("p4")) {
            initPlayersEnum(it,soldiers);
        } else if (!s.compare("Objects") || !s.compare("Objects\r")) {
                while (it < strs.end()) {
                    std::string x = *it;
                    if (!(*it).compare("weapon")) {
                        initWeaponsEnum(it,flag::FROMOBJECT);
                        obj2.itemType=Object ::WEAPON;
                        it++;
                        initPointsObj(it,flag::FROMOBJECT);
                        list_init_to_items_on_map.emplace_back(obj2);
                    } else if (!(*it).compare("Armor")) {
                        obj2.itemType=Object ::ARMOR;
                        it++;
                        std::string x = *it.base();
                        if (!((*(it)).compare("BodyArmor"))) {
                            obj2.type=Object ::BODYARMOR;
                            it++;
                            armorlevel.push_back(std::stod(*it));
                            it++;
                            initPointsObj(it,flag::FROMOBJECT);
                            list_init_to_items_on_map.emplace_back(obj2);

                        } else if (!((*(it)).compare("ShieldArmor"))) {
                            obj2.type=Object ::SHIELDARMOR;
                            it++;
                            armorlevel.push_back(std::stod(*it));
                            it++;
                            initPointsObj(it,flag::FROMOBJECT);
                            list_init_to_items_on_map.emplace_back(obj2);

                        }

                    } else if (!(*it).compare("solid")) {
                        it++;
                        if (!((*(it)).compare("Tree"))) {
                            obj2.type=Object ::TREE;
                            obj2.itemType=Object ::SOLID;
                            it++;
                            double x = std::stod(*it);
                            it++;
                            double y = std::stod(*it);
                            it++;
                            solid.emplace_back(x, y);
                            initPointsObj(it,flag::FROMOBJECT);
                            list_init_to_items_on_map.emplace_back(obj2);

                        }

                    }
                    it++;

                }
        }
        it++;
    }
}
template<typename Out>
void Decoder::split(const std::string &s, char delim, Out result) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}

void Decoder::split(const std::string &s, char delim,std::vector<std::string>& elems) {
    split(s, delim, std::back_inserter(elems));
}

void Decoder::initWeaponsEnum(std::vector<std::string>::iterator& it,flag from)
{
    it++;
    std::string x=*it.base();
    if (!((*(it)).compare("M16")) || !((*(it)).compare("M16\r"))) {
        if(from==flag::FROMPLAYER)
            obj.weapon=Object::M16;
        else if(from ==flag::FROMOBJECT)
            obj2.type=Object::M16;
    } else if (!((*(it)).compare("UZI")) || !((*(it)).compare("UZI\r"))) {
        if(from==flag::FROMPLAYER)
            obj.weapon=Object::UZI;
        else if(from ==flag::FROMOBJECT)
            obj2.type=Object::UZI;
    } else if (!((*(it)).compare("Missile")) || !((*(it)).compare("Missile\r"))) {
        if(from==flag::FROMPLAYER)
            obj.weapon=Object::MISSILE;
        else if(from ==flag::FROMOBJECT)
            obj2.type=Object::MISSILE;    }
}
void Decoder::initSoldierEnum(std::vector<std::string>::iterator& it,flag from)
{
    it++;
    std::string x=*it.base();
    if (!((*(it)).compare("normal")) || !((*(it)).compare("normal\r"))) {
        obj.soldier=Object::REGULARSOLDIER;
        it++;
        std::string x=*it.base();
        initPointsObj(it,from);
        initWeaponsEnum(it,from);
    } else if (!((*(it)).compare("paramedic")) || !((*(it)).compare("paramedic\r"))) {
        obj.soldier=Object::HEALERSOLDIER;
        it++;
        std::string x=*it.base();
        obj.weapon=Object ::UNDI;
        initPointsObj(it,from);
    } else if (!((*(it)).compare("sniper")) || !((*(it)).compare("sniper\r"))) {
        obj.soldier=Object::SNIPERSOLDIER;
        it++;
        std::string x=*it.base();
        initPointsObj(it,from);
        initWeaponsEnum(it,from);


    }
}

void Decoder:: initPlayersEnum(std::vector<std::string>::iterator& it, int soldiers){
    std::string numplayer=*it;
    it++;
    std::string x=*it.base();
    if (!((*(it)).compare("human")) || !((*(it)).compare("human\r"))) {
        int counter=0;
        while(counter<soldiers) {
            initSoldierEnum(it,flag::FROMPLAYER);
            nodes.emplace_back(obj);
            counter++;
        }
        std::pair<std::string,int> z (numplayer,(int)Object::HUMAN);
        map_to_init_players.emplace(z,nodes);
        nodes.clear();
    }
    else if (!((*(it)).compare("computer")) || !((*(it)).compare("computer\r")) ) {
        int counter=0;
        while(counter<soldiers) {
            initSoldierEnum(it,flag::FROMPLAYER);
            nodes.emplace_back(obj);
            counter++;
        }
        std::pair<std::string,int> z (numplayer,(int)Object::COMPUTERRANDOM);
        map_to_init_players.emplace(z,nodes);
        nodes.clear();
    }
}

FileControler *Decoder::getBuffer() const {
    return buffer;
}

void Decoder::setBuffer(FileControler *buffer) {
    Decoder::buffer = buffer;
}

void Decoder:: print(){
    for(auto& list:map_to_init_players)
    {
        std::cout<<list.first.first<<" Type: "<<(int)list.first.second<<") "<<std::endl;
        int j=1;
        for(auto& node:list.second){
            std::cout<<j<<") "<<"SoldierType: "<<(int)node.soldier<<" WeaponType: "<<(int)node.weapon<<
                     " Point: "<<node.point<<std::endl;
            j++;

        }
    }
    std::cout<<"Objects: \n";
    int i=1;
    for(auto& objects:list_init_to_items_on_map){
        std::cout<< i<<") " << "Objectype: "<<(int)objects.type << " Point: "<<objects.point<<std::endl;
        i++;
    }
    i=1;
    std::cout<<"Armor level: \n";
    for(auto& armor:armorlevel){
        std::cout<< i<<") "<<armor<<std::endl;
        i++;
    }
    i=1;
    std::cout<<"Solid Size: \n";
    for(auto& soli:solid){
        std::cout<< i<<") ["<<soli.first<<","<<soli.second<<"]"<<std::endl;
        i++;
    }
}


void Decoder:: initPointsObj(std::vector<std::string>::iterator& it,flag from){
    std::string temp=*it;
    int pos=temp.find(' ');
    temp=temp.substr(1,pos-1);
    double x=std::stod(temp);
    temp=*it;
    temp=temp.substr(pos+1,temp.length()-2);
    double y = std::stod(temp);
    if(from==flag::FROMPLAYER) {
        obj.point.setX(x);
        obj.point.setY(y);
    }
    else if(from==flag::FROMOBJECT){
        obj2.point.setX(x);
        obj2.point.setY(y);
    }

}

Decoder::~Decoder() {

}

int Decoder::getBattlefieldwidth() const {
    return battlefieldwidth;
}

int Decoder::getBattlefieldheight() const {
    return battlefieldheight;
}

int Decoder::getPlayers() const {
    return players;
}

int Decoder::getSoldiers() const {
    return soldiers;
}

const std::list<double> &Decoder::getArmorlevel() const {
    return armorlevel;
}

const std::list<std::pair<double, double>> &Decoder::getSolid() const {
    return solid;
}

const std::map<std::pair<std::string, int>, std::list<Node>> &Decoder::getMap_to_init_players() const {
    return map_to_init_players;
}

const std::list<Node2> &Decoder::getList_init_to_items_on_map() const {
    return list_init_to_items_on_map;
}



