//
// Created by eliran on 21/12/17.
//

#ifndef WARGAME_TREE_H
#define WARGAME_TREE_H


#include <ostream>
#include "NotCollectibleItems.h"

class Tree:public NotCollectibleItems {
public:
    Tree(double width, double height);
    Tree();

    virtual ~Tree();

private:
    virtual void toString(std::ostream &os) const override;


};


#endif //WARGAME_TREE_H
