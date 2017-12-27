//
// Created by noysi on 23-Dec-17.
//

#include <sstream>
#include "HumanStrategy.h"

HumanStrategy::HumanStrategy(const int numOfSoldiers, const int height, const int width, FileControler *fileControler)
        : Strategy(numOfSoldiers, height, width), fileControler(fileControler) {}

HumanStrategy::HumanStrategy() {}

void HumanStrategy::implementStrategy(){
    std::ifstream* file=fileControler->read();
    std::list<Point2d> list;
    while(!(*file).eof()) {
        std::string s;
        std::getline(*file, s);
        if (s.compare("Player\r")) {
            split(s,',',list);
            destination.emplace_back(list);
            list.clear();
        }
    }
    if(destination.size() != getNumOfSoldiers()){

    }

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

void HumanStrategy::split(std::string& s,char delim,std::list<Point2d> &list) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        int pos = item.find(' ');
        std::string temp = item.substr(1, pos - 1);
        double x = std::stod(temp);
        temp = item.substr(pos + 1, item.length() - 2);
        double y = std::stod(temp);
        list.emplace_back(x, y);
    }
}

HumanStrategy::~HumanStrategy() {}

