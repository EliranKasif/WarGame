//
// Created by eliran on 21/12/17.
//

#include "Tree.h"

Tree::Tree(double width, double height) :
        NotCollectibleItems(width, height) {}

Tree::Tree() :
        NotCollectibleItems() {}

void Tree::toString(std::ostream &os) const{
os << "Tree- ";
    NotCollectibleItems::toString(os);
}

Tree::~Tree() {

}
