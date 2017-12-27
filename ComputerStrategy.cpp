//
// Created by noysi on 23-Dec-17.
//

#include <random>
#include <iostream>
#include "ComputerStrategy.h"

ComputerStrategy::ComputerStrategy(const int numOfSoldiers, const int height, const int width)
        : Strategy(numOfSoldiers, height, width) {}

ComputerStrategy::ComputerStrategy() {}

ComputerStrategy::~ComputerStrategy() {}

void ComputerStrategy::implementStrategy(){
    int n=getNumOfSoldiers();
    int ySize=getHeight();
    int xSize=getWidth();

    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    std::uniform_int_distribution<int> uni(0,5); // guaranteed unbiased
    //auto random_integer = uni(rng);
    std::list<Point2d> list;
    for (int i = 0; i <n; ++i) {
        int steps  = uni(rng);
        for (int j = 0; j < steps; ++j) {
            std::uniform_int_distribution<int> xrand(0,xSize); // guaranteed unbiased
            std::uniform_int_distribution<int> yrand(0,ySize); // guaranteed unbiased
            int x =  xrand(rng);
            int y =  yrand(rng);
            Point2d p(x, y);
            list.emplace_back(p);
        }
            destination.emplace_back(list);
        list.clear();

    }
//    for(auto& t:destination){
//        auto p=t.begin();
//        for (auto& p: t) {
//            std::cout <<(Point2d)p<<",";
//        }
//        std::cout<<std::endl;
//
//    }

}



