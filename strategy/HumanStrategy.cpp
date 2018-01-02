//
// Created by noysi on 23-Dec-17.
//

#include <sstream>
#include "HumanStrategy.h"

HumanStrategy::HumanStrategy(FileControler* fileControler,const int _numOfSoldiers)
        :fileControler(fileControler),numOfSoldiers(_numOfSoldiers){}

void HumanStrategy::implementStrategy() throw(inithumanException,equalityException){
    if(fileControler!= nullptr) {
        std::ifstream *file = fileControler->read();
        std::list<Point2d> list;
        while (!(*file).eof()) {
            std::string s;
            std::getline(*file, s);
            if (s.compare("Player\r")) {
                try {
                    split(s, ',', list);
                    destination.emplace_back(list);
                    list.clear();
                }
                catch(const inithumanException& e){
                    throw e;
                }
            }
        }
        int size=destination.size();
        if(destination.size()!=numOfSoldiers){
            throw equalityException(numOfSoldiers);
        }
    }
    else return;

/*
    std::cout << std::endl;
    std::cout << std::endl;
    int i=0;
    for(auto& t:points) {
        std::cout<<i;
        auto p = t.begin();
        while(p!=t.end()) {
            std::cout << *p << ",";
            ++p;
        }
        i++;
        std::cout << std::endl;
    }
*/

}

void HumanStrategy::split(std::string& s,char delim,std::list<Point2d> &list) throw(inithumanException) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        int pos = item.find(' ');
        std::string temp = item.substr(1, pos - 1);
        try{
        double x = std::stod(temp);
        temp = item.substr(pos + 1, item.length() - 2);
        double y = std::stod(temp);
            list.emplace_back(x, y);

        }
        catch (std::exception e){
            throw inithumanException();
        }
    }
}

HumanStrategy::~HumanStrategy() {}

void HumanStrategy::setFileControler(FileControler *fileControler)
{
    HumanStrategy::fileControler = fileControler;
}
void HumanStrategy:: toString(std::ostream &os)const{
    os<<"Human Strategy, ";
}
